
/* ../abmain.cc */
int main ( int argc , char *argv []);

/* ../callbacks.cpp */
int rosterDoubleClick ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int switchAddNodeTabs ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int deleteNode ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int selectClientNode ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int addOrEditNode ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int makeNodeActive ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int checkNeccessaryFields ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int xmppTimerActivated ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int sendMessage ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int focusMessage ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int unfocusMessage ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int comboBoxClose ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int closeChatWindow ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int clearChatWindow ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* ../setup.cpp */
int setup ( PtWidget_t *link_instance , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* ../setupFunctions.cpp */
int openNodesControlFromMenu ( PtWidget_t *link_instance , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int btAddNodeSetup ( PtWidget_t *link_instance , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int btEditNodeSetup ( PtWidget_t *link_instance , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int loadChatHistory ( PtWidget_t *link_instance , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
