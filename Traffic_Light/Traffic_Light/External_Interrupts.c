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
 *  PORTE.4 - Interrupt input from crosswalk button
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "External_Interrupts.h"



void interrupt_init(void)
{
	
	DDRE = DDRE & ~(1<<PE4);		// Port E.4 for interrupt input from crosswalk button (interrupt 4)
	PORTE = PORTE | (1<<PE4);		// Port E.4 enable pull-up resistor
	
	EICRB = EICRB | (1<<ISC41) | (1<<ISC40);		// External interrupt 4 for falling edge on DT

}

ISR(INT4_vect)
{
	
	ped_status = 1;
	
}