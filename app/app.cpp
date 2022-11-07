#include <cstdlib>
#include <thread>

static const char* TAG = "example";
extern "C" void app_main(void)
{
    while(1) {
        volatile int i = 0;
        volatile int j = 1;
        volatile int k = i + j;
    }
}