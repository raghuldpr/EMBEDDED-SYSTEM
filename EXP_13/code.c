#include <reg51.h>

void main(void)
{
    unsigned int i;

    // Array of five 16-bit hexadecimal numbers
    unsigned int array[5] = {
        0x1111, 0x2222, 0x8888, 0x4444, 0xABCD
    };

    unsigned long sum = 0;

    // Calculate total sum
    for (i = 0; i < 5; i++)
    {
        sum = sum + array[i];
    }

    // Split 32-bit sum across 8-bit ports
    P0 = (unsigned char)(sum & 0xFF);
    P1 = (unsigned char)((sum >> 8) & 0xFF);
    P2 = (unsigned char)((sum >> 16) & 0xFF);
    P3 = (unsigned char)((sum >> 24) & 0xFF);

    // Infinite loop
    while (1);
}
