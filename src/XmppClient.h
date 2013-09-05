#ifndef __XMPPCLIENT_H__
#define __XMPPCLIENT_H__

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include <strophe.h>
#include <String.h>
#include <malloc.h>
#include "Roster.h"
#include "XEventQueue.h"

#define EVENT_LOOP_PERIOD 		3

class XmppClient {
private:
	xmpp_ctx_t* context_;
	xmpp_conn_t* connection_;
	
	String login_;
	String jid_;
	String password_;
	int status_;
	
	String serverDomain_;
	String serverAddress_;
	
	static Roster roster_;
	
	static int xmppHandleReply(xmpp_conn_t* const, xmpp_stanza_t* const,
						 void* const);
	static void xmppConnectionHandler(xmpp_conn_t * const, const xmpp_conn_event_t,
								 const int, xmpp_stream_error_t * const, void * const);
	static int xmppMessageHandler(xmpp_conn_t * const, xmpp_stanza_t * const, void * const);
	static int xmppPresenceHandler(xmpp_conn_t * const, xmpp_stanza_t * const, void * const);
	static int xmppTimerHandler(xmpp_conn_t * const conn, void * const userdata);

public:
	static XEventQueue eventQueue_;

	XmppClient(const char*, const char*, const char*, const char*);
//TODO	XmppClient(XmppClient*);
	XmppClient();
	~XmppClient();
	
	int authenticateAtXmppServer();
	int connectXmppServer();
	int initializeXmppVariables();
	int initiateConnectionToXmppServer();
	int sendMessage(const char*, const char*);
	int sendStatus();
	int startEventLoop();
	int startEventLoopOnce();
	int receiveRoster();
	
	int setJid(const char*);
	int setLogin(const char*);
	int	setPassword(const char*);
	int	setStatus(int);
	int setServerDomain(const char*);
	int setServerAddress(const char*);
	
	const char *getJid() const;
	const char *getLogin() const;
	const char *getPassword() const;
	const char *getServerDomain() const;
	int getStatus() const;

	int isJidCorrect(const char*);
	int isLoginCorrect(const char*);
	int isDomainCorrect(const char*);
	int isPasswordCorrect(const char*);
	
	const Roster *getRoster() const;
	
	int doForAllRosterElements(void (*function)(String *, userInfo *, void *), void *);
};

#endif