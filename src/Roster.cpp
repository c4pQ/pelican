#include "Roster.h"

userInfo::userInfo()
{
	name_ = "";
	status_ = "";
	availability_ = STATUS_OFFLINE;
}

userInfo::userInfo(const char *name, const char *status, int availability)
{
	name_ = name;
	status_ = status;
	availability_ = availability;
}

userInfo::~userInfo()
{
}
	
const char *userInfo::getName() const
{
	return (const char *)name_;
}

const char *userInfo::getSatus() const
{
	return (const char *)status_;
}

int userInfo::getAvailability() const
{
	return availability_;
}

int userInfo::setName(const char *name)
{
	name_ = name;
	return 0;
}

int userInfo::setStatus(const char *status)
{
	status_ = status;
	return 0;
}

int userInfo::setAvailability(int availability)
{
	availability_ = availability;
	return 0;
}

int userInfo::setAvailability(const char* availability)
{
	if(availability)
	{
		if(!strcmp("chat", availability))
			availability_ = STATUS_AVAILABLE;
		else
		if(!strcmp("away", availability))
			availability_ = STATUS_AWAY;
		else
		if(!strcmp("dnd", availability))
			availability_ = STATUS_BUSY;
		else
		if(!strcmp("xa", availability)) //know nothing about this status
			availability_ = STATUS_OFFLINE;
		else
		if(!strcmp("off", availability))
			availability_ = STATUS_OFFLINE;
		else
			availability_ = STATUS_UNKNOWN;
	}
	else
		availability_ = STATUS_AVAILABLE;
			
	return 0;
}
	
Roster::Roster()
{
	wasRefreshed = 0;
}

Roster::~Roster()
{
}

int Roster::insertIfNo(const char* jid, 
						const char* name)
{
	String *jidS = new String(jid);
	
	roster_.insert(jidS, new userInfo((name)?name:jid, NULL, STATUS_OFFLINE));

	return 0;
}

int Roster::changeUserAvailability(const char *jid, int availability)
{
	String jidS = jid;
	userInfo *ui = roster_.find(&jidS);
	ui->setAvailability(availability);
	
	return 0;
}

int Roster::changeUserStatus(const char *jid, const char *status)
{
	String jidS = jid;
	userInfo *ui = roster_.find(&jidS);
	ui->setStatus(status);

	return 0;
}

userInfo* Roster::getElement(const char *jid) const
{
	String jidS = jid;
	return roster_.find(&jidS);
}

int Roster::getEntriesN()
{
	return roster_.entries();
}

int Roster::doForAll(void (*function)(String *, userInfo *, void *), void *data)
{
	roster_.forAll(function, data);
	return 0;
}
