//LCD command function for setting portB(data) portD(command)
//(d0 --> lcd register select rs d1 --> lcd read/write RW d2 --> lcd enable)
void LCD_comm(char c){
	GPIO_PORTD_DATA_R &= ~0x07;
	GPIO_PORTB_DATA_R = c;
	GPIO_PORTD_DATA_R |= 0x04;
	delay(230);
	GPIO_PORTD_DATA_R &= 0;
}
//initializing portB and portD(DO~D02)
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