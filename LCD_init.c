#include "Headers/tm4c123gh6pm.h"
#include "Headers/GPIO_DEF.h"
/*
d0 --> lcd register select rs
d1 --> lcd read/write RW
d2 --> lcd enable
*/



void LCD_comm(char c){
	GPIO_PORTD_DATA_R = O;
	GPIO_PORTB_DATA_R = c;
	GPIO_PORTD_DATA_R |= 0x80;
	delay(230);
	GPIO_PORTD_DATA_R &= 0;
}

void LCD_data(unsigned char c){
	GPIO_PORTB_DATA_R = c;					//ready up data to be displayed
	GPIO_PORTD_DATA_R |= (1 << PORTD0);		//select the lcd_data register
	GPIO_PORTD_DATA_R &= ~(1 << PORTD1);	//set lcd to write mode
	GPIO_PORTD_DATA_R |= (1 << PORTD2); 	//pull the enable to high
	delay(230);
	GPIO_PORTD_DATA_R &= ~(1 << PORTD2);	//pull the enable to low
}

void LCD_init(){
	SYSCTL_RCGCGPIO_R |=0xA;
	GPIO_PORTB_DIR_R = 0xff;
	GPIO_PORTB_DEN_R = 0Xff;
	GPIO_PORTB_AFSEL_R &= 0;
	GPIO_PORTB_AMSEL_R &= 0;
	GPIO_PORTD_DIR_R |= 0x7;
	GPIO_PORTD_DEN_R |= 0x7;
	GPIO_PORTD_AFSEL_R &= 0;
	GPIO_PORTD_AMSEL_R &= 0;
	LCD_comm(0x30);
	delay(200);
	LCD_comm(0x06);
	delay(200);
	LCD_comm(0x0f);
	delay(200);
}