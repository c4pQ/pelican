#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <Ph.h>
#include <Pt.h>
#include <Ap.h>

#include "common.h"
#include "abimport.h"

int refreshNodesList()
{
	ClientNode *clientNode = NULL;
	char activeSymbol;
	char *nodesArray[1];
	nodesArray[0] = (char*)malloc(MAX_STR);
	
	PtListDeleteAllItems(ABW_lsNodes);
	::nodesVector->resetIterator();
	while(clientNode = ::nodesVector->getNode())
	{
		memset(nodesArray[0], MAX_STR, 0);
		activeSymbol = (clientNode->isActive())?'X':' ';
		_bprintf(nodesArray[0], MAX_STR, "%c\t%s\tXMPP", activeSymbol, (const char*)clientNode->getJid());
		PtListAddItems(ABW_lsNodes, (const char * *)nodesArray, 1, 0);
	}
	PtListSelectPos(ABW_lsNodes, 1);
	::nodesVector->setSelectedItemNumber(0);
	
	free(nodesArray);	
	return 0;
}

void setWidgetText(PtWidget_t *widget, const char *text)
{
	PtArg_t arg;
	PtSetArg(&arg, Pt_ARG_TEXT_STRING, text, 0);
	PtSetResources(widget, 1, &arg);
}

void setWidgetUserData(PtWidget_t *widget, const char *data)
{
	PtArg_t arg;
	PtSetArg(&arg, Pt_ARG_USER_DATA, data, strlen(data) + 1);
	PtSetResources(widget, 1, &arg);
}

void setWidgetFlags (PtWidget_t *widget, long flags, char state)
{
	PtArg_t arg;
    PtSetArg(&arg, Pt_ARG_FLAGS, state ? Pt_TRUE : 0, flags);
	PtSetResources(widget, 1, &arg);
}

short checkWidgetFlags (PtWidget_t *widget, long flags)
{
	if ((widget->flags & flags) == flags)
		return 1;
	else
		return 0;
}

void setSelectedCBoxItem(PtWidget_t *widget, int position)
{
	PtArg_t arg;
	PtSetArg(&arg, Pt_ARG_CBOX_SEL_ITEM, position, 0);
	PtSetResources(widget, 1, &arg);
	PtDamageWidget(widget);
}

int getSelectedCBoxItem(PtWidget_t *widget)
{
	PtArg_t arg;
	PtSetArg(&arg, Pt_ARG_CBOX_SEL_ITEM, 0, 0);
	PtGetResources(widget, 1, &arg);
	
	return arg.value;
}

const char * getWidgetUserData(PtWidget_t *widget)
{
	PtArg_t arg;
	PtSetArg(&arg, Pt_ARG_USER_DATA, 0, 0);
	PtGetResources(widget, 1, &arg);
	return (char *)arg.value;
}

const char *getWidgetString(PtWidget_t *widget)
{
    PtArg_t arg;

	if(PtWidgetIsClassMember(widget, PtNumeric))
		widget = ((PtNumericWidget_t*)widget)->text_wgt;

	PtSetArg(&arg, Pt_ARG_TEXT_STRING, 0, 0);
	PtGetResources(widget, 1, &arg);
	return (char*) arg.value;
}

int isWidgetTextEmpty(PtWidget_t *widget)
{
	int size = strlen(getWidgetString(widget));
	return (size == 0);
}

int fillWAddNodeFields()
{
	ClientNode *node = ::nodesVector->getSelectedNode();
	char buffer[10] = {'\0'};
	unsigned short port = node->getPort();

	setWidgetText(ABW_nodeLogin, node->getLogin());
	setWidgetText(ABW_nodePassword, node->getPassword());
	setWidgetText(ABW_nodeDomain, node->getDomain());
	setWidgetText(ABW_nodePort, (port)?itoa(port, buffer, 10):"");
	setWidgetText(ABW_nodeServer, node->getServer());
	setWidgetText(ABW_nodeProxy, node->getProxy());
	setWidgetText(ABW_nodeBosh, node->getBosh());

	setSelectedCBoxItem(ABW_nodeEncryption, node->getEncryptionType());

	return 0;
}

int initNodeClassFromFields(ClientNode *node)
{
	node->setLogin(getWidgetString(ABW_nodeLogin));
	node->setPassword(getWidgetString(ABW_nodePassword));
	node->setDomain(getWidgetString(ABW_nodeDomain));
	node->setServer(getWidgetString(ABW_nodeServer));
	node->setProxy(getWidgetString(ABW_nodeProxy));
	node->setBosh(getWidgetString(ABW_nodeBosh));

	node->setPort((unsigned short)atoi(getWidgetString(ABW_nodePort)));
	node->setEncryptionType((unsigned short)getSelectedCBoxItem(ABW_nodeEncryption));

	return 0;
}

int addNewNode()
{
	ClientNode *node = new ClientNode();
	initNodeClassFromFields(node);
	::nodesVector->insertIntoList(node);
	refreshNodesList();
	return 0;
}

int editSelectedNode()
{
	initNodeClassFromFields(::nodesVector->getEditingNode());
	refreshNodesList();
	return 0;
}

int sendMessageFromMTWidget(PtWidget_t *activeChatWindow)
{
	PtWidget_t *mtMessageEdit = ApGetWidgetPtr(activeChatWindow, ABN_mtMessageEdit);
	const char *jid = defineCompanionsJid(activeChatWindow);
	const char *message = getWidgetString(mtMessageEdit);
	::xmppClient->sendMessage(jid, message);

	return 0;
}

int clearMTWidget(PtWidget_t *activeChatWindow)
{
	PtWidget_t *mtMessageEdit = ApGetWidgetPtr(activeChatWindow, ABN_mtMessageEdit);
	
	setWidgetText(mtMessageEdit, "");
	
	return 0;
}

int showMessageInWindow(PtWidget_t *activeChatWindow, int isItMe, const char *jid, const char *message)
{
	PtMultiTextAttributes_t attributes = {0};
	PtWidget_t *chatWindow = NULL;
	
	if(isItMe)
	{
		attributes.text_color = PgRGB(255, 0, 0);
		chatWindow = activeChatWindow;
	}
	else
	{
		attributes.text_color = PgRGB(0, 122, 252);
		JidWidget jidWidget(jid, NULL);
		JidWidget *foundElement = chatWindows.find(&jidWidget);
		if(foundElement)
			chatWindow = foundElement->getWidget();
		else
		{
			PtCallbackInfo_t cb = {0};
			PhEvent_t event = {0};

			cb.event = &event;
			cb.event->type = Ph_EV_BUT_RELEASE;
			cb.event->subtype = Ph_EV_RELEASE_PHANTOM;
			
			setWidgetUserData(ABW_Pelican, jid);
			
			ApCreateModule(ABM_wChat, NULL, &cb);
			foundElement = chatWindows.find(&jidWidget);
			chatWindow = foundElement->getWidget();
		}
	}
	
	PtWidget_t *mtChat = ApGetWidgetPtr(chatWindow, ABN_mtChat);
	
	PtMultiTextModifyText(mtChat, 0, 0, -1, (char *)jid, strlen(jid), &attributes, Pt_MT_TEXT_COLOR);
	
	PtMultiTextModifyText(mtChat, 0, 0, -1, ": ", 1, &attributes, 0);
	attributes.text_color = PgRGB(0, 0, 0);
	PtMultiTextModifyText(mtChat, 0, 0, -1, (char *)message, strlen(message), &attributes, Pt_MT_TEXT_COLOR);
	PtMultiTextModifyText(mtChat, 0, 0, -1, "\n", 1, &attributes, 0);
	
	return 0;
}

int appendMessageToHistory(PtWidget_t *)
{
	return 0;
}

const char *defineCompanionsJid(PtWidget_t *activeChatWindow)
{
	return getWidgetUserData(activeChatWindow);
}

int displayMyMessage(PtWidget_t *activeChatWindow)
{
	PtWidget_t *mtMessageEdit = ApGetWidgetPtr(activeChatWindow, ABN_mtMessageEdit);
	const char *jid = ::xmppClient->getJid();
	const char *message = getWidgetString(mtMessageEdit);
	showMessageInWindow(activeChatWindow, MESSAGE_FROM_ME, jid, message);

	return 0;
}

void addEveryElementToTree(String *jid, userInfo *info, void *)
{
	PtImageTreeItem_t *leaf = NULL;
	int statusImage = info->getAvailability();
	const char *name = info->getName();
	
	leaf = PtImageTreeAllocItem(ABW_trRoster, name, statusImage, statusImage);
	leaf->data = (void*)((const char *)*jid);
	
	PtImageTreeAddFirst(ABW_trRoster, leaf, NULL);
}

int getChatWindowToFront(const char *)
{
	return 0;
}

int windowAlreadyReleased(const char *jid)
{
	JidWidget jidWidget(jid, NULL);
	return chatWindows.contains(&jidWidget);
}

int addReleasedWindowToSet(const char *jid, PtWidget_t *widget)
{
	chatWindows.insert(new JidWidget(jid, widget));
	return 0;
}

int changeStatusLabel(PtWidget_t *widget, int status, int size)
{
	PtArg_t arg;
	int fisrtIcon = 0;
	if(size == SIZE_22)
		fisrtIcon = FIRST_22_ICON;
	else
		fisrtIcon = FIRST_32_ICON;
		
	PtSetArg(&arg, Pt_ARG_LABEL_DATA, images[fisrtIcon + status], sizeof(PhImage_t));
	PtSetResources(widget, 1, &arg);
	PtDamageWidget(widget);
	
	return 0;
}

int refreshRosterTree()
{
	PtImageTreeFreeAllItems(ABW_trRoster);
	::xmppClient->doForAllRosterElements(addEveryElementToTree, NULL);
	
	return 0;
}

int changeStatusLabelsInChatWindows()
{
	::chatWindows.forAll(changeStatusLabel, NULL);
	return 0;
}

void changeStatusLabel(JidWidget *jw, void *)
{
	const char *jid = jw->getJid();
	const userInfo *ui = (::xmppClient->getRoster())->getElement(jid);
	
	changeStatusLabel(ABW_lbStatusImage, ui->getAvailability(), SIZE_32);
}

int reenterWithAnotherAccount()
{
	return 0;
}

int definePhotonFolder()
{
	char *homeFolder = NULL;
	
	homeFolder = getenv("HOME");
	
	if(homeFolder)
		printf("%s\n", homeFolder);
	
	return 0;
}