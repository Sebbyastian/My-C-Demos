/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    Feburary 28th, 2018

    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/

    Programming Language:     C (c99)
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10

    Description: prints a lot of information about floating-point numbers.
*/

#include <stdio.h>
#include <math.h>
#include <values.h>

/* endianness testing */
const int EndianTest = 0x04030201;

#define LITTLE_ENDIAN() (*((const char *) &EndianTest) == 0x01)

/* extract nth LSB from object stored in lvalue x */
#define GET_BIT(x, n) ((((const char *) &x)[LITTLE_ENDIAN() ? (n) / CHARBITS : sizeof(x) - (n) / CHARBITS - 1] >> ((n) % CHARBITS)) & 0x01)

#define PUT_BIT(x, n) (putchar(GET_BIT((x), (n)) ? '1' : '0'))

void print_float_bits(float);


int main(int argc, char **argv)
{
    float f;

    printf("Please enter a floating point number: ");

    while(scanf("%f", &f)) {
        printf("\n%10g = %24.17g = ", f, f);
        print_float_bits(f);
        printf("\n\nPlease enter a floating point number: ");
    }

    return 0;
}


void print_float_bits(float f)
{
    int i;

    i = FLOATBITS - 1;
    PUT_BIT(f, i);
    putchar(' ');
    for(i--; i >= 23; i--) {
        PUT_BIT(f, i);
    }
    putchar(' ');
    for(; i >= 0; i--) {
        PUT_BIT(f, i);
    }
}
