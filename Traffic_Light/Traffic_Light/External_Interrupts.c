/*
 * Project Name: Interrupts
 *
 * Filename: External_Interrupts.c
 *
 * Author: Joshua Liang
 *
 * Created: 10/10/2024 10:39:44 AM
 *
 * Description: Encoder inputs are initialized in this file. Direction of the encoder is checked and the corresponding LEDs on the LED bar are turned on or off. The interrupt to detect the falling edge on the encoder DT is declared here.
 *
 * Hardware Input:
 *  PORTA.0 - General purpose input for encoder CLK
 *  PORTD.2 - Interrupt input 2 for encoder DT
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "External_Interrupts.h"



void interrupt_init(void)
{
	
	DDRE = DDRE | (1<<PE4);		// Port E.4 for interrupt input (interrupt 4)
	PORTE = PORTE & (1<<PE4);		// Port E.4 enable pull-up resistor
	
	EICRB = EICRB | (1<<ISC41) | (1<<ISC40);		// External interrupt 4 for falling edge on DT

}

ISR(INT2_vect)
{
	
	if (PINA & 0x01)
	{
		CW_direction = 1;
	}
	
	else
	{
		CCW_direction = 1;
	}
	
}