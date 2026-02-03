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



// ----- Includes -----
#include <avr/io.h>
#include "Timer.h"



// ----- Defines -----
#define red_light			0x01
#define yellow_light		0x02
#define green_light			0x04



int main(void)
{
	
	
	
	timers_init();
	
    // ----- Initialize Ports -----
	DDRA = DDRA | (1<<PA2) | (1<<PA1) | (1<<PA0);		// Ports A.0, A.1, and A.2 as output to control traffic light
	PORTA = PORTA & ~((1<<PA2) | (1<<PA1) | (1<<PA0));		// Ports A.0, A.1, and A.2 initial state

	
	
	
    while (1)
    {
		
		PORTA = green_light;
		dont_walk_signal();
		delay_in_ms(10000);
		PORTA = yellow_light;
		delay_in_ms(4000);
		PORTA = red_light;
		delay_in_ms(2000);
		walk_signal();
		delay_in_ms(5000);
		for (uint8_t i = 1; i <= 10; i++)
		{
			dont_walk_signal();
			delay_in_ms(500);
			off();
			delay_in_ms(500);
		}
		delay_in_ms(2000);
		
    }
}

