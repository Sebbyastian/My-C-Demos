#include <stdio.h>

void UInt32ToText(const unsigned long int ValueToConvert)
{
  const char *Numbers[] = {"zero",    "one",     "two",       "three",    "four",
                           "five",    "six",     "seven",     "eight",    "nine",
                           "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                           "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                           "twenty",  "thirty",  "fourty",    "fifty",    "sixty",
                           "seventy", "eighty",  "ninety",    "hundred",  "thousand",
                           "million", "billion"
                          };

  const unsigned int BlockLength = 3;

  char NumberString[11];

  int NumberSize = snprintf(NumberString, 11, "%lu", ValueToConvert);

  unsigned int DigitPointer = 0;

  for(DigitPointer = 0; DigitPointer < NumberSize; DigitPointer++)
  {
    unsigned int InverseDigitPointer = (NumberSize - 1) - DigitPointer;
    unsigned int PositionInBlock = InverseDigitPointer % BlockLength;

    printf("NumberString[%d] = ", DigitPointer);
    printf("%d - ", (NumberString[DigitPointer] - '0'));

    if((PositionInBlock == 2) && (NumberString[DigitPointer] > '0'))
      printf("%s %s ", Numbers[NumberString[DigitPointer] - '0'], Numbers[28]);

    if((PositionInBlock == 1) &&
       (NumberString[DigitPointer] == '1'))
      printf("%s ", Numbers[(NumberString[DigitPointer] - '0')
             * 10 + (NumberString[DigitPointer + 1] - '0')]);

    if((PositionInBlock == 1) &&
       (NumberString[DigitPointer] > '1'))
      printf("%s ", Numbers[(NumberString[DigitPointer] - '0') + 18]);

    if(PositionInBlock == 0)
    {
      if((InverseDigitPointer == (NumberSize - 1)))
        printf("%s ", Numbers[NumberString[DigitPointer] - '0']);

      if((InverseDigitPointer < (NumberSize - 1)))
        if((NumberString[DigitPointer - 1] != '1'))
          printf("%s ", Numbers[NumberString[DigitPointer] - '0']);

      if(InverseDigitPointer > 2)
        printf("%s ", Numbers[(InverseDigitPointer / 3) + 28]);
    }

    printf("\n");
  }
}

int main()
{
  unsigned long AmountToCompute = 4294967295;

  printf("%lu\n", AmountToCompute);
  UInt32ToText(AmountToCompute);

  AmountToCompute = 4014967295;
  printf("\n%lu\n", AmountToCompute);
  UInt32ToText(AmountToCompute);

  AmountToCompute = 1;
  printf("\n%lu\n", AmountToCompute);
  UInt32ToText(AmountToCompute);

  AmountToCompute = 12;
  printf("\n%lu\n", AmountToCompute);
  UInt32ToText(AmountToCompute);

  AmountToCompute = 123;
  printf("\n%lu\n", AmountToCompute);
  UInt32ToText(AmountToCompute);

  AmountToCompute = 1234;
  printf("\n%lu\n", AmountToCompute);
  UInt32ToText(AmountToCompute);

  AmountToCompute = 12345;
  printf("\n%lu\n", AmountToCompute);
  UInt32ToText(AmountToCompute);

  AmountToCompute = 123456;
  printf("\n%lu\n", AmountToCompute);
  UInt32ToText(AmountToCompute);

  AmountToCompute = 1234567;
  printf("\n%lu\n", AmountToCompute);
  UInt32ToText(AmountToCompute);

  AmountToCompute = 12345678;
  printf("\n%lu\n", AmountToCompute);
  UInt32ToText(AmountToCompute);

}
