/*
 * IR TEST.c
 *
 * Created: 12/2/2021 2:37:52 PM
 * Author : user
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
int main()
{
	PORTD = 0x00;
	DDRD  = 0x10; 

	while (1)
	{
		if((PIND & 0x10) != 0)    
		PORTD |= 0b00100000;  
		else
		PORTD &= 0b11011111;   
	}
}
