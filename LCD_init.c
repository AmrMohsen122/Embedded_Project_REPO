#include "Headers/tm4c123gh6pm.h"
#include "Headers/GPIO_DEF.h"
#include "Headers/functions_prototype.h"
//LCD command function for setting portB(data) portD(command)
//(d0 --> lcd register select rs d1 --> lcd read/write RW d2 --> lcd enable)

void LCD_comm(unsigned char c)
{
	GPIO_PORTD_DATA_R &= ~0x07;
	GPIO_PORTB_DATA_R = c;
	if(c & 0x40) GPIO_PORTD_DATA_R |= (1 << PORTD3);
	GPIO_PORTD_DATA_R |= 0x04;
	delay_us(1);
	GPIO_PORTD_DATA_R &= ~(0x04);
	delay_us(1);
}

void LCD_data(unsigned char c)
{
	GPIO_PORTB_DATA_R = c;				 //ready up data to be displayed
	GPIO_PORTD_DATA_R |= (1 << PORTD0);	 //select the lcd_data register
	GPIO_PORTD_DATA_R &= ~(1 << PORTD1); //set lcd to write mode
	GPIO_PORTD_DATA_R |= (1 << PORTD2);	 //pull the enable to high
	delay(230);
	GPIO_PORTD_DATA_R &= ~(1 << PORTD2); //pull the enable to low
}

//initializing portB and portD(DO~D02)
void LCD_init()
{
	 delay_ms(voltage_risetime);
	 LCD_comm(on_8bit_mode); 							// Select 8-bit Mode of LCD
	 delay_us(command_delay);
     LCD_comm(display_on);  							// display on , cursor blinking
	 delay_us(command_delay);
	 LCD_comm(auto_inc_cursor);							//auto increment cursor
	 delay_us(command_delay);
	 LCD_comm(clear); 									//clear display
	 delay_ms(5);
}

void LCD_display_string(unsigned char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		LCD_Data(str[i]);
		LCD_comm(inc_cursor);
	}
}
void delay_ms(int n)
{
	int x , y;
	for(x = 0; x < n ; x++){
		for(y = 0 ; y < 3180;y++)
		{}
	
	}
}

void delay_us(int n)
{
 int i,j;
 for(i=0;i<n;i++){
	for(j=0;j<3;j++){}
	
	}
}