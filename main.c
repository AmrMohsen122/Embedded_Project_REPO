#include "Headers/functions_prototype.h"
#include "Headers/GPIO_DEF.h"
int main(void)
{
    init_ports();
    delay_ms(50);
    LCD_init();
    delay_ms(20);
    LCD_display_string("Hello 123");
    while (1)
    {
        double distance = 102;
        REDLed(distance);
    }
    
    return 0;
}
