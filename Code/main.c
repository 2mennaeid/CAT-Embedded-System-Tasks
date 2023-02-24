/*
 * GccApplication6.c
 *
 * Created: 11/10/2022 06:28:22 م
 * Author : Menna Eid
 */ 

#include "MCAL/DIO/Registers1.h"
#include "MCAL/DIO/DIO_priv.h"
#include "MCAL/DIO/errorstate.h"
#include "MCAL/DIO/DI0_interface.h"
#include "ECUAL/LCD/LCD_Interface.h"
#include "ECUAL/KeyPad/KETPAD_INTERFACE.h"
#include "Application/Calculator.h"
int main(void)
{

	LCD_enInit();
	KeyPad_u8Init();
	while(1)
	{
		
	     enCalculator();	
		
		
		
	}
	
}	
