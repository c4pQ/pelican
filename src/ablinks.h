/* Link header for application - AppBuilder 1.14C */

#if defined(__cplusplus)
extern "C" {
#endif

ApWindowLink_t Pelican = {
	"Pelican.wgtw",
	"applicationIcon.wgti",
	};

ApItem_t mCompanions_items[] = {
	{ 1, 1, NULL, NULL, 0, "addCompanion", "\xD0\x94\xD0\xBE\xD0\xB1\xD0\xB0\xD0\xB2\xD0\xB8\xD1\x82\xD1\x8C \xD1\x81\xD0\xBE\xD0\xB1\xD0\xB5\xD1\x81\xD0\xB5\xD0\xB4\xD0\xBD\xD0\xB8\xD0\xBA\xD0\xB0...", },
	{ 1, 1, NULL, NULL, 0, "addChat", "\xD0\x94\xD0\xBE\xD0\xB1\xD0\xB0\xD0\xB2\xD0\xB8\xD1\x82\xD1\x8C \xD1\x87\xD0\xB0\xD1\x82...", },
	{ 1, 1, NULL, NULL, 0, "addGroup", "\xD0\x94\xD0\xBE\xD0\xB1\xD0\xB0\xD0\xB2\xD0\xB8\xD1\x82\xD1\x8C \xD0\xB3\xD1\x80\xD1\x83\xD0\xBF\xD0\xBF\xD1\x83...", },
	{ 1, 16, NULL, NULL, 0, "", "", },
	{ 1, 1, NULL, NULL, 0, "exitFrom", "\xD0\x92\xD1\x8B\xD0\xB9\xD1\x82\xD0\xB8", },
	{ 0, 0, NULL, NULL, 0, NULL, NULL } };

ApMenuLink_t mCompanions = {
	"mCompanions",
	"",
	NULL,
	NULL,
	-2,
	mCompanions_items
	};

ApItem_t mNodes_items[] = {
	{ 1, 1, NULL, NULL, 0, "nodesControl", "\xD0\xA3\xD0\xBF\xD1\x80\xD0\xB0\xD0\xB2\xD0\xBB\xD0\xB5\xD0\xBD\xD0\xB8\xD0\xB5 \xD1\x83\xD1\x87\xD0\xB5\xD1\x82\xD0\xBD\xD1\x8B\xD0\xBC\xD0\xB8 \xD0\xB7\xD0\xB0\xD0\xBF\xD0\xB8\xD1\x81\xD1\x8F\xD0\xBC\xD0\xB8", },
	{ 0, 0, NULL, NULL, 0, NULL, NULL } };

ApMenuLink_t mNodes = {
	"mNodes",
	"",
	NULL,
	NULL,
	-2,
	mNodes_items
	};

ApWindowLink_t wNodesControl = {
	"wNodesControl.wgtw",
	};

ApWindowLink_t wChat = {
	"wChat.wgtw",
	};

ApItem_t mTalk_items[] = {
	{ 1, 1, NULL, NULL, 0, "watchHistory", "\xD0\x9F\xD0\xBE\xD1\x81\xD0\xBC\xD0\xBE\xD1\x82\xD1\x80\xD0\xB5\xD1\x82\xD1\x8C \xD0\xB6\xD1\x83\xD1\x80\xD0\xBD\xD0\xB0\xD0\xBB", },
	{ 1, 1, NULL, NULL, 0, "cleanChatWindow", "\xD0\x9E\xD1\x87\xD0\xB8\xD1\x81\xD1\x82\xD0\xB8\xD1\x82\xD1\x8C", },
	{ 1, 16, NULL, NULL, 0, "", "", },
	{ 1, 1, NULL, NULL, 0, "sendFile", "\xD0\x9E\xD1\x82\xD0\xBF\xD1\x80\xD0\xB0\xD0\xB2\xD0\xB8\xD1\x82\xD1\x8C \xD1\x84\xD0\xB0\xD0\xB9\xD0\xBB...", },
	{ 1, 16, NULL, NULL, 0, "", "", },
	{ 1, 1, NULL, NULL, 0, "closeChat", "\xD0\x97\xD0\xB0\xD0\xBA\xD1\x80\xD1\x8B\xD1\x82\xD1\x8C", },
	{ 0, 0, NULL, NULL, 0, NULL, NULL } };

ApMenuLink_t mTalk = {
	"mTalk",
	"",
	NULL,
	NULL,
	-2,
	mTalk_items
	};

ApWindowLink_t wAddNode = {
	"wAddNode.wgtw",
	};

ApItem_t mActivateNode_items[] = {
	{ 1, 1, NULL, NULL, 0, "accountOn", "\xD0\x92\xD0\xBA\xD0\xBB\xD1\x8E\xD1\x87\xD0\xB8\xD1\x82\xD1\x8C \xD0\xB0\xD0\xBA\xD0\xBA\xD0\xB0\xD1\x83\xD0\xBD\xD1\x82", },
	{ 0, 0, NULL, NULL, 0, NULL, NULL } };

ApMenuLink_t mActivateNode = {
	"mActivateNode",
	"",
	NULL,
	NULL,
	-2,
	mActivateNode_items
	};

ApPictureLink_t iconSet = {
	"iconSet.wgtp",
	0,
	NULL
	};

ApWindowLink_t wHistory = {
	"wHistory.wgtw",
	};


#if defined(__cplusplus)
}
#endif

