/*
 *
 * Created: 5/28/2019 2:34:53 PM
 *  Author: krlic
 */ 

 #include "avr/io.h"
 #include "define.h"


 void initUART(void)	//sets up the uart Registers
 {
	 UBRR0H = UBRRH_VALUE;
	 UBRR0L = UBRRL_VALUE;

	 #if USE_2X
	 UCSR0A |= (1<< U2X0);
	 #else
	 UCSR0A &= ~(1 << U2X0);
	 #endif

	 UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); /* 8-bit data */
	 UCSR0B = (1 << RXEN0) | (1 << TXEN0);   /* Enable RX and TX */
 }

 void transmit(uint8_t data)
 {
	 //while(!(UCSR0A & (1 << UDRE0)));
	 loop_until_bit_is_set(UCSR0A,UDRE0);
	 UDR0 = data;
	 
 }

 void transmitString(const char string[])
 {
	 uint8_t i = 0;
	 while(string[i])
	 {
		 transmit(string[i]);
		 i++;
	 }
 }

 uint8_t receive(void)
 {
	 loop_until_bit_is_set(UCSR0A,RXC0);
	 return UDR0;
 }

 uint8_t receiveWaiting(void)
 {
	uint8_t out = (UCSR0A ^ 0x80);
	return out;	//read the RXC0 Bit
 }
