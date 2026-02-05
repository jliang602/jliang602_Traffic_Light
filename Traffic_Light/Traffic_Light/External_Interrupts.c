/*
 * Project Name: Traffic Light
 *
 * Filename: External_Interrupts.c
 *
 * Author: Joshua Liang
 *
 * Created:
 *
 * Description:
 *
 * Hardware Input:
 *  PORTD.0 - Interrupt 0 input from crosswalk button
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "External_Interrupts.h"



void interrupt_init(void)
{
	
	DDRD = DDRD & ~(1<<PD0);		// Port E.4 for interrupt input from crosswalk button (interrupt 4)
	PORTD = PORTD | (1<<PD0);		// Port E.4 enable pull-up resistor
	
	EICRA = EICRA | (1<<ISC01);		// External interrupt 0 for falling edge on DT

}