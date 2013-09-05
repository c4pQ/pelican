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
#include "abimport.h"
#include "proto.h"
#include "common.h"

int
openNodesControlFromMenu( PtWidget_t *link_instance, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	// eliminate 'unreferenced' warnings
	link_instance = link_instance, apinfo = apinfo, cbinfo = cbinfo;

	refreshNodesList();
		
	return( Pt_CONTINUE );
}

int
btAddNodeSetup( PtWidget_t *link_instance, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	link_instance = link_instance, apinfo = apinfo, cbinfo = cbinfo;

	setWidgetText(ABW_btAddWAddNode, uutf8("Добавить"));
	setWidgetFlags(ABW_btAddWAddNode, Pt_BLOCKED, FLAG_ON);
	setWidgetUserData(ABW_btAddWAddNode, NODE_ADD_STR);

	return( Pt_CONTINUE );
}


int
btEditNodeSetup( PtWidget_t *link_instance, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	link_instance = link_instance, apinfo = apinfo, cbinfo = cbinfo;

	setWidgetText(ABW_btAddWAddNode, uutf8("Изменить"));
	setWidgetUserData(ABW_btAddWAddNode, NODE_EDIT_STR);
	fillWAddNodeFields();
	::nodesVector->setSelectedNodeEditingNode();
	
	return( Pt_CONTINUE );
}


int
loadChatHistory( PtWidget_t *link_instance, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	link_instance = link_instance, apinfo = apinfo, cbinfo = cbinfo;

	return( Pt_CONTINUE );
}

