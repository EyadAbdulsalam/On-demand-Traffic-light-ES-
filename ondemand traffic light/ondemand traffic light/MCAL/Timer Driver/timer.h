/*
 * timer.h
 *
 *  Author: Eyad HOSSAM
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../Utilities/registers.h"

void Set_timer();
void Start_timer(uint16_t overFlows_N);
void Timer_stop();


#endif /* TIMER_H_ */