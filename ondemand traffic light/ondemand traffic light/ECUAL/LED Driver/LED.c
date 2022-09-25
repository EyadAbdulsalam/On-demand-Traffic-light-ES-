/*
 * LED.c
 *
 *  Author: Eyad Hossam
 */ 
#include "LED.h"

void LED_init(uint8_t ledPort,uint8_t ledpin)              
{
	DIO_init(ledPort,ledpin,OUT);                             //initialize led in as an output pin -using DIO APIs-
}
void LED_on(uint8_t ledPort,uint8_t ledpin)
{
	DIO_write(ledPort,ledpin,HIGH);							  //Turn on led -using DIO APIs- by writing high on its pin
}
void LED_off(uint8_t ledPort,uint8_t ledpin)
{
	DIO_write(ledPort,ledpin,LOW);                            //Turn off led -using DIO APIs- by writing low on its pin
}
void LED_toggle(uint8_t ledPort,uint8_t ledpin)
{
	DIO_toggle(ledPort,ledpin);								  //Toggle led -using DIO APIs- by toggling its pin
}