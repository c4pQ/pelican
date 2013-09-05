#include <Ph.h>
#include <Pt.h>
#include <Ap.h>
#include "errno.h"
#include "string.h"
#include "common_func.h"

void ChColor(PtWidget_t *w,PgColor_t color)
{
	PtArg_t arg;
	PgColor_t currentColor;
	currentColor = ((PtBasicWidget_t*)w)->fill_color;
	if (currentColor!=color) {
		PtSetArg( &arg, Pt_ARG_FILL_COLOR, color, 0 );
		PtSetResources( w, 1, &arg );
	}
}

void ChTextColor(PtWidget_t *w,PgColor_t color)
{
	PtArg_t arg;
	PgColor_t currentColor;
	currentColor = ((PtBasicWidget_t*)w)->color;
	if (currentColor!=color) {
		PtSetArg( &arg, Pt_ARG_COLOR, color, 0 );
		PtSetResources( w, 1, &arg );
	}
}

void ChNumericColor(PtWidget_t *w,PgColor_t color)
{
	PtArg_t arg;
	PtSetArg( &arg, Pt_ARG_NUMERIC_TEXT_FILL_COLOR, color, 0 );
	PtSetResources( w, 1, &arg );
}

void ChNumericTextColor(PtWidget_t *w,PgColor_t color)
{
	PtArg_t arg;
	PtSetArg( &arg, Pt_ARG_NUMERIC_TEXT_COLOR, color, 0 );
	PtSetResources( w, 1, &arg );
}

void ChSetColor(PtWidget_t *w,PgColor_t color)
{
	PtArg_t arg;
	PtSetArg( &arg, Pt_ARG_SET_COLOR, color, 0 );
	PtSetResources( w, 1, &arg );
}

int CheckColor(PtWidget_t *w,PgColor_t color)
{
	int res = 0;
	PgColor_t currentColor;
	currentColor = ((PtBasicWidget_t*)w)->fill_color;
	if (currentColor!=color)
		res = 0;
	else
		res = 1;
	return res;
}

void ChText(PtWidget_t *w, char* text)
{
	PtArg_t arg;
	PtSetArg( &arg, Pt_ARG_TEXT_STRING, text, 0 );
	PtSetResources( w, 1, &arg );
}

void ChRealize(PtWidget_t *w)
{
    if (!(PtWidgetIsRealized ( w ))) PtRealizeWidget(w);
}

void ChUnRealize(PtWidget_t *w)
{
    if (PtWidgetIsRealized ( w )) PtUnrealizeWidget(w);
}

void ChPos(PtWidget_t *w, int x, int y)
{
	PhPoint_t pos;
	PtArg_t arg;
    pos.x = (short) x;
    pos.y = (short) y;
    PtSetArg( &arg, Pt_ARG_POS, &pos, 0 );
    PtSetResources( w, 1, &arg );
}

void ChLine(PtWidget_t *w, int x_beg, int y_beg, int x_end, int y_end)
{
	PtArg_t arg;
	PhPoint_t pos[2];
    pos[0].x = x_beg;
    pos[0].y = y_beg;
    pos[1].x = x_end;
    pos[1].y = y_end;
    PtSetArg( &arg, Pt_ARG_POINTS, pos, 2 );
    PtSetResources( w, 1, &arg );
}

void ChSetFlags (PtWidget_t *w, long flags, char state)
{
	PtArg_t arg;
    PtSetArg( &arg, Pt_ARG_FLAGS, state ? Pt_TRUE : 0, flags );
	PtSetResources( w, 1, &arg );
}

short CheckFlags (PtWidget_t *w, long flags)
{
	if ((w->flags & flags) == flags)
		return 1;
	else
		return 0;
}


const char *GetString( PtWidget_t *w)
{
    PtArg_t arg;

	if( PtWidgetIsClassMember( w, PtNumeric ))
		w = ((PtNumericWidget_t*) w)->text_wgt;

	PtSetArg( &arg, Pt_ARG_TEXT_STRING, 0, 0 );
	PtGetResources( w, 1, &arg );
	return (char*) arg.value;
}
/*
void*	get_struct( PtWidget_t *widget, long type, void *str)	{
	PtArg_t arg;
	PtSetArg( &arg, type, str, 0);
	PtGetResources( widget, 1, &arg);
	return	str;
}
*/

double privAngle (double angle, double max)		// Функция приведения
{                                    			// угла к интервалу [0,max]
	int n = (angle / max);

	angle -= n * max;
	if( angle < 0 )
		angle += max;

	if( angle > max - 0.0001 )
		angle = 0;

	return angle;
}


double priv360 (double angle)               // Функция приведения
{                                    // угла к интервалу [0,2PI]
	return privAngle( angle, M2_PI );
}


double priv180 (double angle)              // Функция приведения
{                                    // угла к интервалу [0,PI]
	return privAngle( angle, M_PI );
}

double PrivUgPi(double ALFA)
{
 if (ALFA > M_PI) return(ALFA = ALFA - 2.0*M_PI);
 if (ALFA < -M_PI) return(ALFA = ALFA + 2.0*M_PI);
 return ALFA;
}

float Priv2Pi(float ALFA)
{
 if ((ALFA > M_PI/2.0) && (ALFA < M_PI))
    return (5.0*M_PI/2.0 - ALFA);
 else
    return (M_PI/2.0 - ALFA);
}


float sign_1(float A)
{
 float sign_1A;
 if (A == 0.0) sign_1A= 0;
 if (A >  0.0) sign_1A= 1;
 if (A <  0.0) sign_1A=-1;
 return (sign_1A);
}


int GetNumericInt( PtWidget_t* wgt )
{
	PtArg_t arg;
	PtSetArg( &arg, Pt_ARG_NUMERIC_VALUE, 0, 0 );
	return !PtGetResources( wgt, 1, &arg ) ? arg.value : -1e9;
}


double GetNumericFloat( PtWidget_t* wgt )
{
	PtArg_t arg;
	PtSetArg( &arg, Pt_ARG_NUMERIC_VALUE, 0, 0 );
	return !PtGetResources( wgt, 1, &arg ) ? *((double*) arg.value) : -1e9;
}


int SetNumericInt( PtWidget_t* wgt, int val )
{
	if( !PtIsFocused( wgt )) {
		PtArg_t arg;
		PtSetArg( &arg, Pt_ARG_NUMERIC_VALUE, val, 0 );
		PtSetResources( wgt, 1, &arg );
	}
	
	return 0;
}


int SetNumericFloat( PtWidget_t* wgt, double val )
{
	if( !PtIsFocused( wgt )) {
		PtArg_t arg;
		PtSetArg( &arg, Pt_ARG_NUMERIC_VALUE, &val, 0 );
		PtSetResources( wgt, 1, &arg );
	}
	
	return 0;
}


int CBoxCurrentPos( PtWidget_t* wgt )
{
	PtArg_t arg;
	PtSetArg( &arg, Pt_ARG_CBOX_SEL_ITEM, 0, 0 );
	return !PtGetResources( wgt, 1, &arg ) ? arg.value : 0;
}


int CBoxSelectItem( PtWidget_t* wgt, int pos )
{
	PtArg_t arg;
	PtSetArg( &arg, Pt_ARG_CBOX_SEL_ITEM, pos, 0 );
	PtSetResources( wgt, 1, &arg );
	PtDamageWidget( wgt );	// fix redraw error
	return 0;
}


int SetBlock( PtWidget_t* wgt, int state )
{
	ChSetFlags( wgt,(Pt_GHOST|Pt_BLOCKED), state );
	return 0;
}


int CheckBlock( PtWidget_t* wgt )
{
	return CheckFlags( wgt, Pt_BLOCKED );
}


int ListAddItem( PtWidget_t* wgt, const char* item, int pos )
{
	return PtListAddItems( wgt, &item, 1, pos );
}


int ListItemPos( PtWidget_t* wgt, const char* item )
{
	return PtListItemPos( wgt, item );
}


int ListDeleteItem( PtWidget_t* wgt, int pos )
{
	return PtListDeleteItemPos( wgt, 1, pos );
}


int ListDeleteAll( PtWidget_t* wgt )
{
	return PtListDeleteAllItems( wgt );
}


int ListReplaceItem( PtWidget_t* wgt, const char* old_item, const char* new_item )
{
	return PtListReplaceItems( wgt, &old_item, &new_item, 1 );
}


void TimerSet( PtWidget_t *w, long initial, long period )
{
	int n = 0;
	PtArg_t args[2];
	if( initial != -1 )
		PtSetArg( &args[n++], Pt_ARG_TIMER_INITIAL, initial, 0 );
	if( period != -1 )
		PtSetArg( &args[n++], Pt_ARG_TIMER_REPEAT, period, 0 );

	if( n > 0 )
		PtSetResources( w, n, args );
}


const char* IntToString( int val )
{
	static char buf[10];
	return _itoa( val, buf, 10 );
}


const char* DoubleToString( double val )
{
	static char buf[16];
	return _gcvt( val, 5, buf );
}
