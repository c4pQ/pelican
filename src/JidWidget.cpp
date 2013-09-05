#include "JidWidget.h"

JidWidget::JidWidget()
{
	jid_ = "";
	widget_ = NULL;
}

JidWidget::JidWidget(const char *jid, PtWidget_t *widget)
{
	char *jidCopy = strdup(jid);
	jid_ = strtok(jidCopy, "/");
	widget_ = widget;
}

JidWidget::~JidWidget()
{
}
	
const char *JidWidget::getJid() const
{
	return (const char*)jid_;
}

PtWidget_t *JidWidget::getWidget() const
{
	return widget_;
}
	
int JidWidget::setJid(const char *jid)
{
	char *jidCopy = strdup(jid);
	jid_ = strtok(jidCopy, "/");
	return 0;
}

int JidWidget::setWidget(PtWidget_t *widget)
{
	widget_ = widget;
	return 0;
}
	
int JidWidget::operator ==(const JidWidget &other) const
{
	return jid_ == other.getJid();
}

int JidWidget::operator <(const JidWidget &other) const
{
	return jid_ < other.getJid();
}