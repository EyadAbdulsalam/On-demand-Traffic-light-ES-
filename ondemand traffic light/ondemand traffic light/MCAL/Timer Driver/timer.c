/*
 * timer.c
 *
 *  Author: Eyad Hossam
 */ 
#include "timer.h"


void Set_timer(){
	  TCCR0=0x00;                           // normal mode
	  TCNT0=0x00;                           // set timer initial value
}

void Start_timer(uint16_t overFlowsNumber){
	uint16_t overFlowCounter=0;
	TCCR0 |=(1<<0);                         //Timer start
	while(overFlowCounter<overFlowsNumber){
		while((TIFR & (1<<0))==0);          // while there is no over flow
		TIFR |=(1<<0);                      //clear flag
		overFlowCounter++;
	}
}
void Timer_stop(){
	TCCR0 =0x00;
}
