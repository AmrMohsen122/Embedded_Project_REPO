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

<<<<<<< HEAD
void get_nema_string(char arr[], int *cont)
=======
void get_nema_string(char *arr, int *cont) // Function for recieving $GPRMC sentence from gps
>>>>>>> d10dc64c60bcea787c2ea0222af414e49a180f3e
{
    int i;
    char str[100];
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
<<<<<<< HEAD
=======
		
>>>>>>> d10dc64c60bcea787c2ea0222af414e49a180f3e
    }
    else
        *cont = 1;
}
<<<<<<< HEAD
void getPosition(char string[], double coordinates[])
=======


void getPosition(char *string, double *coordinates ) //Function for extracting longitude and latitude from nema sentence recived
>>>>>>> d10dc64c60bcea787c2ea0222af414e49a180f3e
{

    static char *parsed[20];
    int i = 0;
    static char *token;
    token = strtok(string, ",");
    while (token != NULL)
    {
        parsed[i++] = token;
        token = strtok(NULL, ",");
        if (i == 20)
            break;
    }
    coordinates[0] = (strtod(parsed[3], NULL)); //lat
    coordinates[1] = (strtod(parsed[5], NULL)); //long

}

