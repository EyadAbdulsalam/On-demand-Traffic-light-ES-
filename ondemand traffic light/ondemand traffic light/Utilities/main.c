/*
 * main.c
 *
 * Author : Eyad Hossam
 */ 
#include "../MCAL/DIO driver/DIO.h"
#include "../ECUAL/LED Driver/LED.h"
#include "../ECUAL/Button Driver/button.h"
#include "../MCAL/Interrupts/interrupts.h"
#include "../MCAL/Timer Driver/timer.h"
#include "../Application/application.h"
#include "test_module.h"

int main(void)
{
  
  appStart();
  //sei();                               // INTURRUPTs driver test 
  //enable_extint(INT0);             
  //enable_extint(INT1);
  //enable_extint(INT2);
  //INT0_Sense(rising_Edge);
  //INT1_Sense(logical_change);
  //INT2_Sense(falling_Edge);
 // while(1) test();
}

ISR(INT0vect)
{
	flag|=(1<<0);
}

//ISR(INT1vect)
//{
	//flag^=(1<<0);
//}
//
//ISR(INT2vect)
//{
	//flag^=(1<<0);
//}