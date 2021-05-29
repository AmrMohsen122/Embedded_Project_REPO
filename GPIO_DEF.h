#ifndef GPIO_DEF
//commit reg and amsel of ports are at lines: A(13,14) B(30,31) C(47,48) D(64,65) E(81,82) F(98,99)
		#define GPIO_DEF
		#define GPIO_PORTF_LOCK_KEY 0x4C4F434B
		//PORTA DEFINATIONS
		#define SYSCTL_RCGCGPIO_R 	(*((volatile unsigned long *) 0x400FE608))
		#define SYSCTL_PRGPIO_R  		(*((volatile unsigned long *) 0x400FEA08))
		#define GPIO_PORTA_DATA_R 	(*((volatile unsigned long *) 0x400043FC))
		#define GPIO_PORTA_DIR_R 		(*((volatile unsigned long *) 0x40004400))
		#define GPIO_PORTA_AFSEL_R 	(*((volatile unsigned long *) 0x40004420))
		#define GPIO_PORTA_PUR_R 		(*((volatile unsigned long *) 0x40004510))
		#define GPIO_PORTA_DEN_R		(*((volatile unsigned long *) 0x4000451C))
		#define GPIO_PORTA_PCTL_R		(*((volatile unsigned long *) 0x4000452C))
		//#define GPIO_PORTA_CR_R     (*((volatile unsigned long *) 0x40004524))
		//#define GPIO_PORTA_AMSEL_R  (*((volatile unsigned long *) 0x40004528))
		#define PORTA 0
		#define PORTA0 0
		#define PORTA1 1
		#define PORTA2 2
		#define PORTA3 3
		#define PORTA4 4
		#define PORTA5 5
		#define PORTA6 6
		#define PORTA7 7
		SYSCTL_RCGCGPIO_R |= ((1 << PORTA) | (1 << PORTD));

		//PORTB DEFINIATIONS
		#define GPIO_PORTB_DATA_R 	(*((volatile unsigned long *) 0x400053FC))
		#define GPIO_PORTB_DIR_R 		(*((volatile unsigned long *) 0x40005400))
		#define GPIO_PORTB_AFSEL_R 	(*((volatile unsigned long *) 0x40005420))
		#define GPIO_PORTB_PUR_R 		(*((volatile unsigned long *) 0x40005510))
		#define GPIO_PORTB_DEN_R		(*((volatile unsigned long *) 0x4000551C))
    #define GPIO_PORTB_PCTL_R		(*((volatile unsigned long *) 0x4000552C))
		#define GPIO_PORTB_CR_R     (*((volatile unsigned long *) 0x40005524))  //already enabled
		#define GPIO_PORTB_AMSEL_R  (*((volatile unsigned long *) 0x40005528))  //all diasbled
		#define PORTB 1
		#define PORTB0 0
		#define PORTB1 1
		#define PORTB2 2
		#define PORTB3 3
		#define PORTB4 4
		#define PORTB5 5
		#define PORTB6 6
		#define PORTB7 7
		//PORTC DEFINIATIONS
		#define GPIO_PORTC_DATA_R 	(*((volatile unsigned long *) 0x400063FC))
		#define GPIO_PORTC_DIR_R 		(*((volatile unsigned long *) 0x40006400))
		#define GPIO_PORTC_AFSEL_R 	(*((volatile unsigned long *) 0x40006420))
		#define GPIO_PORTC_PUR_R 		(*((volatile unsigned long *) 0x40006510))
		#define GPIO_PORTC_DEN_R		(*((volatile unsigned long *) 0x4000651C))
		//#define GPIO_PORTC_CR_R     (*((volatile unsigned long *) 0x40006524))
		//#define GPIO_PORTC_AMSEL_R  (*((volatile unsigned long *) 0x40006528))
		#define PORTC 2
		#define PORTC0 0
		#define PORTC1 1
		#define PORTC2 2
		#define PORTC3 3
		#define PORTC4 4
		#define PORTC5 5
		#define PORTC6 6
		#define PORTC7 7
		//PORTD DEFINIATIONS
		#define GPIO_PORTD_DATA_R 	(*((volatile unsigned long *) 0x400073FC))
		#define GPIO_PORTD_DIR_R 		(*((volatile unsigned long *) 0x40007400))
		#define GPIO_PORTD_AFSEL_R 	(*((volatile unsigned long *) 0x40007420))
		#define GPIO_PORTD_PUR_R 		(*((volatile unsigned long *) 0x40007510))
		#define GPIO_PORTD_DEN_R		(*((volatile unsigned long *) 0x4000751C))
		//#define GPIO_PORTD_CR_R     (*((volatile unsigned long *) 0x40007524))
		//#define GPIO_PORTD_AMSEL_R  (*((volatile unsigned long *) 0x40007528))
		#define PORTD 3
		#define PORTD0 0
		#define PORTD1 1
		#define PORTD2 2
		#define PORTD3 3
		#define PORTD4 4
		#define PORTD5 5
		#define PORTD6 6
		#define PORTD7 7
		//PORTE DEFINIATIONS
		#define GPIO_PORTE_DATA_R 	(*((volatile unsigned long *) 0x400243FC))
		#define GPIO_PORTE_DIR_R 		(*((volatile unsigned long *) 0x40024400))
		#define GPIO_PORTE_AFSEL_R 	(*((volatile unsigned long *) 0x40024420))
		#define GPIO_PORTE_PUR_R 		(*((volatile unsigned long *) 0x40024510))
		#define GPIO_PORTE_DEN_R		(*((volatile unsigned long *) 0x4002451C))
		//#define GPIO_PORTE_CR_R     (*((volatile unsigned long *) 0x40024524))
		//#define GPIO_PORTE_AMSEL_R  (*((volatile unsigned long *) 0x40024528))
		#define PORTE 4
		#define PORTE0 0
		#define PORTE1 1
		#define PORTE2 2
		#define PORTE3 3
		#define PORTE4 4
		#define PORTE5 5
	
		//PORTF DEFINIATIONS
		#define GPIO_PORTF_DATA_R 	(*((volatile unsigned long *) 0x400253FC))
		#define GPIO_PORTF_DIR_R 		(*((volatile unsigned long *) 0x40025400))
		#define GPIO_PORTF_AFSEL_R 	(*((volatile unsigned long *) 0x40025420))
		#define GPIO_PORTF_PUR_R 		(*((volatile unsigned long *) 0x40025510))
		#define GPIO_PORTF_DEN_R		(*((volatile unsigned long *) 0x4002551C))
		#define GPIO_PORTF_LOCK_R		(*((volatile unsigned long *) 0x40025520))
		#define GPIO_PORTF_PCTL_R		(*((volatile unsigned long *) 0x4002552C))
		#define GPIO_PORTF_CR_R     (*((volatile unsigned long *) 0x40025524))
		#define GPIO_PORTF_AMSEL_R  (*((volatile unsigned long *) 0x40025528))
		#define PORTF 5
		#define PORTF0 0
		#define PORTF1 1
		#define PORTF2 2
		#define PORTF3 3
		#define PORTF4 4
//---------------------------------------------------------------------------------------------------------------------
		//UART DEFINATIONS
		#define UART1_DR 					 (*((volatile unsigned long *) 0x4000D000))
		#define UART1_IBRD         (*((volatile unsigned long *) 0x4000D024))
		#define UART1_FBRD         (*((volatile unsigned long *) 0x4000D028))
		#define UART1_LCRH         (*((volatile unsigned long *) 0x4000D02C))
		#define UART1_CTL          (*((volatile unsigned long *) 0x4000D030))
		#define PRUART1            (*((volatile unsigned long *) 0x4000DA18))
		#define UART1_RCGC         (*((volatile unsigned long *) 0x4000D618))
		#define UART1_FR           (*((volatile unsigned long *) 0x4000D018))
#endif
	