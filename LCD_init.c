
#include "Headers/tm4c123gh6pm.h"
#include "Headers/GPIO_DEF.h"
#include "Headers/functions_prototype.h"
//LCD command function for setting portB(data) portD(command)
//(d0 --> lcd register select rs d1 --> lcd read/write RW d2 --> lcd enable)

void LCD_comm(unsigned char c)
{
	GPIO_PORTB_DATA_R = c;															//ready up command
	if(c & 0x40) GPIO_PORTD_DATA_R |= (1 << PORTD3); 		//PORTB6 had some errors; command is masked 
	else GPIO_PORTD_DATA_R &= ~(1 << PORTD3);						//the masked data is outputed on PORTD3 instead
	GPIO_PORTA_DATA_R &= ~(1 << PORTA5);								//RS is reseted
	GPIO_PORTA_DATA_R &= ~(1 << PORTA6);								//R/W is reseted
	GPIO_PORTD_DATA_R |= (1 << PORTD2);									//pull the enable to high
	delay_ms(1);																				//enable high hold time
	GPIO_PORTD_DATA_R &= ~(1 << PORTD2);								//pull the enable to low
	delay_us(1);

}

void LCD_data(unsigned char c)
{
    GPIO_PORTB_DATA_R = c;                				  //ready up data to be displayed
    if(c & 0x40) GPIO_PORTD_DATA_R |= (1 << PORTD3);
		else GPIO_PORTD_DATA_R &= ~(1 << PORTD3);
		GPIO_PORTA_DATA_R |= (1 << PORTA5);   				  //RS is set
		GPIO_PORTA_DATA_R &= ~(1 << PORTA6);  				  //R/W is reseted
		GPIO_PORTD_DATA_R |= (1 << PORTD2);	 				  //pull the enable to high
		delay_us(1);						  				  //enable high hold time
		GPIO_PORTD_DATA_R &= ~(1 << PORTD2);  				  //pull the enable to low
		delay_us(1);
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
	int i;
	for(i = 0; str[i] != '\0'; i++)
	{
		LCD_data(str[i]);
		delay_us(data_delay);
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