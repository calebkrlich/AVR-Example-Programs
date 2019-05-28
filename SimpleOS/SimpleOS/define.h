/*
 * define.c
 *
 * Created: 5/28/2019 2:36:46 PM
 *  Author: krlic
 */ 

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#ifndef BAUD
	#define BAUD 9600
#endif

#include <util/setbaud.h>

#ifndef loop_until_bit_is_set
 #define loop_until_bit_is_set(sfr, bit) do {} while(bit_is_clear(sfr,bit))
#endif
