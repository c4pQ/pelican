/* M a i n l i n e                                       */
/*                            AppBuilder Photon Code Lib */
/*                                         Version 1.14C */

#ifdef __USAGE
%C - This is a QNX/Photon Application.
%C [options]

Options:
  -s server   Server node or device name
  -x x        Initial x position
  -y y        Initial y position
  -h h        Initial h dimension
  -w w        Initial w dimension

Examples:
%C -s4
  Run using Photon server on node 4

%C -s//4/dev/photon
  Same as above

%C -x10 -y10 -h200 -w300
  Run at initial position 10,10 with initial 
  dimension of 200x300.
#endif

/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Toolkit headers */
#include <Ph.h>
#include <Pt.h>
#include <Ap.h>

/* Local headers */
#include "common.h"
#include "abimport.h"
#include "proto.h"
#include "abwidgets.h"
#include "ablinks.h"
#include "abdefine.h"
#include "abevents.h"
#include "abvars.h"

/* AppBuilder globals */
char		ab_exe_path[PATH_MAX];

static void ApClassInit( void );

int
main ( int argc, char *argv[] )

	{

	ab_winstate = 0;

	/* AppBuilder Initialization */
	ApInitialize( argc, argv );

	/* Setup class table used by this application */
	ApClassInit( );

	/* Display main window */
	ApLinkWindow( NULL, &appl_links[0], NULL );

	/* Loop until user quits application */
	PtMainLoop( );

	return 0;
	}

static void
ApClassInit( void )

	{

	ApAddClass( "PtWindow", &PtWindow );
	ApAddClass( "PtMenuBar", &PtMenuBar );
	ApAddClass( "PtMenuButton", &PtMenuButton );
	ApAddClass( "PtImageTree", &PtImageTree );
	ApAddClass( "PtComboBox", &PtComboBox );
	ApAddClass( "PtTimer", &PtTimer );
	ApAddClass( "PtGroup", &PtGroup );
	ApAddClass( "PtLabel", &PtLabel );
	ApAddClass( "PtMenu", &PtMenu );
	ApAddClass( "PtButton", &PtButton );
	ApAddClass( "PtList", &PtList );
	ApAddClass( "PtDivider", &PtDivider );
	ApAddClass( "PtPane", &PtPane );
	ApAddClass( "PtMultiText", &PtMultiText );
	ApAddClass( "PtToggleButton", &PtToggleButton );
	ApAddClass( "PtText", &PtText );
	ApAddClass( "PtBasic", &PtBasic );
	ApAddClass( "PtTab", &PtTab );
	ApAddClass( "PtIcon", &PtIcon );

	}
