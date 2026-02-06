/*
 * Project Name: Traffic Light
 *
 * Filename: External_Interrupts.c
 *
 * Author: Joshua Liang
 *
 * Created: 2/5/2026 9:29:41
 *
 * Description: This is the file that initializes the interrupt with the push button input.
 *
 * Hardware Input:
 *  PORTE.4 - Interrupt 4 input from crosswalk button
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "External_Interrupts.h"



void interrupt_init(void)
{
	
	DDRE = DDRE & ~(1<<PE4);		// Port E.4 for interrupt input from crosswalk button (interrupt 4)
	PORTE = PORTE | (1<<PE4);		// Port E.4 enable pull-up resistor
	
	EICRB = EICRB | (1<<ISC41);		// External interrupt 4 for falling edge on DT

}