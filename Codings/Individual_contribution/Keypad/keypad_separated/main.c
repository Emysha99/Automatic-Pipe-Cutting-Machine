/*
 * keypad_separated.c
 *
 * Created: 5/27/2022 8:52:52 PM
 * Author : user
 */


 #define F_CPU 16000000UL
 
 #include <avr/io.h>
 #include <util/delay.h>
 
 #include "lcd.h"
 #include "keypad.h"
 
 unsigned char x;
 unsigned char y;
 int pipeLength=0 ; // variable for length of the pipe
 int quantity=0; // variable for quantity


int main(void)
{
	DDRA=0x0F;
	lcd_init();
	lcd_print("  HELLO USER ");
	_delay_ms(30);
	lcdcmd(0x01);//clear the display
	lcdcmd(0x0E);//blink the cursor
	_delay_ms(30);
	lcd_print("-- ICT PROJECT --");
	_delay_ms(30);
	lcdcmd(0x01);
	lcdcmd(0x0E);
	_delay_ms(30);
	lcd_print("  GROUP - 39");
	label1:
	_delay_ms(100);
	lcdcmd(0x01);
	lcdcmd(0x0E);
	_delay_ms(100);
	lcd_print("ENTER LENGTH :");
	lcdcmd(0xC0);//bring cursor to next line
	
	do
	{
		PORTA=0xF0;
		if(PINA!=0xF0)
		{
			x=keypad();
			if(x=='/'||x=='*'||x=='-'||x=='C'||x=='+')
			{
				lcdcmd(0x01);
				lcdcmd(0x0E);
				_delay_ms(30);
				lcd_print("INVALID INPUT");
				_delay_ms(30);
				goto label1;
			}
			
			else if(x!='E')
			{
				pipeLength=(pipeLength*10)+(x-'0');//read the length of the pipe
				lcddata(x);//print the data
				
			}
		}
	}while(x!='E');
	 
	 if(pipeLength<=10 ||pipeLength>150)
	 {
		 lcdcmd(0x01);
		 lcdcmd(0x0E);
		 _delay_ms(30);
		 lcd_print("INVALID LENGTH");
		 _delay_ms(30);
		
	}
	 
	    label2:
	    lcdcmd(0x01);
	    lcdcmd(0x0E);
	    _delay_ms(30);
	    lcd_print("ENTER QUANTITY :");
	    _delay_ms(30);
	    lcdcmd(0xC0);
	
	   do
	   {
		PORTA=0xF0;
		if(PINA!=0xF0)
		{
			y=keypad();
			if(y=='/'||y=='*'||y=='-'||y=='+')
			{
				lcdcmd(0x01);
				lcdcmd(0x0E);
				_delay_ms(30);
				lcd_print("INVALID INPUT");
				_delay_ms(30);
				goto label2;
			}
			else if(y!='E')//read the quantity
			{
				quantity=y-'0';
				lcddata(y);
			}
		}
	   }while(y!='E');
	
	
	if(y=='E')
	{
		lcdcmd(0x01);
		lcdcmd(0x0E);
		_delay_ms(30);
		lcd_print("    DONE");
		_delay_ms(100);
		lcdcmd(0x01);
		_delay_ms(500);
	}

	return 0;
}



