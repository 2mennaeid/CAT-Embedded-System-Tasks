/*
 * assignments.c
 *
 * Created: 09/02/2023 03:06:42 م
 *  Author: Menna Eid
 */ 
#include "../MCAL/DIO/DI0_interface.h"
#include "../MCAL/Timer/timer.h"
#include "../ECUAL/Led/Led_interface.h"
#include "../ECUAL/Button/button_interface.h"
#include "../ECUAL/SevenSegment/Seven_seg_interface.h"
#include "util/delay.h"

// Assignment 2

void Control_led_using_push()
{
	
	uint8_t value;
	led_init(PORT_A,PIN0);
	led_init(PORT_A,PIN1);
	Button_eninit(PORT_B,PIN0,PULL_UP);
	Button_eninit(PORT_B,PIN1,PULL_UP);
	Button_eninit(PORT_B,PIN2,PULL_UP);
	while(1)
	{
		
		if(Button_Getstate(PORT_B,PIN0,&value)&&value==0)
		{
			led_on(PORT_A,PIN0,source);
			led_of(PORT_A,PIN1,source);
		}
		else if(Button_Getstate(PORT_B,PIN1,&value)&&value==0)
		{
			led_on(PORT_A,PIN1,source);
			led_of(PORT_A,PIN0,source);
		}
		else if(Button_Getstate(PORT_B,PIN2,&value)&&value==0)
		{
			led_on(PORT_A,PIN1,source);
		}
		else
		{
			led_of(PORT_A,PIN0,source);
			led_of(PORT_A,PIN1,source);
		}
	}
}
void Control_7Seg_usingTwoPush()
{
	uint8_t _val;
	uint8_t i=0;
	Seven_Segment_enInit();
	Seven_Segment_enEnableCommon();
	Button_eninit(PORT_B,PIN0,PULL_UP);// PUSH1 for increase
	Button_eninit(PORT_B,PIN1,PULL_UP);// PUSH2 for decrease
	Seven_Segment_enDisplayNum(i);
	while(1)
	{
		
		
		if(Button_Getstate(PORT_B,PIN0,&_val)&&_val==0)
		{
			if(i>=9)
			{
				i=9;
				
			}
			else
			{
				
				++i;
				Seven_Segment_enDisplayNum(i);
				_delay();
			}
			
		}
		else if(Button_Getstate(PORT_B,PIN1,&_val)&&_val==0 )
		{
			if(i<=0)
			{
				i=0;
				
			}
			else
			{
				--i;
				Seven_Segment_enDisplayNum(i);
				_delay();
			}
			
			
		}		
		
	}
}
void Control_2Mltiplexed_7Seg_usingTwoPush()
{
	uint8_t NumDisplay []= {  0x3f, 0x06, 0x5B,
		0x4F, 0x66, 0x6D,
		0x7D, 0x07, 0x7F,
	0x6F};
	uint8_t i=5;
	uint8_t j=0;
	uint8_t val;
	uint8_t num = 49;
	Button_eninit(PORT_C,PIN0,PULL_UP); //push 1
	Button_eninit(PORT_C,PIN1,PULL_UP); // push2
	DIO_enSetPortDirection(PORT_A,0xff);
	DIO_SetPinDirection(PORT_B,PIN0,OUT);
	DIO_SetPinDirection(PORT_B,PIN1,OUT);
	// multiplexing
	DIO_SetPinValue(PORT_B,PIN0,HIGH);// dis common cathode b
	DIO_SetPinValue(PORT_B,PIN1,HIGH);// dis common cathode a
	
	
	while(1)
	{
		if(Button_Getstate(PORT_C,PIN0,&val)&&val==0)
		{
			++num;
			if(num>99)
			{
				num=50;
				i= num/10;
				j= num%10;
				DIO_SetPinValue(PORT_B,PIN0,HIGH);// dis common cathode b
				DIO_enSetPortValue(PORT_A,NumDisplay[j]);
				DIO_SetPinValue(PORT_B,PIN1,LOW);// EN common cathode a
				DIO_SetPinValue(PORT_B,PIN0,HIGH);// dis common cathode b
				_delay_ms(30);
				DIO_SetPinValue(PORT_B,PIN1,HIGH);// dis common cathode a
				DIO_enSetPortValue(PORT_A,NumDisplay[i]);
				DIO_SetPinValue(PORT_B,PIN0,LOW);// EN common cathode b
				_delay_ms(30);
				
			}
			else
			{
				i= num/10;
				j= num%10;
				DIO_SetPinValue(PORT_B,PIN0,HIGH);// dis common cathode b
				DIO_enSetPortValue(PORT_A,NumDisplay[j]);
				DIO_SetPinValue(PORT_B,PIN1,LOW);// EN common cathode a
				DIO_SetPinValue(PORT_B,PIN0,HIGH);// dis common cathode b
				_delay_ms(30);
				DIO_SetPinValue(PORT_B,PIN1,HIGH);// dis common cathode a
				DIO_enSetPortValue(PORT_A,NumDisplay[i]);
				DIO_SetPinValue(PORT_B,PIN0,LOW);// EN common cathode b
				_delay_ms(30);
			}
			
		}
		else if(Button_Getstate(PORT_C,PIN1,&val)&& val==0)
		{
			--num;
			if(num<0)
			{
				num=50;
				i= num/10;
				j= num%10;
				DIO_SetPinValue(PORT_B,PIN0,HIGH);// dis common cathode b
				DIO_enSetPortValue(PORT_A,NumDisplay[j]);
				DIO_SetPinValue(PORT_B,PIN1,LOW);// EN common cathode a
				DIO_SetPinValue(PORT_B,PIN0,HIGH);// dis common cathode b
				_delay_ms(30);
				DIO_SetPinValue(PORT_B,PIN1,HIGH);// dis common cathode a
				DIO_enSetPortValue(PORT_A,NumDisplay[i]);
				DIO_SetPinValue(PORT_B,PIN0,LOW);// EN common cathode b
				_delay_ms(30);
			}
			else
			{
				i= num/10;
				j= num%10;
				DIO_SetPinValue(PORT_B,PIN0,HIGH);// dis common cathode b
				DIO_enSetPortValue(PORT_A,NumDisplay[j]);
				DIO_SetPinValue(PORT_B,PIN1,LOW);// EN common cathode a
				DIO_SetPinValue(PORT_B,PIN0,HIGH);// dis common cathode b
				_delay_ms(30);
				DIO_SetPinValue(PORT_B,PIN1,HIGH);// dis common cathode a
				DIO_enSetPortValue(PORT_A,NumDisplay[i]);
				DIO_SetPinValue(PORT_B,PIN0,LOW);// EN common cathode b
				_delay_ms(30);
			}
			
		}
	}
}