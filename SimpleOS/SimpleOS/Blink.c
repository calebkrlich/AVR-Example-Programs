/*
 *
 * Created: 5/28/2019 2:14:51 PM
 *  Author: krlic
 */ 

 /*
	Sets up pins for running blinky program and 
 */

 #include "avr/io.h"
 #include "define.h"

 void initBlink(void)
 {
	DDRC = 0x3F;	//sets pins 0 -> 6
 }

 void togglePin(uint8_t pin)
 {
	if(0 < pin && pin < 7)
	{
		PORTC ^= (1 << pin);	//toggle the pin
	}
 }

 void setBank(uint8_t pins)
 {
	PORTC = pins;	//toggle whole bank
 }

 void clearBank(void)
 {
	PORTC = 0;
 }