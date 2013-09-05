#ifndef __EVENTQUEUE_H__
#define __EVENTQUEUE_H__

#include <wcqueue.h>
#include <wclist.h>
#include <String.h>

enum eventType{GOT_MESSAGE, ROSTER_REFRESH};

class XEvent
{
private:
	static int messageId_;
	eventType type_;
	String from_;
	String data_;

public:
	XEvent();
	XEvent(int, const char*, const char*);
	~XEvent();
	
	int getMessageId() const;	
	int getMessageType() const;	
	const char *getMessageFrom() const;	
	const char *getMessageData() const;	
	
	int operator ==(const XEvent &other) const;
};

class XEventQueue
{
private:
	WCQueue< XEvent *, WCPtrSList<XEvent> > queue_;

public:

	XEventQueue();
	~XEventQueue();

	int putEvent(XEvent *);
	XEvent *getEvent();
	isEmpty();
};

#endif