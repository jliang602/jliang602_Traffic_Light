/*
 * Project Name: Traffic Light
 *
 * Filename: main.c
 *
 * Author: Joshua Liang
 *
 * Created: 1/31/2026 19:22:46
 *
 * Description: This is the main code that controls the traffic light and pedestrian signal.
 *
 * Hardware Input:
 *  PORTL.0 for push button
 *
 * Hardware Output:
 *  PORTA.0 for traffic light red
 *  PORTA.1 for traffic light yellow
 *	PORTA.2 for traffic light green
 */ 



#define F_CPU 16000000UL



// ----- Includes -----
#include <avr/io.h>
#include <avr/interrupt.h>
#include "External_Interrupts.h"
#include "Timer.h"



// ----- Defines -----
#define red_light			0x01
#define yellow_light		0x02
#define green_light			0x04



// ----- Declare functions -----
void ports_init(void);



// ----- Global variables -----
volatile uint8_t ped_status;



int main(void)
{
	
	
	
	// ----- Initializations -----
	interrupt_init();		// Initialize interrupts
	timers_init();		// Initialize timers
	ports_init();		// Initialize ports
	
	
	
	// ----- Starting states -----
	EIMSK = EIMSK | (1<<INT4);		// Enable interrupt 4
	PORTA = green_light;		// Green light
	dont_walk_signal();		// Don't walk signal
	ped_status = 0;
	
	
	
    while (1)
    {
			
		
		
		if (ped_status)		// Crosswalk button has been pressed
		{
			
			delay_in_ms(1000);		// Wait 1 second
			
			PORTA = yellow_light;		// Yellow light
			delay_in_ms(4000);		// Wait 4 seconds
			
			PORTA = red_light;		// Red light
			delay_in_ms(2000);		// Wait 2 seconds
			
			walk_signal();		// Walk signal
			ped_status = 0;		// Reset crosswalk button status
			EIMSK = EIMSK & ~(1<<INT4);		// Disable interrupt 4
			delay_in_ms(5000);		// Wait 5 seconds
			EIMSK = EIMSK | (1<<INT4);		// Enable interrupt 4
			
			for (uint8_t i = 1; i <= 9; i++)		// Flash don't walk signal
			{
				
				dont_walk_signal();
				delay_in_ms(500);
				off();
				delay_in_ms(500);
				
			}
			
			dont_walk_signal();		// Steady don't walk signal
			delay_in_ms(2000);		// Wait 2 seconds
			
			PORTA = green_light;		// Green light
			
			delay_in_ms(10000);		// Cooldown for 10 seconds
			
		}
		
		
		
    }
}



void ports_init(void)
{
	
	 DDRA = DDRA | (1<<PA2) | (1<<PA1) | (1<<PA0);		// Ports A.0, A.1, and A.2 as output to control traffic light
	 PORTA = PORTA & ~((1<<PA2) | (1<<PA1) | (1<<PA0));		// Ports A.0, A.1, and A.2 initial state
	 
}
