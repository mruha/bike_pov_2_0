/*
 * bike_pov.c
 *
 * Created: 8/24/2013 5:45 PM
 *  Author: mruha
 */
#ifndef _BIKE_POV_2_0_INIT_C_
#define _BIKE_POV_2_0_INIT_C_

/****************************************************************************************************************
 *function:
 *	bike_pov_init
 *arguments:
 *	none
 *return value:
 *	none
 *comment:
 *	initializes hw and data before idle
 */

void bike_pov_2_0_init_all(void)
{
	/* init MCU HW */
	bike_pov_2_0_init_hw();
	
	/* init data structures */
	bike_pov_2_0_init_data();
}

/****************************************************************************************************************
 *function:
 *	bike_pov_hw_init
 *arguments:
 *	none
 *return value:
 *	none
 *comment:
 *	init hw
 */
void bike_pov_2_0_init_hw()
{
	// initialize ports
	DDRA |= 0b00001110;		// PIN3 = OE, PIN2 = LED_LE_B, PIN1 = LED_LE_A
	DDRB |= 0b10110010;		// PIN7 = SCK , PIN5 = MOSI, PIN4 = SS ,PIN1 = SS_SD_CARD
	DDRC |= 0b00010000;		// PIN4 = TDO
	
	PORTA |= (1 << 3);		// OE low active, disable with high signal
	PORTB |= (1 << 1);		// SS_SD_CARD low active
	
	// initialize interrupts
	MCUCR  &=	~(1 << ISC11) | \
				~(1 << ISC10) | \
				~(1 << ISC01) | \
				~(1 << ISC00);
				 
	MCUCSR &=  ~(1 << ISC2);	// falling edge => interrupt
	GICR   |=	(1 << INT1) | \
				(1 << INT0) | \
				(1 << INT2);	// enable external interrupts
	

	// initialize timer0
	TIMSK |= (1 << TOIE0);		// timer0 overflow interrupt
	
	// initialize timer1
	TCCR1B |= (1 << WGM12);		// CTC mode
	TIMSK  |= (1 << OCIE1A);	// output compare match interrupt enable
	
	// SPI setup
	SPCR	|=	(1 << MSTR);	// select CPU master mode
	SPSR	|=	(1 << SPI2X);	// SPI clk f_clk/2
}

/****************************************************************************************************************
 *function:
 *	bike_pov_data_init
 *arguments:
 *	none
 *return value:
 *	none
 *comment:
 *	init data for pov display
 */
void bike_pov_2_0_init_data()
{

}

#undef _BIKE_POV_2_0_INIT_C_
#endif
