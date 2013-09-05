#include <String.h>
#include <Pt.h>

#ifndef __JIDWIDGET_H__
#define __JIDWIDGET_H__

class JidWidget
{
private:
	String jid_;
	PtWidget_t *widget_;
	
public:
	JidWidget();
	JidWidget(const char *, PtWidget_t *);
	~JidWidget();
	
	const char *getJid() const;
	PtWidget_t *getWidget() const;
	
	int setJid(const char *);
	int setWidget(PtWidget_t *);
	
	int operator ==(const JidWidget &) const;
	int operator <(const JidWidget &) const;
};

#endif
