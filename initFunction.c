#include "HEADERS\tm4c123gh6pm.h"
#include "HEADERS\GPIO_DEF.h"
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------

PORTB ---> LCD_DATA
PORTD PIND0-PIND2 ---> LCD_CTL
PORTD PIND6,PIND7 -->UART_TX&RX
PORTF PORTF2 -->LED


--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void init_ports(){
	SYSCTL_RCGCGPIO_R |= ((1 << PORTB) | (1 << PORTD) | (1 << PORTF)); //ENABLE CLK FOR PORTS B, F, D
	while((SYSCTL_PRGPIO_R & ((1 << PORTB) | (1 << PORTD) | (1 << PORTF))) == 0){}//WAIT FOR CLK TO BE ENABLED
	//PORTB init
	GPIO_PORTB_DIR_R = 0xFF;				//Set portB pins to output
	GPIO_PORTB_AFSEL_R = 0x00;				//disable portB pin alternate function
	GPIO_PORTB_PCTL_R = 0x00000000;			//PORTB AS GPIO
	GPIO_PORTB_AMSEL_R = 0x00;				//disable analog signals
	GPIO_PORTB_DEN_R = 0xFF;				//enable digital signals
	//PORTF init
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;		//unlock portf
	GPIO_PORTF_CR_R |= (1 << PORTF2);		//enable changes on PORTF2
	GPIO_PORTF_DIR_R |= (1 << PORTF2);		//set PORTF2 to output
	GPIO_PORTF_PCTL_R = 0x00000000;		    //PORTF AS GPIO
	GPIO_PORTF_AMSEL_R  &= ~(1 << PORTF2); 	//disable analog signals	
	GPIO_PORTF_AFSEL_R &= ~(1 << PORTF2);	//disable alternate function for PORTF2
	GPIO_PORTF_DEN_R |= (1 << PORTF2) ;		//enable digital signals
	//PORTD init
	GPIO_PORTD_DIR_R |= ((1 << PORTD0) | (1 << PORTD1) | (1 << PORTD2)); //PORTD0-D2 output for lcd_ctl
	GPIO_PORTD_AMSEL_R &= ~((1 << PORTD0) | (1 << PORTD1) | (1 << PORTD2));//disable analog signals 
	GPIO_PORTD_PCTL_R &= ~(0x00000FFF); 	//use PORTD0-D2 as GPIO
	GPIO_PORTD_AFSEL_R &= ~((1 << PORTD0) | (1 << PORTD1) | (1 << PORTD2));//disable alternate function
	GPIO_PORTD_DEN_R |= ((1 << PORTD0) | (1 << PORTD1) | (1 << PORTD2));   //enable digital signals
	//UART init 
  	SYSCTL_RCGCUART_R |= (0x0004);
	UART2_CTL_R &= ~(0x0001);
	UART2_IBRD_R |= 104;
	UART2_FBRD_R |= 11;
	UART2_LCRH_R &= ~(0x08); 									//Make FIFO have only one stop bit
	UART2_LCRH_R |= 0x60; 										//Make Word Length 8 bits
	GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY; 							//Unlock PORT D
	GPIO_PORTD_DIR_R &= ~(1 << PORTD6) ;						//Enable PINS D6 as input for GPS
	GPIO_PORTD_DIR_R |= (1 << PORTD7) ; 						//Enable PIN D7 as output for GPS
	GPIO_PORTD_AMSEL_R &= ~((1 << PORTD6) | (1 << PORTD7) ); 	//disable analog signals 
	GPIO_PORTD_PCTL_R |= (0x11000000); 							//use PINS D6, D7 as UART Tx, Rx
	GPIO_PORTD_AFSEL_R |= ((1 << PORTD6) | (1 << PORTD7) );		//enable alternate function
	GPIO_PORTD_DEN_R |= ((1 << PORTD6) | (1 << PORTD7) ); 		//enable PINS D6, D7 as Digital pins
	UART2_CTL_R |= (0x01); 										// Enable UART2 Tx, Rx




}
