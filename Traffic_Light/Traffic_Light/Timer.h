/*
 * Project Name: Traffic Light
 *
 * Filename: Timer.h
 *
 * Author: Joshua Liang
 *
 * Created: 1/31/2026 21:04:00
 *
 * Description: This is where the timer functions are declared.
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
void off(void);

#endif /* TIMER_H_ */