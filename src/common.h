/* Header "common.h" for Pelican Application */
#define TAB_MAIN_USERINFO	'1'
#define TAB_EXTRA_USERINFO	'2'

#define NODE_ADD_STR	"1"
#define NODE_EDIT_STR	"2"

#define NODE_ADD	'1'
#define NODE_EDIT	'2'

#define FLAG_OFF	0
#define FLAG_ON		1

#define WIDGET_GOT_FOCUS	"1"
#define WIDGET_LOST_FOCUS	""

#define MESSAGE_FROM_ME		1
#define MESSAGE_TO_ME		0

#include "XmppClient.h"
#include "JidWidget.h"
#include "ClientNodesVector.h"

#include <nls.h>
#include <wcskip.h>

extern XmppClient *xmppClient;
extern ClientNodesVector *nodesVector;
extern WCPtrSkipListSet<JidWidget> chatWindows;
extern const PhImage_t* images[14];

void setWidgetText(PtWidget_t *, const char *);
void setWidgetUserData(PtWidget_t *, const char *);
void setSelectedCBoxItem(PtWidget_t *widget, int position);
int getSelectedCBoxItem(PtWidget_t *widget);
const char * getWidgetUserData(PtWidget_t *widget);
void setWidgetFlags (PtWidget_t *widget, long flags, char state);
short checkWidgetFlags (PtWidget_t *widget, long flags);
const char *getWidgetString(PtWidget_t *widget);
int isWidgetTextEmpty(PtWidget_t *widget);

int refreshNodesList();
int fillWAddNodeFields();

int addNewNode();
int editSelectedNode();
int sendMessageFromMTWidget(PtWidget_t *);
int clearMTWidget(PtWidget_t *);
int showMessageInWindow(PtWidget_t *, int isItMe, const char *jid, const char *message);
int appendMessageToHistory(PtWidget_t *);
const char *defineCompanionsJid(PtWidget_t *);
int displayMyMessage(PtWidget_t *);

void addEveryElementToTree(String *jid, userInfo *name, void *);

int getChatWindowToFront(const char *jid);
int windowAlreadyReleased(const char *jid);
int addReleasedWindowToSet(const char *jid, PtWidget_t *widget);
int changeStatusLabel(PtWidget_t *widget, int status, int size);
void changeStatusLabel(JidWidget *, void *);

int refreshRosterTree();
int changeStatusLabelsInChatWindows();
int reenterWithAnotherAccount();
int definePhotonFolder();
