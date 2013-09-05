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

XmppClient *xmppClient = new XmppClient();
ClientNodesVector *nodesVector = new ClientNodesVector();
WCPtrSkipListSet<JidWidget> chatWindows;
const PhImage_t* images[14] = {NULL};

int
setup( PtWidget_t *link_instance, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	link_instance = link_instance, apinfo = apinfo, cbinfo = cbinfo;
	ClientNode *node = NULL;
	ApDBase_t* pIconBase = NULL;

	pIconBase = ApOpenDBase(ABM_iconSet);
	if(pIconBase) {
		images[0] = ApGetImageRes(pIconBase, "available11W" );
		images[1] = ApGetImageRes(pIconBase, "away11W" );
		images[2] = ApGetImageRes(pIconBase, "busy11W" );
		images[3] = ApGetImageRes(pIconBase, "offline11W" );
		images[4] = ApGetImageRes(pIconBase, "unknown11" );
		images[5] = ApGetImageRes(pIconBase, "available22" );
		images[6] = ApGetImageRes(pIconBase, "away22" );
		images[7] = ApGetImageRes(pIconBase, "busy22" );
		images[8] = ApGetImageRes(pIconBase, "offline22" );
		images[9] = ApGetImageRes(pIconBase, "available32" );
		images[10] = ApGetImageRes(pIconBase, "away32" );
		images[11] = ApGetImageRes(pIconBase, "busy32" );
		images[12] = ApGetImageRes(pIconBase, "offline32" );
		images[13] = ApGetImageRes(pIconBase, "unknown" );
	}	
	for(int i = 0; i < STATUS_N; i++)
		PtTreeAddImages(ABW_trRoster, images[i], 1);

	::nodesVector->init();
	node = ::nodesVector->getActiveNode();
	
	::xmppClient->setLogin(node->getLogin());
	::xmppClient->setPassword(node->getPassword());
	::xmppClient->setServerDomain(node->getDomain());
	::xmppClient->setServerAddress(node->getServer());
	::xmppClient->connectXmppServer();
	::xmppClient->receiveRoster();

	::xmppClient->doForAllRosterElements(addEveryElementToTree, NULL);

	int s = ::xmppClient->getStatus();
	setSelectedCBoxItem(ABW_cboxStatus, ::xmppClient->getStatus() + 1);
	changeStatusLabel(ABW_lbMyStatusImage, ::xmppClient->getStatus(), SIZE_22);
	
	return( Pt_CONTINUE );
}

