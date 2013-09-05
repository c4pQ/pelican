#include "ClientNodesVector.h"

ClientNode::ClientNode(const char *login, const char *password, const char *domain,
						const char *server, const char *proxy, const char *bosh,
						unsigned short port, unsigned short encryption, int isActive)
{
	login_		= login;
	password_ 	= password;
	domain_		= domain;
	server_		= server;
	proxy_		= proxy;
	bosh_		= bosh;

	encryption_ = encryption;
	port_ 		= port;
	
	isActive_ 	= isActive;
	
	jid_ = login_ + String("@") + domain_;
}

ClientNode::ClientNode(ClientNode &source)
{
	login_ 		= source.getLogin();
	password_ 	= source.getPassword();
	domain_ 	= source.getDomain();
	server_ 	= source.getServer();
	proxy_ 		= source.getProxy();
	bosh_ 		= source.getBosh();
	jid_ 		= source.getJid();
	
	encryption_ = source.getEncryptionType();
	port_		= source.getPort();
	
	isActive_	= source.isActive();
}

ClientNode::ClientNode()
{
	login_		= "";
	password_ 	= "";
	domain_		= "";
	server_		= "";
	proxy_		= "";
	bosh_		= "";
	jid_		= "";

	encryption_ = ENCRYPTION_USE_ALWAYS;
	port_ 		= 0;
	
	isActive_	= 0;
}

ClientNode::~ClientNode()
{
}

String ClientNode::getLogin() const
{
	return login_;
}

String ClientNode::getPassword() const
{
	return password_;
}

String ClientNode::getDomain() const
{
	return domain_;
}

String ClientNode::getServer() const
{
	return server_;
}

String ClientNode::getProxy() const
{
	return proxy_;
}

String ClientNode::getBosh() const
{
	return bosh_;
}

String ClientNode::getJid() const
{
	return jid_;
}

unsigned short ClientNode::getEncryptionType() const
{
	return encryption_;
}

unsigned short ClientNode::getPort() const
{
	return port_;
}

int ClientNode::isActive() const
{
	return isActive_;
}
	
int ClientNode::setLogin(const char *login)
{
	login_ = login;
	jid_ = login_ + String("@") + domain_;
	
	return 0;
}

int ClientNode::setPassword(const char *password)
{
	password_ = password;
	return 0;
}

int ClientNode::setDomain(const char *domain)
{
	domain_ = domain;
	jid_ = login_ + String("@") + domain_;

	return 0;
}

int ClientNode::setServer(const char *server)
{
	server_ = server;
	return 0;
}

int ClientNode::setProxy(const char *proxy)
{
	proxy_ = proxy;
	return 0;
}

int ClientNode::setBosh(const char *bosh)
{
	bosh_ = bosh;
	return 0;
}

int ClientNode::setJid(const char *jid)
{
	jid_ = jid;
	return 0;
}

int ClientNode::setEncryptionType(unsigned short encryption)
{
	encryption_ = encryption;
	return 0;
}

int ClientNode::setPort(unsigned short port)
{
	port_ = port;
	return 0;
}

int ClientNode::setActive()
{
	isActive_ = 1;
	return 0;
}

int ClientNode::setInactive()
{
	isActive_ = 0;
	return 0;
}
	
ClientNode & ClientNode::operator =(const ClientNode &source)
{
	login_ 		= source.getLogin();
	password_ 	= source.getPassword();
	domain_ 	= source.getDomain();
	server_ 	= source.getServer();
	proxy_ 		= source.getProxy();
	bosh_ 		= source.getBosh();
	jid_ 		= source.getJid();
	
	encryption_ = source.getEncryptionType();
	port_		= source.getPort();

	isActive_	= source.isActive();
	
	return *this;
}

int ClientNode::operator ==(const ClientNode &another) const
{
	return (jid_ == another.getJid());
}

int ClientNode::operator <(const ClientNode &another) const
{
	return (jid_ < another.getJid());
}

ClientNodesVector::ClientNodesVector()
{
	selectedInListItem_ = 0;
	iterator_ = 0;
}

ClientNodesVector::~ClientNodesVector()
{
}

int ClientNodesVector::openClientNodesFile()
{
/*	String photonFolder 	= "";
	String clientNodesFile 	= "";
	char *homeFolder 		= NULL;
	struct stat s			= {0};
	
	homeFolder = getenv("HOME");
	if(homeFolder)
	{
		photonFolder = homeFolder;
		photonFolder += "/.photon/pelican";
	}
	
	if(stat((const char *)photonFolder, &s))
		mkdir(photonFolder, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	
	clientNodesFile = photonFolder + "/pelican.cfg";
	// CLIENTNODES_FILE
	infoFile_.open((const char *)clientNodesFile, ios::in | ios::out, filebuf::openprot);
*/	
	return 0;
}
	
int ClientNodesVector::insertIntoList(ClientNode *node)
{
	nodesVector_.insert(node);
	
	return 0;
}
	
int ClientNodesVector::changeNode(const char*, const char*, const char*, int,
								int, const char*, const char*, const char*, int)
{
	return 0;
}

int ClientNodesVector::init()
{
	fillListFromFile();

	return 0;
}

int ClientNodesVector::fillListFromFile()
{
	String bufferString;
	ClientNode *bufferNode = NULL;
	
	while(1)
	{
		bufferString = readLineFromFile();
		if(bufferString == "")
			break;
		bufferNode = parseLine(bufferString);
		if(bufferNode->isActive())
			activeAccount_ = bufferNode;
		insertIntoList(bufferNode);
	}
	
	return 0;
}

String ClientNodesVector::readLineFromFile()
{
//TODO to redo better to say; strange code here
	char temp[MAX_STR] = {0};

	infoFile_.getline((char*)&temp, MAX_STR, '\n');

	return temp;
}

ClientNode *ClientNodesVector::parseLine(String income)
{
	char login[MAX_ELEMENT], password[MAX_ELEMENT],
			domain[MAX_ELEMENT], server[MAX_ELEMENT],
			proxy[MAX_ELEMENT], bosh[MAX_ELEMENT];
	unsigned short encryption, port;
	int isActive = 0;
	
	sscanf(income, "%d %s %s %s %s %s %s %d %d", &isActive, login, password,
												domain, server,
												proxy, bosh,
												&encryption, &port);
	
	if(!strcmp(proxy, "NULL"))
		memset(proxy, 0, MAX_ELEMENT);

	if(!strcmp(bosh, "NULL"))
		memset(bosh, 0, MAX_ELEMENT);
	
	return new ClientNode(login, password, domain, server,
					 		proxy, bosh, port, encryption, isActive);
}

String ClientNodesVector::compoundLine(ClientNode *cn)
{
	String line;
	char buffer[MAX_STR] = {'\0'};
	
	_bprintf(buffer, MAX_STR, "%d %s %s %s %s %s %s %d %d", cn->isActive(), (const char *)cn->getLogin(), (const char *)cn->getPassword(),
												(const char *)cn->getDomain(), (const char *)cn->getServer(),
												(const char *)cn->getProxy(), (const char *)cn->getBosh(),
												cn->getEncryptionType(), cn->getPort());
	line = buffer;
	
	return line;
}

int ClientNodesVector::resetIterator()
{
	iterator_ = 0;
	return 0;
}

ClientNode *ClientNodesVector::getNode()
{
	if(iterator_ < nodesVector_.entries())
		return nodesVector_[iterator_++];
	else
		return NULL;
}

ClientNode *ClientNodesVector::getSelectedNode()
{
	return nodesVector_[selectedInListItem_];
}

int ClientNodesVector::getSelectedItemNumber() const
{
	return selectedInListItem_;
}

int ClientNodesVector::setSelectedItemNumber(int number)
{
	selectedInListItem_ = number;
	return 0;
}

int ClientNodesVector::deleteNode(int position)
{
	nodesVector_.removeAt(position);
	return 0;
}

ClientNode *ClientNodesVector::getEditingNode() const
{
	return editingAccount_;
}

ClientNode *ClientNodesVector::getActiveNode() const
{
	return activeAccount_;
}

int ClientNodesVector::setSelectedNodeEditingNode()
{
	editingAccount_ = nodesVector_[selectedInListItem_];
	return 0;
}

int ClientNodesVector::makeSelectedNodeActive()
{
	activeAccount_->setInactive();
	activeAccount_ = nodesVector_[selectedInListItem_];
	activeAccount_->setActive();
	
	return 0;
}	

int ClientNodesVector::writeListToFile()
{
	int n = nodesVector_.entries();
	for(int i = 0; i < n; i++)
		infoFile_ << compoundLine(nodesVector_[i]) << endl;
		
	return 0;
}
