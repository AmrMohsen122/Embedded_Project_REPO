#include "Headers/functions_prototype.h"
#include "Headers/GPIO_DEF.h"
int main()
{
    LCD_init();
    while (1)
    {
        LCD_comm(display_on);
        LCD_comm(clear);
        LCD_data('A');
    }

    return 0;
}