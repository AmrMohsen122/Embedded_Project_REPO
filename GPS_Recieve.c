#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Headers/GPIO_DEF.h"
#include "Headers/functions_prototype.h"
#include "Headers/tm4c123gh6pm.h"
#define RXFE 4

unsigned char UART_receive(void)
{
    while ((UART2_FR_R & (1 << RXFE)) != 0)
    {
    }
    return (unsigned char)(UART2_DR_R & 0xFF);
}

void get_nema_string(char *arr, int *cont) // Function for recieving $GPRMC sentence from gps
{
    int i;
    char *str = malloc(100);
    unsigned char received = UART_receive();

    str[0] = received;
    received = UART_receive();
    for (i = 1; received != 0x0A; i++)
    {

        str[i] = received;
        received = UART_receive();
    }

    if (str[3] == 'R' && str[0] == '$')
    {
        memcpy(arr, str, 100);
        *cont = 0;
		
    }
		else *cont = 1;
    free(str);


}


void getPosition(char *string, double *coordinates ) //Function for extracting longitude and latitude from nema sentence recived
{

				char *parsed[20];
        int i = 0;
        char *token;
        token = strtok(string, ",");
        while (token != NULL)
        {
            parsed[i++] = token;
            token = strtok(NULL, ",");
            if (i == 20)
                break;
					}
    coordinates[0] = (strtod(parsed[3] , NULL)) ;  //lat
    coordinates[1] = (strtod(parsed[5] , NULL));  //long

}


