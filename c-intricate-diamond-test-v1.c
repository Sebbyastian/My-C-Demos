/*
    Written by:  Walter Whitman aka Waltersmind aka The Joyful Programmer
    October 20, 2019
    My website: http://www.TheJoyfulProgrammer.com/
    FaceBook:   https://www.facebook.com/thejoyfulprogrammer/
    Twitter:  	https://twitter.com/TheJoyfulProg
    YouTube:    https://www.youtube.com/thejoyfulprogrammer
    Pinterest:  https://www.pinterest.com/waltersmind/
    GitHub:     https://github.com/TheJoyfulProgrammer/
    Programming Language:     C
    Tested Compilers:         G++ ver 8, MingW W64 GCC-8.1.0 x86_64-win32-seh
    Tested Operating Systems: Linux Mint 19, Windows 7, Windows 10
    Description: This creates an intricate diamond pattern.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int Iterator1, Iterator2, rows = 8;

	printf("\n  QUANDRANT SIZE: %d\n\n", rows);

	for (Iterator1 = -rows + 1; Iterator1 < rows; Iterator1++)
	{
		printf("   %*s", abs(Iterator1), "");

		for (Iterator2 = (rows - abs(Iterator1)) * 2 - 1; Iterator2 > 0; Iterator2--)
		{
			(Iterator2 != (rows - abs(Iterator1))) && (Iterator1 != 0) ? printf("*")
							:  (Iterator1 == 0) && (Iterator2 == rows) ? printf("+")
							:  ((Iterator1 == 0) && (Iterator2 != rows)) && ((Iterator2 > 1) && (Iterator2 < (rows * 2 - 1))) ? printf("-")
							:  (Iterator2 == (rows * 2 - 1)) ? printf("<")
							:  (Iterator2 == 1) && (Iterator1 == 0) ? printf(">")
							:  (abs(Iterator1) == rows - 1) && (Iterator1 < 0) ? printf("^")
							:  (Iterator1 == rows - 1) ? printf("V")
							:  printf("|");
		}

		printf("\n");
	}
}

