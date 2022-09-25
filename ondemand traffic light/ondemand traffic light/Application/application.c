/*
 * application.c
 *
 *  Author: EYAD HOSSAM
 */ 

#define delay 19531                            //overflows =5/(256/10e+6)=19531 
#include "application.h"
uint8_t Blink=0;
uint8_t flag=0;
void appStart(void)
{
	LED_init(PORT_A,Green);
	LED_init(PORT_A,yellow);
	LED_init(PORT_A,Red);
	LED_init(PORT_B,Green);
	LED_init(PORT_B,yellow);
	LED_init(PORT_B,Red);
	sei();
	enable_extint(INT0);
	Set_timer();
	INT0_Sense(falling_Edge);
	flag=0;
	while(1)
	{
		carGreen();                       //1.cars' green turn on  
		
		while(carYellow())                //2.cars' yellow blink
		{                                 //if pedestrian mode doesn't happen loop wouldn't take effect (yellow then red) 
			carYellow();                  //if pedestrian mode does happen loop would take effect  (last step in pedestrian -> cars's green then yellow blink in normal mode)
		}
		
		while (carRED())                 //3.cars' red turn on 
		{								 //if pedestrian mode doesn't happen loop wouldn't take effect (red then yellow)
				                         //if pedestrian mode does happen loop would take effect  (last step in pedestrian -> cars's green then yellow blink in normal mode)
			carYellow();
		}
		
		carYellow();                     //4. yellow blink again then loop repeat
	}

}



void carGreen(void)
{
	/************************************************************************/
	/*                        CAR's Green-Light is ON                       */
	/************************************************************************/
	flag=0;
	LED_on(PORT_A,Green);
	Blink=0;
	while (Blink<5)                                        //checks if button is pressed 5 times
	{
		Start_timer(delay/5);
		if (flag==1)
		{                                                   //Button is pressed      ""Pedestrian-Mode""
			LED_on(PORT_B,Red);                             //1.turn on pedestrians'  ""RED-Light""
			Start_timer(delay);                 //NOTE: can be set to reminder or to restart counting
			LED_off(PORT_A,Green);
			LED_off(PORT_B,Red);
			
			Blink=0;
			while(Blink<5)                                  //2.Blink Yellow light on both
			{
				LED_toggle(PORT_A,yellow);
				LED_toggle(PORT_B,yellow);
				Start_timer(delay/5);
				Blink++;
			}
			LED_off(PORT_A,yellow);
			LED_off(PORT_B,yellow);
			
			LED_on(PORT_A,Red);                            //3.Turns on cars' "RED" and pedestrian "GREEN" for 5sec
			LED_on(PORT_B,Green);
			Start_timer(delay);
			
			LED_off(PORT_A,Red);                           //4.turn off Cars' "RED" and Blink both "Yellow" for 5sec
			Blink=0;
			while(Blink<5)
			{
				LED_toggle(PORT_A,yellow);
				LED_toggle(PORT_B,yellow);
				Start_timer(delay/5);
				Blink++;
			}
			
			LED_off(PORT_B,yellow);                         //5.Turn off both "yellow", turn off pedestrian "Green" and Cars' "Red"
			LED_off(PORT_A,yellow);
			LED_off(PORT_B,Green);
			LED_off(PORT_A,Red);
			
			LED_on(PORT_B,Red);                             //6.Turn on pedestrian "Red" and Cars' "Green" for 5sec
			LED_on(PORT_A,Green);
			Start_timer(delay);
			
			LED_off(PORT_B,Red);                           //7. turn off pedestrian "RED"
			flag=0;
			break;
		}
		Blink++;
	}
	
	LED_off(PORT_A,Green);
	////////////////////////////////////////////////////////////////////////////
}

char carRED(void)
{
	/************************************************************************/
	/*                       CARS' RED-Light is ON                          */
	/************************************************************************/
	flag=0;
	LED_on(PORT_A,Red);
	Blink=0;
	while (Blink<5)
	{
		Start_timer(delay/5);
		if (flag==1){
			LED_on(PORT_B,Green);
			Start_timer(delay);
			LED_off(PORT_A,Red);
			
			Blink=0;
			while(Blink<5)                                  //2.Blink Yellow light on both
			{
				LED_toggle(PORT_A,yellow);
				LED_toggle(PORT_B,yellow);
				Start_timer(delay/5);
				Blink++;
			}
			LED_off(PORT_A,yellow);
			LED_off(PORT_B,yellow);
			LED_off(PORT_B,Green);
			
			LED_on(PORT_B,Red);
			LED_on(PORT_A,Green);
			Start_timer(delay);
			LED_off(PORT_B,Red);
			LED_off(PORT_A,Green);
			
			flag=0;
			return 1;
		}
		Blink++;
	}
	LED_off(PORT_A,Red);
	return 0;
	/////////////////////////////////////////////////////////////////////////////
}

char carYellow(void)
{
	/************************************************************************/
	/*                         CAR's Yellow-Light is ON                     */
	/************************************************************************/
	flag=0;
	Blink=0;
	while(Blink<5)
	{
		LED_toggle(PORT_A,yellow);
		Start_timer(delay/5);
		if (flag==1)
		{                                                   //Button is pressed      ""Pedestrian-Mode""
			LED_on(PORT_B,Red);                             //1.turn on pedestrians'  ""RED-Light""
			Blink=0;
			while(Blink<5)
			{
				LED_toggle(PORT_A,yellow);
				Start_timer(delay/5);                 //NOTE: can be set to reminder or to restart counting
				Blink++;
			}
			LED_off(PORT_A,yellow);
			LED_off(PORT_B,Red);
			
			Blink=0;
			while(Blink<5)                                  //2.Blink Yellow light on both
			{
				LED_toggle(PORT_A,yellow);
				LED_toggle(PORT_B,yellow);
				Start_timer(delay/5);
				Blink++;
			}
			LED_off(PORT_A,yellow);
			LED_off(PORT_B,yellow);
			
			LED_on(PORT_A,Red);                            //3.Turns on cars' "RED" and pedestrian "GREEN" for 5sec
			LED_on(PORT_B,Green);
			Start_timer(delay);
			
			LED_off(PORT_A,Red);                           //4.turn off Cars' "RED" and Blink both "Yellow" for 5sec
			Blink=0;
			while(Blink<5)
			{
				LED_toggle(PORT_A,yellow);
				LED_toggle(PORT_B,yellow);
				Start_timer(delay/5);
				Blink++;
			}
			
			LED_off(PORT_B,yellow);                         //5.Turn off both "yellow", turn off pedestrian "Green" and Cars' "Red"
			LED_off(PORT_A,yellow);
			LED_off(PORT_B,Green);
			LED_off(PORT_A,Red);
			
			LED_on(PORT_B,Red);                             //6.Turn on pedestrian "Red" and Cars' "Green" for 5sec
			LED_on(PORT_A,Green);
			Start_timer(delay);
			LED_off(PORT_A,Green);
			
			LED_off(PORT_B,Red);                           //7. turn off pedestrian "RED"
			flag=0;
			
			return 1;
		}
		Blink++;
	}
	
	LED_off(PORT_A,yellow);
	return 0;
	/////////////////////////////////////////////////////////////////////////////
}