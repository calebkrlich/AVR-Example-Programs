/*
 * SimpleOS.cpp
 *
 * Created: 5/26/2019 6:59:44 PM
 * Author : krlic
 */ 

 #include "define.h"
 #include "blink.c"
 #include "UART.c"

#include <avr/io.h>
#include <util/setbaud.h>
#include <util/delay.h>


uint8_t option = 0;
uint8_t inOption = 0;
uint8_t inProgram = 0;

int main(void)
{
	initUART();
	initBlink();

	char received;



    transmitString("Welcome to my Simple OS \n");
	transmitString("By: Caleb Krlich \n \n");
	transmitString("For Options: 1 to Exit System: 2 \n");
	
	while (1) 
    {
		if(inOption == 1)
		{
			transmitString("1 : Blinky\n");
			transmitString("2 : Cycle\n");
			transmitString("3 : Exit\n");

			received = receive();

			if((received - 48) == 3)
				inOption = 0;
		}
		else
		{
			received = receive();	//wait for input

			if((received - 48) == 1)	//if call for system options...
			{
				transmitString("\n Displaying options... \n");
				inOption = 1;
			}
			if((received - 48) == 2)	//if call for exit system...
			{
				transmitString("System powering down....");
			}
		}
	}
}

