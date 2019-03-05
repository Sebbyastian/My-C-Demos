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
    Tested Compilers:         GCC ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10

    Description: This is the code to a challenge that adds two numbers without using the basic math operators.
*/

#include <stdio.h>

#define MaximumCharacters 255

int main(void)
{
    unsigned char UserInput[MaximumCharacters] = {};
    int iteration;

    printf("Please enter a message (maximum %d characters)\n> ", MaximumCharacters - 1);
    fgets(UserInput, MaximumCharacters, stdin);

    for(iteration = 0; iteration <= MaximumCharacters; ++iteration)
    {
        if(iteration % 16 == 0) printf("\n");
        printf("%02X ", UserInput[iteration]);
    }

    printf("\n\nYou said: %s", UserInput);

    return 0;
}
