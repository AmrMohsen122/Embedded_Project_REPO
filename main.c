#include "Headers/functions_prototype.h"
#include "Headers/GPIO_DEF.h"
#include "Headers/tm4c123gh6pm.h"
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int i;
	double amount = 0;

	double distance = 0;
	int cont = 1;
	char arr[100];
	double coordinates[2][2];
	init_ports();
	delay_ms(50);
	LCD_init();
	delay_ms(20);
	while(cont){
		get_nema_string(arr , &cont);
	}
	cont = 1;
	getPosition(arr , coordinates[0]);
	delay_ms(10);
	while(1){
			while(cont){
				get_nema_string(arr , &cont);
			}
			
			cont = 1;
			if(distance >= 100 ){
		GPIO_PORTF_DATA_R |=0X02;
				break;
	 		}

			getPosition(arr , coordinates[1]);
			calcDistance(coordinates[0][1] , coordinates[1][1] , coordinates[0][0], coordinates[1][0] , &amount);
			distance += amount;
			//swap the two points
			for(i = 0 ; i < 2 ; i++){
				coordinates[0][i] = coordinates[1][i]; 
			}
			LCD_comm(clear);
			delay_ms(2);
			
			 LCD_display_string(int_to_char(distance));
			//LCD_display_string(reverseArray(int_to_char(distance)));
			
			
			delay_ms(10);
	}
	/*
	LCD_comm(clear);
			delay_ms(2);
			reverseArray(int_to_char(distance), reversed);
	   LCD_display_string(reversed);
	
			
			delay_ms(10000);
	*/
	return 0;
	}
