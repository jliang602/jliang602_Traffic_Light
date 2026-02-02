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
 *  PORTA.0 for red light
 *  PORTA.1 for yellow light
 *	PORTA.2 for green light
 */ 



// ----- Includes -----
#include <avr/io.h>
#include "Timer.h"



// ----- Defines -----
#define red_light					0x01
#define yellow_light				0x02
#define green_light					0x04
#define dont_walk_signal		
#define walk_signal
#define signal_activated_flag		0x00



int main(void)
{
	
	
	
    // ----- Initialize Ports -----
	DDRA = DDRA | (1<<PA2) | (1<<PA1) | (1<<PA0);		// Ports A.0, A.1, and A.2 as output to control traffic light
	PORTA = PORTA & ~((1<<PA2) | (1<<PA1) | (1<<PA0));		// Ports A.0, A.1, and A.2 initial state
	
	
	
	PORTA = green_light;
	delay_in_ms(1000);
	PORTA = yellow_light;
	delay_in_ms(1000);
	PORTA = red_light;
	delay_in_ms(1000);
	
	
	
    while (1)
    {
		
		
		
    }
}

