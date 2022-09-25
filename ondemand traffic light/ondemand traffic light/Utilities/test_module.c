/*
 * test_module.c
 *
 *  Author: Eyad Hossam
 */ 


#include "test_module.h"


void test(void)
{
 /************************************************************************/
 /*                         DIO and LED test                             */
 /************************************************************************/	
	//for (uint8_t i=0;i<8;i++)                     
	//{
		//DIO_init(PORT_A,i,OUT);
		//DIO_init(PORT_B,i,OUT);
		//DIO_init(PORT_C,i,OUT);
		//DIO_init(PORT_D,i,OUT);
	//}
	//
	//for (uint8_t i=0;i<8;i++)
	//{
		//LED_on(PORT_A,i);
		//LED_on(PORT_B,i);
		//LED_on(PORT_C,i);
		//LED_on(PORT_D,i);
	//}
	//
	//for (uint8_t i=0;i<8;i++)
	//{
		//LED_off(PORT_A,i);
		//LED_off(PORT_B,i);
		//LED_off(PORT_C,i);
		//LED_off(PORT_D,i);
	//}
	//
	//for (uint8_t i=0;i<8;i++)
	//{
		//LED_toggle(PORT_A,i);
		//LED_toggle(PORT_B,i);
		//LED_toggle(PORT_C,i);
		//LED_toggle(PORT_D,i);
	//}
	/////////////////////////////////////////////////////////////////////
	//
	///************************************************************************/
	///*                        DIO and Buttons                               */
	///************************************************************************/
	//
	//for (uint8_t i=0;i<8;i++)
	//{
		//BUTTON_init(PORT_A,i);
		//BUTTON_init(PORT_B,i);
		//BUTTON_init(PORT_C,i);
		//BUTTON_init(PORT_D,i);
	//}
	//
	//uint8_t value=0;
		//for (uint8_t i=0;i<8;i++)
	//{
		//BUTTON_read(PORT_A,i,&value);
		//BUTTON_read(PORT_B,i,&value);
		//BUTTON_read(PORT_C,i,&value);
		//BUTTON_read(PORT_D,i,&value);
	//}
	
	/************************************************************************/
	/*                             Timer                                    */
	/************************************************************************/
		
		Set_timer();
		Start_timer(1953);        //time=1953*256/(10e+6) ~= 0.5 sec
		Timer_stop();
	/************************************************************************/
	/*                          INTURRUPTS                                  */
	/************************************************************************/
	
	
	
}
