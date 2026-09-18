#include <reg51.h>

void main()
{
    unsigned int num1, num2;
    unsigned long int product;

    num1 = 0x2222;
    num2 = 0xBBBB;

    while (1)
    {
        // Multiply two 16-bit numbers
        product = (unsigned long int)num1 * num2;

        // Send 32-bit result to four 8-bit ports
        P0 = product & 0xFF;
        P1 = (product >> 8) & 0xFF;
        P2 = (product >> 16) & 0xFF;
        P3 = (product >> 24) & 0xFF;
    }
}
