/*
 * Project Name: PWM and ADC
 *
 * Filename: Timer.h
 *
 * Author: Joshua Liang
 *
 * Created: 9/20/2024 2:01:24 PM
 *
 * Description: In this header file for the timer module, the only sections needed are the header and function declarations that the module needs.
 */


#ifndef TIMER_H_
#define TIMER_H_

#define F_CPU 16000000UL
#include <avr/io.h>

// ----- Declaration of Functions -----
void delay_in_ms(uint16_t time_in_ms);
void timers_init(void);
void walk_signal(void);
void dont_walk_signal(void);

#endif /* TIMER_H_ */