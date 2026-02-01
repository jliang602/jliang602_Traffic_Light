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
 *  PORTE.3 for OCR3A PWM signal output
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
	
	
	
	// ----- Timer 3 (Normal Mode) -----
	TCCR3A = TCCR3A | 0x00;		// Set waveform generation mode
	
	TCCR3B = TCCR3B | 0x00;		// Timer shouldn't be active
	// ----------
	
	
	
}