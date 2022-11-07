#include "wifi.h"

void use_wifi()
{
    volatile int i = 0;
    volatile int *j = &i;
    *j = i + 1;
    return;
}