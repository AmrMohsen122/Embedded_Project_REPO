<<<<<<< HEAD
#include "Headers/tm4c123gh6pm.h"
#include "Headers/GPIO_DEF.h"
/*
d0 --> lcd register select rs
d1 --> lcd read/write RW
d2 --> lcd enable
*/



=======
//LCD command function for setting portB(data) portD(command)
//(d0 --> lcd register select rs d1 --> lcd read/write RW d2 --> lcd enable)
>>>>>>> eb5909331e32eb23e08c80ecca24decdfe254186
void LCD_comm(char c){
	GPIO_PORTD_DATA_R &= ~0x07;
	GPIO_PORTB_DATA_R = c;
	GPIO_PORTD_DATA_R |= 0x04;
	delay(230)
	GPIO_PORTD_DATA_R &= 0;
}
<<<<<<< HEAD

void LCD_data(unsigned char c){
	GPIO_PORTB_DATA_R = c;					//ready up data to be displayed
	GPIO_PORTD_DATA_R |= (1 << PORTD0);		//select the lcd_data register
	GPIO_PORTD_DATA_R &= ~(1 << PORTD1);	//set lcd to write mode
	GPIO_PORTD_DATA_R |= (1 << PORTD2); 	//pull the enable to high
	delay(230);
	GPIO_PORTD_DATA_R &= ~(1 << PORTD2);	//pull the enable to low
}

=======
//initializing portB and portD(DO~D02)
>>>>>>> eb5909331e32eb23e08c80ecca24decdfe254186
void LCD_init(){
	SYSCTL_RCGCGPIO_R |=0xA;//clack initiation portB,portD
	GPIO_PORTB_DIR_R = 0xff;//direction init for portB
	GPIO_PORTB_DEN_R = 0Xff;//digital enable portB
	GPIO_PORTB_AFSEL_R = 0;//disable analog function
	GPIO_PORTB_AMSEL_R = 0;
	GPIO_PORTD_DIR_R |= 0x7;//direction init for portD(D0~D2)
	GPIO_PORTD_DEN_R | = 0x7;//digital enable for portD(D0~D2)
	GPIO_PORTD_AFSEL_R &= ~0x07;//disable analog function
	GPIO_PORTD_AMSEL_R &= ~0x07;
	LCD_comm(0x30);//LCD wakeup
	delay(20);
	LCD_comm(0x38);//enabling 2 line deisplay
	delay(20);
	LCD_comm(0x01);//clear display
	delay(20);
	LCD_comm(0x06);//cursor increment
	delay(20);
	LCD_comm(0x0f);//display on
	delay(20);
}