#include <wcskip.h>
#include <String.h>
#include <nls.h>

#ifndef __ROSTER_H__
#define __ROSTER_H__

#define STATUS_AVAILABLE 	0
#define STATUS_AWAY			1
#define STATUS_BUSY			2
#define STATUS_OFFLINE		3
#define STATUS_UNKNOWN		4

#define STATUS_N			5
#define FIRST_22_ICON 		STATUS_N
#define FIRST_32_ICON 		STATUS_N + 4
#define SIZE_22				22
#define SIZE_32				32


class userInfo {
private:
	String name_;
	String status_;
	int availability_;
	
public:
	userInfo();
	userInfo(const char *, const char *, int);
	~userInfo();
	
	const char *getName() const;
	const char *getSatus() const;
	int getAvailability() const;

	int setName(const char *);
	int setStatus(const char *);
	int setAvailability(int);
	int setAvailability(const char*);
};

class Roster {
private:
	int wasRefreshed;
	WCPtrSkipListDict<String, userInfo> roster_;
	
public:
	Roster();
	~Roster();
	
	int insertIfNo(const char*, const char *);
	int changeUserAvailability(const char *, int);
	int changeUserStatus(const char *, const char *);
	userInfo* getElement(const char *) const;
	int getEntriesN();
	int doForAll(void (*function)(String *, userInfo *, void *), void *);
};

#endif