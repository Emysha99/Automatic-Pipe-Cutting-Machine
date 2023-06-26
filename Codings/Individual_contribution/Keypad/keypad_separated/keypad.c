/*
 * keypad.c
 *
 * Created: 5/27/2022 9:18:45 PM
 *  Author: user
 */ 

#include "keypad.h"

// check & return the value of pressed key
unsigned char keypad()
{
	PORTA=0b11111110;//check first row
	if((PINA &(1<<PINA4))==0)
	{
		_delay_ms(10);
		return '7';
	}
	else if((PINA & (1<<PINA5))==0)
	{
		_delay_ms(10);
		return '8';
	}
	else if((PINA & (1<<PINA6))==0)
	{
		_delay_ms(10);
		return '9';
	}
	else if((PINA & (1<<PINA7))==0)
	{
		_delay_ms(10);
		return '/';
	}
	
	PORTA=0b11111101;//check second row
	if((PINA &(1<<PINA4))==0)
	{
		_delay_ms(10);
		return '4';
	}
	else if((PINA & (1<<PINA5))==0)
	{
		_delay_ms(10);
		return '5';
	}
	else if((PINA & (1<<PINA6))==0)
	{
		_delay_ms(10);
		return '6';
	}
	else if((PINA & (1<<PINA7))==0)
	{
		_delay_ms(10);
		return '*';
	}
	
	PORTA=0b11111011;//check third row
	if((PINA &(1<<PINA4))==0)
	{
		_delay_ms(10);
		return '1';
	}
	else if((PINA & (1<<PINA5))==0)
	{
		_delay_ms(10);
		return '2';
	}
	else if((PINA & (1<<PINA6))==0)
	{
		_delay_ms(10);
		return '3';
	}
	else if((PINA & (1<<PINA7))==0)
	{
		_delay_ms(10);
		return '-';
	}
	
	PORTA=0b11110111;//check fourth row
	if((PINA &(1<<PINA4))==0)
	{
		_delay_ms(10);
		return 'C';
	}
	else if((PINA & (1<<PINA5))==0)
	{
		_delay_ms(10);
		return '0';
	}
	else if((PINA & (1<<PINA6))==0)
	{
		_delay_ms(10);
		return 'E';
	}
	else if((PINA & (1<<PINA7))==0)
	{
		_delay_ms(10);
		return '+';
	}
}

