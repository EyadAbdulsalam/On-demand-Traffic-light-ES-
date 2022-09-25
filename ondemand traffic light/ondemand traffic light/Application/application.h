/*
 * application.h
 *
 *  Author: Eyad Hossam
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../Utilities/registers.h"
#include "../MCAL/interrupts/interrupts.h"
#include "../MCAL/Timer Driver/timer.h"
#include "../ECUAL/Button Driver/button.h"
#include "../ECUAL/LED Driver/LED.h"

extern uint8_t flag;
#define Green 0
#define yellow 1
#define  Red 2

void appStart(void);
void carGreen(void);
char carRED(void);                  //returns if it had entered pedestrian mode
char carYellow(void);

#endif /* APPLICATION_H_ */