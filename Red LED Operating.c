
#include "Headers/tm4c123gh6pm.h"

void REDLed(double distance){
    if (distance>=100){
        GPIO_PORTF_DATA_R |=0X02;  // Set bit F1 = 1 so the Red LED Operates
    }
}
