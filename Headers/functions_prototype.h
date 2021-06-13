#ifndef functions_prototype

#define functions_prototype


double degtorad(double deg);
double calcDistance(double long1, double long2, double lat1, double lat2);
void LCD_data(unsigned char c);
void LCD_display_string(unsigned char* str);
void delay_ms(int a);
void delay_us(int a);
void LCD_comm(unsigned char c);
void LCD_init(void);
void REDLed(double distance);
void init_ports(void);
void get_nema_string(char *arr, int *cont);
void getPosition(char *string, double *coordinates );
unsigned char UART_receive(void);
void reverseArray(char *arr, char *reversed);
#endif // !functions_prototype
