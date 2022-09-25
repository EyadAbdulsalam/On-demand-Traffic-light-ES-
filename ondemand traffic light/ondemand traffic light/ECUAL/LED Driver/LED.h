/*
 * LED.h
 *
 *  Author: Eyad Hossam
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO driver/DIO.h"

void LED_init(uint8_t ledPort,uint8_t ledpin);
void LED_on(uint8_t ledPort,uint8_t ledpin);
void LED_off(uint8_t ledPort,uint8_t ledpin);
void LED_toggle(uint8_t ledPort,uint8_t ledpin);

#endif /* LED_H_ */