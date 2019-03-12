/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    March 12th, 2019
    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/
    Programming Language:     C (c99)
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10
    Description: This demo asks for a message from the user and the displays how many
                 consonants, vowels, number, spaces, and punctuations there are in the
                 message.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int CounterConsonants = 0;
    int CounterVowels = 0;
    int CounterNumbers = 0;
    int CounterSpaces = 0;
    int CounterPunctuation = 0;
    int Iterator1 = 0;

    char UserInput[255];
    char vowels[] = "aeiouAEIOU";
    char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    char numbers[] = "1234567890";
    char space[] = " ";
    char punctuation[] = "`~!@#$%^&*()_-+={}[]|\\:;\"\'<>,.?/";

    printf("This C demo will count all consonants, vowels, numbers, spaces, and punctuation in a message.\n\nPlease type in a message:\n> ");

    gets(UserInput);
    UserInput[strcspn(UserInput, "\n")] = 0;

    for (Iterator1 = 0; Iterator1 < strlen(UserInput); Iterator1++)
    {
        if (strchr(consonants, UserInput[Iterator1]) != 0) CounterConsonants++;
        if (strchr(vowels, UserInput[Iterator1]) != 0) CounterVowels++;
        if (strchr(numbers, UserInput[Iterator1]) != 0) CounterNumbers++;
        if (strchr(space, UserInput[Iterator1]) != 0) CounterSpaces++;
        if (strchr(punctuation, UserInput[Iterator1]) != 0) CounterPunctuation++;
    }

    printf("\n\nConsonants: %d\n", CounterConsonants);
    printf("Vowels: %d\n", CounterVowels);
    printf("Numbers: %d\n", CounterNumbers);
    printf("Punctuations: %d\n", CounterPunctuation);
    printf("Spaces: %d\n", CounterSpaces);

    return 0;
}
