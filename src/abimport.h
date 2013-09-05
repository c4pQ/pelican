/* Import (extern) header for application - AppBuilder 1.14C */

#if defined(__cplusplus)
extern "C" {
#endif

#include "abdefine.h"

extern const ApEventLink_t appl_links[];
extern ApEventLink_t internal_links[];

extern ApWindowLink_t Pelican;
extern const ApEventLink_t Pelican_links[];
extern ApWidget_t dsPelican[7];

extern ApMenuLink_t mCompanions;
extern const ApEventLink_t mCompanions_links[];
extern ApMenuLink_t mNodes;
extern const ApEventLink_t mNodes_links[];
extern ApWindowLink_t wNodesControl;
extern const ApEventLink_t wNodesControl_links[];
extern ApWidget_t dswNodesControl[6];

extern ApWindowLink_t wChat;
extern const ApEventLink_t wChat_links[];
extern ApWidget_t dswChat[7];

extern ApMenuLink_t mTalk;
extern const ApEventLink_t mTalk_links[];
extern ApWindowLink_t wAddNode;
extern const ApEventLink_t wAddNode_links[];
extern ApWidget_t dswAddNode[20];

extern ApMenuLink_t mActivateNode;
extern const ApEventLink_t mActivateNode_links[];
extern ApPictureLink_t iconSet;
extern const ApEventLink_t iconSet_links[];
extern ApWidget_t dsiconSet[19];

extern ApWindowLink_t wHistory;
extern const ApEventLink_t wHistory_links[];
extern ApWidget_t dswHistory[2];


#if defined(__cplusplus)
}
#endif

#ifdef __cplusplus
int setup( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int openNodesControlFromMenu( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int rosterDoubleClick( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int btAddNodeSetup( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int switchAddNodeTabs( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int btEditNodeSetup( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int deleteNode( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int selectClientNode( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int addOrEditNode( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int makeNodeActive( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int checkNeccessaryFields( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int xmppTimerActivated( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int sendMessage( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int focusMessage( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int unfocusMessage( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int comboBoxClose( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int closeChatWindow( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int clearChatWindow( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int loadChatHistory( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
#endif
