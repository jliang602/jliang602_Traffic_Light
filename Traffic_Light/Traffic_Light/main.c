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
 *  PORTG.0 for red light on multicolor LED
 *  PORTG.1 for green light on multicolor LED
 *	PORTG.2 for blue light on multicolor LED
 */ 



// ----- Includes -----
#include <avr/io.h>
#include "Timer.h"



// ----- Defines -----
#define red_light					0x01
#define yellow_light				0x02
#define green_light					0x04
#define dont_walk_signal			0x03		
#define walk_signal					0x07



int main(void)
{
	
	
	
    // ----- Initialize Ports -----
	DDRA = DDRA | (1<<PA2) | (1<<PA1) | (1<<PA0);		// Ports A.0, A.1, and A.2 as output to control traffic light
	PORTA = PORTA & ~((1<<PA2) | (1<<PA1) | (1<<PA0));		// Ports A.0, A.1, and A.2 initial state
	
	DDRG = DDRG | (1<<PG2) | (1<<PG1) | (1<<PG0);		// Ports G.0, G.1, and G.2 as output to control crosswalk signal
	PORTG = PORTG & ~((1<<PG2) | (1<<PG1) | (1<<PG0));		// Ports A.0, A.1, and A.2 initial state
	
	
	
    while (1)
    {
		
		PORTA = green_light;
		PORTG = dont_walk_signal;
		delay_in_ms(10000);
		PORTA = yellow_light;
		delay_in_ms(4000);
		PORTA = red_light;
		delay_in_ms(2000);
		PORTG = walk_signal;
		delay_in_ms(5000);
		for (uint8_t i = 1; i <= 10; i++)
		{
			PORTG = dont_walk_signal;
			delay_in_ms(500);
			PORTG = 0x00;
			delay_in_ms(500);
		}
		PORTG = dont_walk_signal;
		delay_in_ms(2000);
		
    }
}

