/*
 * Project Name: PWM and ADC
 *
 * Filename: Timer.c
 *
 * Author: Joshua Liang
 *
 * Created: 9/20/2024 2:01:24 PM
 *
 * Description: The code to initialize the timers and ports for OCRnA/OCRnB/OCRnC are done in this module. This is also where a fixed 1 ms delay is implemented and then repeated multiple times to generate the desired delay. The total delay duration generated would be 1 ms times the desired delay in ms (total delay = 1 ms * desired delay in ms) by using a for loop to repeat the 1 ms delay as many times as needed.
 *
 * Hardware Input:
 *  None
 *
 * Hardware Output:
 *  PORTE.5 for red light on multicolor LED
 *  PORTE.6 for green light on multicolor LED
 *	PORTE.7 for blue light on multicolor LED
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "Timer.h"

// ----- Variables -----
uint8_t time_in_ms;

void delay_in_ms(uint16_t time_in_ms)
{

	for (uint16_t a = 1; a <= time_in_ms; a++)
	{
		
		TCNT0 = 6;		// Pre-load count to delay 1 ms with a clock pre-scale of 64
		TCCR0B = TCCR0B | (1<<CS31) | (1<<CS30);		// Pre-scale clock by 64 and start counting
		
		while (!(TIFR0 & (1<<TOV0)))		// Timer hasn't reached maximum
		{
			
		}
		
		TCCR0B = TCCR0B & ~( (1<<CS31) | (1<<CS30) );		// Stop counting
		
		TIFR0 = TIFR0 | (1<<TIFR0);		// Remove flag
		
	}

}

void timers_init(void)
{
	
	
	
	// ----- Timer 0 (Normal Mode) -----
	TCCR0A = TCCR0A | 0x00;		// Set waveform generation mode
	
	TCCR0B = TCCR0B | 0x00;		// Timer shouldn't be active
	// ----------
	
	
	
	// ----- Timer 1 (PWM, Phase Correct, 8-bit) -----
	DDRB = DDRB | (1<<PB7) | (1<<PB6) | (1<<PB5);		// Configure Port E.5, E.6, and E.7 for OC1A, OC1B, and OC1C outputs
	PORTB = DDRB & ~((1<<PB7) | (1<<PB6) | (1<<PB5));		// Ports E.5, E.6, and E.7 initial state
	
	TCCR1A = TCCR1A | (1<<WGM10);		// Set waveform generation mode
	
	TCCR1A = TCCR1A | (1<<COM1A1) | (1<<COM1A0) | (1<<COM1B1) | (1<<COM1B0) | (1<<COM1C1) | (1<<COM1C0);		// Set OC1A, OC1B, and OC1C on OCR values during up counting, clear all three on OCR values during down counting 
	
	TCCR1B = TCCR1B | (1<<CS11) | (1<<CS10);		// Pre-scale clock by 64 and start counting
	// ----------
	
	
	
}

void walk_signal(void)
{
	OCR1A = 127;
	OCR1B = 127;
	OCR1C = 127;
}

void dont_walk_signal(void)
{
	OCR1A = 127;
	OCR1B = 7;
	OCR1C = 0;
}

void off(void)
{
	OCR1A = 0;
	OCR1B = 0;
	OCR1C = 0;
}