/* Event header for application - AppBuilder 1.14C */

#if defined(__cplusplus)
extern "C" {
#endif

const ApEventLink_t appl_links[] = {
	{ 3, 0, 0L, 0L, 0L, &Pelican, Pelican_links, NULL, 0, setup, 1, 0, 0, 0, dsPelican },
	{ 0, 0, 0L, 0L, 0L, NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0, NULL }
	};

ApEventLink_t internal_links[] = {
	{ 3, 0, 0L, 0L, 0L, &wChat, wChat_links, NULL, 0, rosterDoubleClick, 0, 0, 0, 0, dswChat },
	{ 11, 0, 0L, 0L, 0L, &iconSet, iconSet_links, NULL, 0, NULL, 0, 0, 0, 0, dsiconSet },
	{ 0, 0, 0L, 0L, 0L, NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0, NULL }
	};

const ApEventLink_t Pelican_links[] = {
	{ 5, 0, 0L, 0L, 0L, &mCompanions, mCompanions_links, "mbtCompanions", 2009, NULL, 0, 1, 0, 0, NULL },
	{ 5, 0, 0L, 0L, 0L, &mNodes, mNodes_links, "mbtNodes", 2009, NULL, 0, 1, 0, 0, NULL },
	{ 3, 0, 0L, 0L, 0L, &wChat, wChat_links, "trRoster", 23022, rosterDoubleClick, 0, 0, 0, 0, dswChat },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "cboxStatus", 31020, comboBoxClose, 0, 0, 0, 0, NULL },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "wTimer", 41002, xmppTimerActivated, 0, 0, 0, 0, NULL },
	{ 0, 0, 0L, 0L, 0L, NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0, NULL }
	};

const ApEventLink_t mCompanions_links[] = {
	{ 10, 0, 0L, 0L, 0L, NULL, NULL, "exitFrom", 2009, NULL, 0, 0, 0, 0, NULL },
	{ 0, 0, 0L, 0L, 0L, NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0, NULL }
	};

const ApEventLink_t mNodes_links[] = {
	{ 3, 0, 0L, 0L, 0L, &wNodesControl, wNodesControl_links, "nodesControl", 2009, openNodesControlFromMenu, 0, 0, 0, 0, dswNodesControl },
	{ 0, 0, 0L, 0L, 0L, NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0, NULL }
	};

const ApEventLink_t wNodesControl_links[] = {
	{ 10, 0, 0L, 0L, 0L, NULL, NULL, "btCloseNodesControl", 2009, NULL, 0, 0, 0, 0, NULL },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "btDeleteNodeWNodesControl", 2009, deleteNode, 0, 0, 0, 0, NULL },
	{ 3, 0, 0L, 0L, 0L, &wAddNode, wAddNode_links, "btAddNodeWNodesControl", 2009, btAddNodeSetup, 0, 0, 0, 0, dswAddNode },
	{ 3, 0, 0L, 0L, 0L, &wAddNode, wAddNode_links, "btEditNodeWNodesControl", 2009, btEditNodeSetup, 0, 0, 0, 0, dswAddNode },
	{ 5, 0, 0L, 0L, 0L, &mActivateNode, mActivateNode_links, "lsNodes", 2016, NULL, 0, 10, 0, 0, NULL },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "lsNodes", 23010, selectClientNode, 0, 0, 0, 0, NULL },
	{ 0, 0, 0L, 0L, 0L, NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0, NULL }
	};

const ApEventLink_t wChat_links[] = {
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "wChat", 18024, closeChatWindow, 0, 0, 0, 0, NULL },
	{ 5, 0, 0L, 0L, 0L, &mTalk, mTalk_links, "mbtTalk", 2009, NULL, 0, 1, 0, 0, NULL },
	{ 8, 2, 61453L, 2L, 0L, NULL, NULL, "mtMessageEdit", 1010, sendMessage, 0, 0, 0, 0, NULL },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "mtMessageEdit", 2010, focusMessage, 0, 0, 0, 0, NULL },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "mtMessageEdit", 2011, unfocusMessage, 0, 0, 0, 0, NULL },
	{ 0, 0, 0L, 0L, 0L, NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0, NULL }
	};

const ApEventLink_t mTalk_links[] = {
	{ 3, 0, 0L, 0L, 0L, &wHistory, wHistory_links, "watchHistory", 2009, loadChatHistory, 0, 0, 0, 0, dswHistory },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "cleanChatWindow", 2009, clearChatWindow, 0, 0, 0, 0, NULL },
	{ 9, 0, 0L, 0L, 0L, NULL, NULL, "closeChat", 2009, NULL, 0, 0, 0, 0, NULL },
	{ 0, 0, 0L, 0L, 0L, NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0, NULL }
	};

const ApEventLink_t wAddNode_links[] = {
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "nodeEncryption", 31020, comboBoxClose, 0, 0, 0, 0, NULL },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "nodeLogin", 4010, checkNeccessaryFields, 0, 0, 0, 0, NULL },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "nodePassword", 4010, checkNeccessaryFields, 0, 0, 0, 0, NULL },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "nodeDomain", 4010, checkNeccessaryFields, 0, 0, 0, 0, NULL },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "tabExtra", 2009, switchAddNodeTabs, 0, 0, 0, 0, NULL },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "tabMain", 2009, switchAddNodeTabs, 0, 0, 0, 0, NULL },
	{ 10, 0, 0L, 0L, 0L, NULL, NULL, "btCancelWAddNode", 2009, NULL, 0, 0, 0, 0, NULL },
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "btAddWAddNode", 2009, addOrEditNode, 0, 0, 0, 0, NULL },
	{ 9, 0, 0L, 0L, 0L, NULL, NULL, "btAddWAddNode", 2009, NULL, 0, 0, 0, 0, NULL },
	{ 0, 0, 0L, 0L, 0L, NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0, NULL }
	};

const ApEventLink_t mActivateNode_links[] = {
	{ 8, 0, 0L, 0L, 0L, NULL, NULL, "accountOn", 2009, makeNodeActive, 0, 0, 0, 0, NULL },
	{ 0, 0, 0L, 0L, 0L, NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0, NULL }
	};

const ApEventLink_t iconSet_links[] = {
	{ 0, 0, 0L, 0L, 0L, NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0, NULL }
	};

const ApEventLink_t wHistory_links[] = {
	{ 0, 0, 0L, 0L, 0L, NULL, NULL, NULL, 0, NULL, 0, 0, 0, 0, NULL }
	};

const char ApOptions[] = AB_OPTIONS;

#if defined(__cplusplus)
}
#endif

