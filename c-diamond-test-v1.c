/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    October 12, 2018
    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/
    Programming Language:     C
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10
    Description: This creates a diamond pattern.
*/

#include <stdio.h>

int main()
{
	int Iterator1, Iterator2;
	int rows = 8;

	for (Iterator1 = -rows + 1; Iterator1 < rows; Iterator1++)
	{
		printf("%*s", abs(Iterator1), "");

		for (Iterator2 = (rows - abs(Iterator1)) * 2 - 1; Iterator2 > 0; Iterator2--)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}

