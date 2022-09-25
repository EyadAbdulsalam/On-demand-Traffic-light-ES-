/*
 * button.h
 *
 *  Author: Eyad Hossam
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO driver/DIO.h"

void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t* value);


#endif /* BUTTON_H_ */