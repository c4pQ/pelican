#include <stdio.h>
#include "XEventQueue.h"

int	XEvent::messageId_ = 0;

XEvent::XEvent()
{
	messageId_++;
	type_ = 0;
	from_ = 0;
	data_ = 0;
}

XEvent::XEvent(int type, const char *from, const char *data)
{
	messageId_++;
	type_ = type;
	from_ = from;
	data_ = data;
}

XEvent::~XEvent()
{
	
}

int XEvent::operator ==(const XEvent &other) const
{
	return messageId_ == other.getMessageId();
}

XEventQueue::XEventQueue()
{
}

XEventQueue::~XEventQueue()
{
}
	
int XEventQueue::putEvent(XEvent *event)
{
	queue_.insert(event);
	return 0;
}

XEvent *XEventQueue::getEvent()
{
	if(queue_.isEmpty())
		return NULL;
	
	return queue_.get();
}

int XEventQueue::isEmpty()
{
	return queue_.isEmpty();
}

int XEvent::getMessageId() const
{
	return messageId_;
}

int XEvent::getMessageType() const
{
	return type_;
}

const char *XEvent::getMessageFrom() const
{
	return from_;
}

const char *XEvent::getMessageData() const
{
	return data_;
}
