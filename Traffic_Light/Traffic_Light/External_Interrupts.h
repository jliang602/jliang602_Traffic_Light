/*
 * Project Name: Interrupts
 *
 * Filename: External_Interrupts.h
 *
 * Author: Joshua Liang
 *
 * Created: 10/10/2024 10:39:44 AM
 *
 * Description: Two declarations of functions are needed, one for initialization and another for the function to control the LED bar when the encoder is turned. Two variables determine each different direction of the encoder and another determines exactly which LED on the LED bar turns on or off or whether nothing should happen if all LEDs on the bar are on or off.
 */ 


#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

// ----- Declaration of Functions -----
void interrupt_init(void);
void interrupt_counter(void);

// ----- Declaration of Variables -----
volatile uint8_t CW_direction;
volatile uint8_t CCW_direction;
volatile uint8_t LED_sequence;

#endif /* EXTERNAL_INTERRUPTS_H_ */