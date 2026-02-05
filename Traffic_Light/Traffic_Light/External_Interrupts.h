/*
 * Project Name: Traffic Light
 *
 * Filename: External_Interrupts.h
 *
 * Author: Joshua Liang
 *
 * Created:
 *
 * Description:
 */ 


#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

// ----- Declaration of Functions -----
void interrupt_init(void);

// ----- Declaration of Variables -----
volatile uint8_t ped_status;

#endif /* EXTERNAL_INTERRUPTS_H_ */