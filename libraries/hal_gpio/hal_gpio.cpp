#include "hal_gpio.h"

void use_hal_gpio()
{
    volatile int i = 0;
    volatile int *j = &i;
    *j = i + 1;
    return;
}