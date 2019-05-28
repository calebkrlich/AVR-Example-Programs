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

uint8_t programRunning = 0;
uint8_t inProgram = 0;



void displayOptions(void)
{
	transmitString("1 : Blinky\n");
	transmitString("2 : Cycle\n");
	transmitString("3 : Exit\n");
}


int main(void)
{
	initUART();
	initBlink();

	char received;
	char lastReceived;
	
	/*
	transmitString("Welcome to my Simple OS \n");
	transmitString("By: Caleb Krlich \n \n");
	transmitString("For Options: 1 to Exit System: 2 \n");
	*/

	while (1) 
    {
		while(inProgram == 1)	//if we are running a program
		{
			transmitString("Executing Program...");

			if(programRunning == 1)
			{
				setBank(255);
				_delay_ms(1000);
				setBank(0);
				_delay_ms(1000);

			}
			if(programRunning == 2)
			{
				setBank(255);
				_delay_ms(100);
				setBank(0);
				_delay_ms(100);
			}
		}


		transmitString("Welcome to my Simple OS \n");
		transmitString("By: Caleb Krlich \n \n");
		transmitString("For Options: 1 to Exit System: 2 \n");



		while(1)	//waiting for program to run
		{
			received = receive();

			if(inOption == 1)
			{
				if((received - 48) == 1)
				{
					inProgram = 1;
					programRunning = 1;
					break;
				}
				if((received - 48) == 2)
				{
					inProgram = 1;
					programRunning = 2;
					break;
				}

				if((received - 48) == 3)
				{
					transmitString("Returning...\n");
					inOption = 0;
					break;
				}
				else
				{
					transmitString("Invalid Option...\n");
				}
			}

			if(inOption == 0)
			{
				if((received - 48) == 1)	//if call for system options...
				{
					transmitString("\n Displaying options... \n");
					displayOptions();
					inOption = 1;
				}
				else if((received - 48) == 2)	//if call for exit system...
				{
					transmitString("System powering down...\n");
					break;
				}
				else
				{
					transmitString("Not Valid Option...\n");
				}
			}


		}
	}
}

