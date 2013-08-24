/*
 * bike_pov.c
 *
 * Created: 8/24/2013 5:47 PM
 *  Author: mruha
 */
#ifndef _BIKE_POV_2_0_INTERRUPT_C_
#define _BIKE_POV_2_0_INTERRUPT_C_

#include <avr/io.h>
#include <avr/interrupt.h>

/****************************************************************************************************************
 *function:
 *	ISR(INT2_vect)
 *arguments:
 *	none
 *return value:
 *	none
 *comment:
 *	ISR for hall sensor
 */
ISR(INT2_vect)
{

}

/****************************************************************************************************************
 *function:
 *	ISR(TIMER1_COMPA_vect)
 *arguments:
 *	none
 *return value:
 *	none
 *comment:
 *	ISR for counter1 compare match
 */
ISR(TIMER1_COMPA_vect)
{	

}

#undef _BIKE_POV_2_0_INTERRUPT_C_
#endif
