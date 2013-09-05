#ifndef __CLIENTLIST_H__
#define __CLIENTLIST_H__

#include <String.h>
#include <wcvector.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#define CLIENTNODES_FILE		"/home/root/.photon/pelican.cfg"
#define MAX_STR					200
#define MAX_ELEMENT				30

#define ENCRYPTION_USE_ALWAYS		1
#define ENCRYPTION_USE_IFPOSSIBLE	2
#define ENCRYPTION_USE_OLDSSL		3

class ClientNode
{
	String login_;
	String password_;
	String domain_;
	String server_;
	String proxy_;
	String bosh_;
	String jid_;
	
	unsigned short encryption_;
	unsigned short port_;
	
	int isActive_;
		
public:
	String getLogin() const;
	String getPassword() const;
	String getDomain() const;
	String getServer() const;
	String getProxy() const;
	String getBosh() const;
	String getJid() const;
	unsigned short getEncryptionType() const;
	unsigned short getPort() const;
	int isActive() const;
	
	int setLogin(const char*);
	int setPassword(const char*);
	int setDomain(const char*);
	int setServer(const char*);
	int setProxy(const char*);
	int setBosh(const char*);
	int setJid(const char*);
	int setEncryptionType(unsigned short);
	int setPort(unsigned short);
	int setActive();
	int setInactive();
	
	ClientNode(const char*, const char*, const char*, const char*, 
				const char*, const char*, unsigned short, unsigned short, int);
	ClientNode(ClientNode&);
	ClientNode();
	~ClientNode();
	
	ClientNode & operator =(const ClientNode &);
	int operator ==(const ClientNode &) const;
	int operator <(const ClientNode &) const;
};

class ClientNodesVector
{
	WCPtrOrderedVector<ClientNode> nodesVector_;
 	
	ClientNode *activeAccount_; //здесь должен быть индекс TODO
	ClientNode *editingAccount_;
	fstream infoFile_;
	
	int selectedInListItem_;
	int iterator_;
	
public:
	ClientNodesVector();
	~ClientNodesVector();
	
	int 		changeNode(const char*, const char*, const char*, int,
							int, const char*, const char*, const char*, int);
	String 		compoundLine(ClientNode *);
	int 		deleteNode(int);
	int 		fillListFromFile();
	ClientNode *getActiveNode() const;
	ClientNode *getEditingNode() const;
	ClientNode *getNode();
	ClientNode *getSelectedNode();
	int 		getSelectedItemNumber() const;
	int 		init();
	int 		insertIntoList(ClientNode *);
	int 		insertIntoList(const char *, const char *, const char *, int,
								int, const char *, const char *, const char *, int);
	int 		makeSelectedNodeActive();
	int 		openClientNodesFile();
	ClientNode *parseLine(String);
	String 		readLineFromFile();
	int 		resetIterator();
	int 		setSelectedItemNumber(int);
	int 		setSelectedNodeEditingNode();
	int			writeListToFile();
};

#endif