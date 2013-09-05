/* Define header for application - AppBuilder 1.14C */

#if defined(__cplusplus)
extern "C" {
#endif

/* Internal Module Links */
extern const int ABI_wChat;
#define ABM_wChat                            &internal_links[ABI_wChat]
extern const int ABI_iconSet;
#define ABM_iconSet                          &internal_links[ABI_iconSet]

/* 'Pelican' Window link */
extern const int ABN_Pelican;
#define ABW_Pelican                          dsPelican[ABN_Pelican].wgt
extern const int ABN_mbtCompanions;
#define ABW_mbtCompanions                    dsPelican[ABN_mbtCompanions].wgt
extern const int ABN_mbtNodes;
#define ABW_mbtNodes                         dsPelican[ABN_mbtNodes].wgt
extern const int ABN_trRoster;
#define ABW_trRoster                         dsPelican[ABN_trRoster].wgt
extern const int ABN_cboxStatus;
#define ABW_cboxStatus                       dsPelican[ABN_cboxStatus].wgt
extern const int ABN_wTimer;
#define ABW_wTimer                           dsPelican[ABN_wTimer].wgt
extern const int ABN_lbMyStatusImage;
#define ABW_lbMyStatusImage                  dsPelican[ABN_lbMyStatusImage].wgt

/* 'mCompanions' Menu link */
extern const int ABN_addCompanion;
extern const int ABN_addChat;
extern const int ABN_addGroup;
extern const int ABN_exitFrom;

/* 'mCompanions' Menu link */
extern const int ABN_mCompanions;

/* 'mNodes' Menu link */
extern const int ABN_nodesControl;

/* 'mNodes' Menu link */
extern const int ABN_mNodes;

/* 'wNodesControl' Window link */
extern const int ABN_wNodesControl;
#define ABW_wNodesControl                    dswNodesControl[ABN_wNodesControl].wgt
extern const int ABN_btCloseNodesControl;
#define ABW_btCloseNodesControl              dswNodesControl[ABN_btCloseNodesControl].wgt
extern const int ABN_btDeleteNodeWNodesControl;
#define ABW_btDeleteNodeWNodesControl        dswNodesControl[ABN_btDeleteNodeWNodesControl].wgt
extern const int ABN_btAddNodeWNodesControl;
#define ABW_btAddNodeWNodesControl           dswNodesControl[ABN_btAddNodeWNodesControl].wgt
extern const int ABN_btEditNodeWNodesControl;
#define ABW_btEditNodeWNodesControl          dswNodesControl[ABN_btEditNodeWNodesControl].wgt
extern const int ABN_lsNodes;
#define ABW_lsNodes                          dswNodesControl[ABN_lsNodes].wgt

/* 'wChat' Window link */
extern const int ABN_wChat;
#define ABW_wChat                            dswChat[ABN_wChat].wgt
extern const int ABN_mbtTalk;
#define ABW_mbtTalk                          dswChat[ABN_mbtTalk].wgt
extern const int ABN_lbStatusImage;
#define ABW_lbStatusImage                    dswChat[ABN_lbStatusImage].wgt
extern const int ABN_lbName;
#define ABW_lbName                           dswChat[ABN_lbName].wgt
extern const int ABN_lbStatus;
#define ABW_lbStatus                         dswChat[ABN_lbStatus].wgt
extern const int ABN_mtMessageEdit;
#define ABW_mtMessageEdit                    dswChat[ABN_mtMessageEdit].wgt
extern const int ABN_mtChat;
#define ABW_mtChat                           dswChat[ABN_mtChat].wgt

/* 'mTalk' Menu link */
extern const int ABN_watchHistory;
extern const int ABN_cleanChatWindow;
extern const int ABN_sendFile;
extern const int ABN_closeChat;

/* 'mTalk' Menu link */
extern const int ABN_mTalk;

/* 'wAddNode' Window link */
extern const int ABN_wAddNode;
#define ABW_wAddNode                         dswAddNode[ABN_wAddNode].wgt
extern const int ABN_pnExtraSettings;
#define ABW_pnExtraSettings                  dswAddNode[ABN_pnExtraSettings].wgt
extern const int ABN_grAddNodeExtra;
#define ABW_grAddNodeExtra                   dswAddNode[ABN_grAddNodeExtra].wgt
extern const int ABN_nodeEncryption;
#define ABW_nodeEncryption                   dswAddNode[ABN_nodeEncryption].wgt
extern const int ABN_nodeEnablePlainText;
#define ABW_nodeEnablePlainText              dswAddNode[ABN_nodeEnablePlainText].wgt
extern const int ABN_nodePort;
#define ABW_nodePort                         dswAddNode[ABN_nodePort].wgt
extern const int ABN_nodeServer;
#define ABW_nodeServer                       dswAddNode[ABN_nodeServer].wgt
extern const int ABN_nodeProxy;
#define ABW_nodeProxy                        dswAddNode[ABN_nodeProxy].wgt
extern const int ABN_nodeBosh;
#define ABW_nodeBosh                         dswAddNode[ABN_nodeBosh].wgt
extern const int ABN_pnMainSettings;
#define ABW_pnMainSettings                   dswAddNode[ABN_pnMainSettings].wgt
extern const int ABN_grAddNodeMain;
#define ABW_grAddNodeMain                    dswAddNode[ABN_grAddNodeMain].wgt
extern const int ABN_xmpp20;
#define ABW_xmpp20                           dswAddNode[ABN_xmpp20].wgt
extern const int ABN_nodeLogin;
#define ABW_nodeLogin                        dswAddNode[ABN_nodeLogin].wgt
extern const int ABN_nodePassword;
#define ABW_nodePassword                     dswAddNode[ABN_nodePassword].wgt
extern const int ABN_nodeDomain;
#define ABW_nodeDomain                       dswAddNode[ABN_nodeDomain].wgt
extern const int ABN_tabAddNode;
#define ABW_tabAddNode                       dswAddNode[ABN_tabAddNode].wgt
extern const int ABN_tabExtra;
#define ABW_tabExtra                         dswAddNode[ABN_tabExtra].wgt
extern const int ABN_tabMain;
#define ABW_tabMain                          dswAddNode[ABN_tabMain].wgt
extern const int ABN_btCancelWAddNode;
#define ABW_btCancelWAddNode                 dswAddNode[ABN_btCancelWAddNode].wgt
extern const int ABN_btAddWAddNode;
#define ABW_btAddWAddNode                    dswAddNode[ABN_btAddWAddNode].wgt

/* 'mActivateNode' Menu link */
extern const int ABN_accountOn;

/* 'mActivateNode' Menu link */
extern const int ABN_mActivateNode;

/* 'iconSet' Picture link */
extern const int ABN_iconSet;
#define ABW_iconSet                          dsiconSet[ABN_iconSet].wgt
extern const int ABN_available32;
#define ABW_available32                      dsiconSet[ABN_available32].wgt
extern const int ABN_available22;
#define ABW_available22                      dsiconSet[ABN_available22].wgt
extern const int ABN_away22;
#define ABW_away22                           dsiconSet[ABN_away22].wgt
extern const int ABN_busy22;
#define ABW_busy22                           dsiconSet[ABN_busy22].wgt
extern const int ABN_offline22;
#define ABW_offline22                        dsiconSet[ABN_offline22].wgt
extern const int ABN_available11;
#define ABW_available11                      dsiconSet[ABN_available11].wgt
extern const int ABN_available11W;
#define ABW_available11W                     dsiconSet[ABN_available11W].wgt
extern const int ABN_away11;
#define ABW_away11                           dsiconSet[ABN_away11].wgt
extern const int ABN_away11W;
#define ABW_away11W                          dsiconSet[ABN_away11W].wgt
extern const int ABN_busy11;
#define ABW_busy11                           dsiconSet[ABN_busy11].wgt
extern const int ABN_busy11W;
#define ABW_busy11W                          dsiconSet[ABN_busy11W].wgt
extern const int ABN_offline11;
#define ABW_offline11                        dsiconSet[ABN_offline11].wgt
extern const int ABN_offline11W;
#define ABW_offline11W                       dsiconSet[ABN_offline11W].wgt
extern const int ABN_unknown;
#define ABW_unknown                          dsiconSet[ABN_unknown].wgt
extern const int ABN_unknown11;
#define ABW_unknown11                        dsiconSet[ABN_unknown11].wgt
extern const int ABN_away32;
#define ABW_away32                           dsiconSet[ABN_away32].wgt
extern const int ABN_busy32;
#define ABW_busy32                           dsiconSet[ABN_busy32].wgt
extern const int ABN_offline32;
#define ABW_offline32                        dsiconSet[ABN_offline32].wgt

/* 'wHistory' Window link */
extern const int ABN_wHistory;
#define ABW_wHistory                         dswHistory[ABN_wHistory].wgt

#define AB_OPTIONS "s:x:y:h:w:S:"

#if defined(__cplusplus)
}
#endif

