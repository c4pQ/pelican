/* Y o u r   D e s c r i p t i o n                       */
/*                            AppBuilder Photon Code Lib */
/*                                         Version 1.14C */

/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Toolkit headers */
#include <Ph.h>
#include <Pt.h>
#include <Ap.h>

/* Local headers */
#include "common.h"
#include "abimport.h"
#include "proto.h"


int
rosterDoubleClick( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	PhPointerEvent_t *pointerEvent = (PhPointerEvent_t*) PhGetData(cbinfo->event);
	
	if((cbinfo->event->type == Ph_EV_BUT_RELEASE) &&
		((pointerEvent->click_count > 1) || (cbinfo->event->subtype == Ph_EV_RELEASE_PHANTOM)))
	{
		PtImageTreeItem_t *treeItem = PtImageTreeGetCurrent(ABW_trRoster);
		const char *jid = NULL;
			
		if(cbinfo->event->subtype == Ph_EV_RELEASE_PHANTOM)
			jid = getWidgetUserData(ABW_Pelican);
		else
			jid = (const char *)(treeItem->data);

		if(windowAlreadyReleased(jid))
		{
			getChatWindowToFront(jid);
		}	
		else
		{
//TODO статус пользователя установить
			const userInfo *ui = (::xmppClient->getRoster())->getElement(jid);
			PtWidget_t *lbName = ApGetWidgetPtr(widget, ABN_lbName);
			setWidgetText(lbName, ui->getName());
			setWidgetUserData(widget, jid);
			addReleasedWindowToSet(jid, widget);
			changeStatusLabel(ABW_lbStatusImage, ui->getAvailability(), SIZE_32);
			return( Pt_CONTINUE );
		}
	}
	
	return( Pt_END );
}


int
switchAddNodeTabs( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	if(widget->user_data)
	{
		switch(widget->user_data[0])
		{
			case TAB_MAIN_USERINFO:
				PtWidgetToFront(ABW_pnMainSettings);
			break;
			
			case TAB_EXTRA_USERINFO:
				PtWidgetToFront(ABW_pnExtraSettings);
			break;
			
			default:
				PtWidgetToFront(ABW_pnMainSettings);
		}
		PtWidgetToFront(ABW_tabAddNode);
	}
	
	return( Pt_CONTINUE );
}


int
deleteNode( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	int itemPosition = ::nodesVector->getSelectedItemNumber();
	
	PtListDeleteItemPos(ABW_lsNodes, 1, itemPosition + 1);
	::nodesVector->deleteNode(itemPosition);
	
	PtListSelectPos(ABW_lsNodes, 1);
	::nodesVector->setSelectedItemNumber(0);
	
	return( Pt_CONTINUE );
}


int
selectClientNode( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	::nodesVector->setSelectedItemNumber(((PtListCallback_t*)(cbinfo->cbdata))->item_pos - 1);
	
	return( Pt_CONTINUE );
}


int
addOrEditNode( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	if(widget->user_data)
	{
		switch(widget->user_data[0])
		{
			case NODE_ADD:
				addNewNode();
			break;
		
			case NODE_EDIT:
				editSelectedNode();
			break;
		}
	}
	
	::nodesVector->writeListToFile();
		
	return( Pt_CONTINUE );
}


int
makeNodeActive( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	::nodesVector->makeSelectedNodeActive();
//TODO	reenterWithAnotherAccount();
	refreshNodesList();
	
	return( Pt_CONTINUE );
}


int
checkNeccessaryFields( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	if(!isWidgetTextEmpty(ABW_nodeLogin) && !isWidgetTextEmpty(ABW_nodePassword) && !isWidgetTextEmpty(ABW_nodeDomain))
		setWidgetFlags(ABW_btAddWAddNode, Pt_BLOCKED, FLAG_OFF);
	else
		setWidgetFlags(ABW_btAddWAddNode, Pt_BLOCKED, FLAG_ON);
	
	return( Pt_CONTINUE );
}


int
xmppTimerActivated( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	time_t now = time(NULL);
	
	::xmppClient->startEventLoopOnce();
	XEvent *event = ::xmppClient->eventQueue_.getEvent();
	//TODO different event hadlers
	if(event)
		switch(event->getMessageType())
		{
			case(1):
				showMessageInWindow(NULL, MESSAGE_TO_ME, event->getMessageFrom(), event->getMessageData());
			break;
		
			case(2):
				refreshRosterTree();
				changeStatusLabelsInChatWindows();
			break;
		}
	
	if(now % 15 == 0)
		::xmppClient->sendStatus();
	
	return( Pt_CONTINUE );
}


int
sendMessage( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	PtWidget_t *activeChatWindow = widget->parent->parent;
	PtWidget_t *mtMessageEdit = ApGetWidgetPtr(activeChatWindow, ABN_mtMessageEdit);
	
	if(getWidgetUserData(mtMessageEdit))
	{
		sendMessageFromMTWidget(activeChatWindow);
		displayMyMessage(activeChatWindow);
		appendMessageToHistory(activeChatWindow);
		clearMTWidget(activeChatWindow);
	}

	return( Pt_CONTINUE );
}


int
focusMessage( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	PtWidget_t *activeChatWindow = widget->parent->parent;
	PtWidget_t *mtMessageEdit = ApGetWidgetPtr(activeChatWindow, ABN_mtMessageEdit);
	
	PtArg_t arg[2];
	PtSetArg(&arg[0], Pt_ARG_BOT_BORDER_COLOR, PgRGB(255, 255, 255), 0);
	PtSetArg(&arg[1], Pt_ARG_TOP_BORDER_COLOR, PgRGB(96, 96, 96), 0);
	PtSetResources(mtMessageEdit, 2, arg);
	
	setWidgetUserData(mtMessageEdit, WIDGET_GOT_FOCUS);
	
	return( Pt_CONTINUE );
}


int
unfocusMessage( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	PtWidget_t *activeChatWindow = widget->parent->parent;
	PtWidget_t *mtMessageEdit = ApGetWidgetPtr(activeChatWindow, ABN_mtMessageEdit);

	setWidgetUserData(mtMessageEdit, WIDGET_LOST_FOCUS);

	return( Pt_CONTINUE );
}


int
comboBoxClose( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	int status = getSelectedCBoxItem(ABW_cboxStatus) - 1;
	
	changeStatusLabel(ABW_lbMyStatusImage, status, SIZE_22);
	::xmppClient->setStatus(status);
	::xmppClient->sendStatus();
	PtDamageWidget(widget);
	
	return( Pt_CONTINUE );
}


int
closeChatWindow( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	JidWidget jidWidget(getWidgetUserData(widget), NULL);
	chatWindows.remove(&jidWidget);

	return( Pt_CONTINUE );
}

int
clearChatWindow( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	return( Pt_CONTINUE );
}

