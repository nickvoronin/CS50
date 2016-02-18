#include "bmp.h"
#include <stdio.h>

int main(void)
{
    
    //What’s the point of using uint8_t, uint32_t, int32_t, and uint16_t in a program?

    printf("Size of uint8_t is %lu bytes\n", sizeof(uint8_t));
    printf("Size of uint32_t is %lu bytes\n", sizeof(uint32_t));
    printf("Size of int32_t is %lu bytes\n", sizeof(int32_t));
    printf("Size of uint16_t is %lu bytes\n", sizeof(uint16_t));
}