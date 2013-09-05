#include "XmppClient.h"

Roster XmppClient::roster_;
XEventQueue XmppClient::eventQueue_;

XmppClient::XmppClient(const char* login, const char* password, const char* domain, const char* address)
{
	context_    = NULL;
	connection_ = NULL;
	
	login_	  = login;
	password_ = password;
	status_   = STATUS_OFFLINE;
	
	serverDomain_  = domain;
	serverAddress_ = address;

	jid_ = login_ + "@" + serverDomain_;

    xmpp_initialize();
}

XmppClient::XmppClient()
{
	context_	   = NULL;
	connection_ = NULL;
	
	login_	 = "";
	password_ = "";
	status_ = STATUS_OFFLINE;
	
	serverDomain_  = "";
	serverAddress_ = "";

	jid_ = "";
	
    xmpp_initialize();
}

XmppClient::~XmppClient()
{
	if(connection_)
	    xmpp_conn_release(connection_);
	if(context_)
	    xmpp_ctx_free(context_);
	
    xmpp_shutdown();
}

static int XmppClient::xmppHandleReply(xmpp_conn_t * const /*conn*/,
			 xmpp_stanza_t * const stanza,
			 void * const /*userdata*/)
{
    xmpp_stanza_t *query, *item;
    char *type;//, *name;

    type = xmpp_stanza_get_type(stanza);
    if (strcmp(type, "error") == 0)
		fprintf(stderr, "ERROR: query failed\n");
    else
	{
		query = xmpp_stanza_get_child_by_name(stanza, "query");

		for (item = xmpp_stanza_get_children(query); item; 
			 item = xmpp_stanza_get_next(item))
				roster_.insertIfNo(xmpp_stanza_get_attribute(item, "jid"),
						  xmpp_stanza_get_attribute(item, "name"));
    }

    return 0;	
}

static int XmppClient::xmppPresenceHandler(xmpp_conn_t * const /*conn*/,
			 xmpp_stanza_t * const stanza, void * const /*userdata*/)
{
    char *jid = strdup(xmpp_stanza_get_attribute(stanza, "from"));
	char *show = NULL;
	char *type = NULL;

	userInfo *ui = roster_.getElement(strtok(jid, "/"));

    type = xmpp_stanza_get_type(stanza);
	if(type)
		if(!strcmp(type, "unavailable"))
			show = "off";
	if(xmpp_stanza_get_child_by_name(stanza, "show"))
		show = xmpp_stanza_get_text(xmpp_stanza_get_child_by_name(stanza, "show"));

	ui->setAvailability(show);
//TODO
	eventQueue_.putEvent(new XEvent(/*eventType[GOT_PRESENCE]*/2, NULL, NULL));
	
    return 1;
}

static int XmppClient::xmppMessageHandler(xmpp_conn_t * const /*conn*/,
			 xmpp_stanza_t * const stanza, void * const userdata)
{
	const char *intext;
	xmpp_ctx_t *ctx = (xmpp_ctx_t*)userdata;
	
	if(!xmpp_stanza_get_child_by_name(stanza, "body")) return 1;
	if(!strcmp(xmpp_stanza_get_attribute(stanza, "type"), "error")) return 1;
	
	intext = xmpp_stanza_get_text(xmpp_stanza_get_child_by_name(stanza, "body"));
	
	printf("Incoming message from %s: %s\n", xmpp_stanza_get_attribute(stanza, "from"), intext);
//TODO
	char *jidFrom = strdup(xmpp_stanza_get_attribute(stanza, "from"));
	eventQueue_.putEvent(new XEvent(/*eventType[GOT_MESSAGE]*/1, strtok(jidFrom, "/"), intext));
	
	return 1;
}

static void XmppClient::xmppConnectionHandler(xmpp_conn_t * const conn, const xmpp_conn_event_t status, 
		  				const int /*error*/, xmpp_stream_error_t * const /*stream_error*/,
		  				void * const userdata)
{
    xmpp_ctx_t *ctx = (xmpp_ctx_t *)userdata;
    xmpp_stanza_t *iq, *query, *pres;
	
    if (status == XMPP_CONN_CONNECT)
	{
		// create iq stanza for request 
		iq = xmpp_stanza_new(ctx);
		xmpp_stanza_set_name(iq, "iq");
		xmpp_stanza_set_type(iq, "get");
		xmpp_stanza_set_id(iq, "roster1");

		query = xmpp_stanza_new(ctx);
		xmpp_stanza_set_name(query, "query");
		xmpp_stanza_set_ns(query, XMPP_NS_ROSTER);

		xmpp_stanza_add_child(iq, query);

		// we can release the stanza since it belongs to iq now 
		xmpp_stanza_release(query);
		// set up reply handler 
		xmpp_id_handler_add(conn, xmppHandleReply, "roster1", ctx);
		xmpp_send(conn, iq);
		xmpp_stanza_release(iq);

		xmpp_handler_add(conn, xmppMessageHandler, NULL, "message", NULL, ctx);
		xmpp_handler_add(conn, xmppPresenceHandler, NULL, "presence", NULL, ctx);
	
		pres = xmpp_stanza_new(ctx);
		xmpp_stanza_set_name(pres, "presence");
		xmpp_send(conn, pres);
		xmpp_stanza_release(pres);

		xmpp_timed_handler_add(conn, xmppTimerHandler, 10000, ctx);
    }
	else
	{
		fprintf(stderr, "DEBUG: disconnected\n");
		xmpp_stop(ctx);
    }
}

static int XmppClient::xmppTimerHandler(xmpp_conn_t * const conn, void * const userdata)
{
	printf("Timer\n");
	//TODO тут было бы неплохо слать /presence со статусом и всем остальным	
	return 1;
}
	
int XmppClient::initializeXmppVariables()
{
    // create a context
    context_ = xmpp_ctx_new(NULL, NULL);

    // create a connection
    connection_ = xmpp_conn_new(context_);

	return 0;
}

int XmppClient::authenticateAtXmppServer()
{
    xmpp_conn_set_jid(connection_, (const char*)jid_);
    xmpp_conn_set_pass(connection_, (const char*)password_);

	return 0;
}

int XmppClient::initiateConnectionToXmppServer()
{
    // initiate connection
    xmpp_connect_client(connection_, serverAddress_, 0, xmppConnectionHandler, context_);
//	xmpp_timed_handler_add(connection_, xmppTimerHandler, 2, NULL);
	return 0;
}

int XmppClient::startEventLoop()
{
    // start the event loop
//    xmpp_run(context_);
// TODO Set some other condition here, because server can be down,
// so we'll never get to the widget
	while(!roster_.getEntriesN())
	    xmpp_run_once(context_, 1);

	status_ = STATUS_AVAILABLE;
	
	return 0;
}

int XmppClient::startEventLoopOnce()
{
    xmpp_run_once(context_, EVENT_LOOP_PERIOD);

	return 0;
}


int XmppClient::connectXmppServer()
{
	initializeXmppVariables();
	authenticateAtXmppServer();
	initiateConnectionToXmppServer();

	return 0;
}
	
int XmppClient::receiveRoster()
{
	startEventLoop();
		
	return 0;
}
	
int XmppClient::setJid(const char *jid)
{
	if(isJidCorrect(jid))
		jid_ = jid;
	
	return 0;
}

int XmppClient::setLogin(const char *login)
{
	if(isLoginCorrect(login))
		login_ = login;
	
	jid_ = login_ + "@" + serverDomain_;
	
	return 0;
}

int	XmppClient::setPassword(const char *password)
{
	if(isPasswordCorrect(password))
		password_ = password;
	
	return 0;
}

int XmppClient::setStatus(int status)
{
	status_ = status;
	return 0;
}

int XmppClient::setServerDomain(const char *domain)
{
	if(isDomainCorrect(domain))
		serverDomain_ = domain;
		
	jid_ = login_ + "@" + serverDomain_;
	
	return 0;
}

int XmppClient::setServerAddress(const char *address)
{
	serverAddress_ = address;
		
	return 0;
}
	
const char * XmppClient::getJid() const
{
	return jid_;
}

const char * XmppClient::getPassword() const
{
	return password_;
}

int XmppClient::getStatus() const
{
	return status_;
}

const char * XmppClient::getServerDomain() const
{
	return serverDomain_;
}

int XmppClient::isDomainCorrect(const char* domain)
{
	return (domain)?1:0;
}

int XmppClient::isPasswordCorrect(const char* password)
{
	return (password)?1:0;
}

int XmppClient::isJidCorrect(const char* jid)
{
	return (jid)?1:0;
}

int XmppClient::isLoginCorrect(const char* login)
{
	return (login)?1:0;
}

int XmppClient::sendMessage(const char* jid, const char* message)
{
	if(!jid || !message)
		return 1;
	
	xmpp_stanza_t *reply, *body, *text;

	reply = xmpp_stanza_new(context_);
	xmpp_stanza_set_name(reply, "message");
	xmpp_stanza_set_type(reply, "chat");
	xmpp_stanza_set_attribute(reply, "to", jid);
	body = xmpp_stanza_new(context_);
	xmpp_stanza_set_name(body, "body");
	
	text = xmpp_stanza_new(context_);
	xmpp_stanza_set_text(text, message);
	xmpp_stanza_add_child(body, text);
	xmpp_stanza_add_child(reply, body);
	
	xmpp_send(connection_, reply);
	xmpp_stanza_release(reply);
	
	return 0;
}

int XmppClient::doForAllRosterElements(void (*function)(String *, userInfo *, void *), void *data)
{
	return roster_.doForAll(function, data);
}

int XmppClient::sendStatus()
{
	xmpp_stanza_t *pres, *show, *text;
	char *status = NULL;

	pres = xmpp_stanza_new(context_);
	xmpp_stanza_set_name(pres, "presence");
	
	switch(status_)
	{
		case(STATUS_AVAILABLE):
			status = "available";
		break;
		
		case(STATUS_AWAY):
			status = "away";
		break;

		case(STATUS_BUSY):
			status = "dnd";
		break;
		
		case(STATUS_OFFLINE):
			xmpp_stanza_set_type(pres, "unavailable");
		break;
		
		default:
			return 0;
	}
	
	if(status)
	{
		text = xmpp_stanza_new(context_);
		show = xmpp_stanza_new(context_);
		xmpp_stanza_set_name(show, "show");
		xmpp_stanza_set_text(text, status);
		xmpp_stanza_add_child(show, text);
	
		xmpp_stanza_add_child(pres, show);
	}
	xmpp_send(connection_, pres);
	xmpp_stanza_release(pres);
	
	return 0;
}

const Roster *XmppClient::getRoster() const
{
	return &roster_;
}
