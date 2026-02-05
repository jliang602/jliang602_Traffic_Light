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

void interrupt_counter(void)
{
	
	if (CW_direction == 1)		// CW direction detected
	{

		if (LED_sequence == 8)		// Maximum value should be 8
		{
			LED_sequence = 8;		// Hold at maximum for immediate incrementing
		}
		else
		{
			LED_sequence++;
		}

		PORTK = PORTK | (1 << (LED_sequence - 1));
		
		CW_direction = 0;		// Reset CW direction status
		
	}
	
	if (CCW_direction == 1)		// CCW direction detected
	{

		if (LED_sequence == 0)		// Minimum value should be 0
		{
			LED_sequence = 0;		// Hold at minimum for immediate incrementing
		}
		else
		{
			LED_sequence--;
		}
		
		PORTK = PORTK & ~(1 << LED_sequence);

		CCW_direction = 0;		// Reset CCW direction status
		
	}
	
}

void interrupt_init(void)
{
	
	DDRA = DDRA | 0x00;		// Set PORTA.0 for general purpose input
	PORTA = PORTA | 0x01;		// Enable PORTA.0 pull-up resistor
	
	DDRD = DDRD | 0x00;		// Set PORTD.2 for interrupt input 2
	PORTD = PORTD | 0x04;		// Enable PORTD.2 pull-up resistor
	
	EICRA = EICRA | (1<<ISC21);		// External interrupt 2 for falling edge on DT
	
	EIMSK = EIMSK | (1<<INT2);		// Enable interrupt 2

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