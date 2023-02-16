/*
 * GccApplication6.c
 *
 * Created: 11/10/2022 06:28:22 م
 * Author : Pc
 */ 

/*#include "MCAL/DIO/DI0_interface.h"
#include "MCAL/Timer/timer.h"
#include "ECUAL/Led/Led_interface.h"
#include "ECUAL/SevenSegment/Seven_seg_interface.h"*/
#include "MCAL/DIO/DI0_interface.h"
#include "MCAL/Timer/timer.h"
#include "ECUAL/Button/button_interface.h"
//#include "ECUAL/LCD/LCD_Interface.h"
#include "Application/assignments.h"
#include "util/delay.h"


int main(void)
{
	
	Control_2Mltiplexed_7Seg_usingTwoPush();
}	
