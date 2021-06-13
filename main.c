#include "Headers/functions_prototype.h"
#include "Headers/GPIO_DEF.h"
#include "Headers/tm4c123gh6pm.h"
#include <stdlib.h>
int main(void)
{
	int i;
	double amount = 0;
	double distance = 0;
	int cont = 1;
	char *arr = (char *)malloc(100 * sizeof(char));
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
	delay_ms(2000);
    while (1)
    {
        double distance = 102;
        REDLed(distance);
    }
    
    return 0;
}
