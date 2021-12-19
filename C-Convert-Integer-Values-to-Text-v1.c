#include <stdio.h>

//  UInt32ToText
//  UNSIGNED 32-BIT INTEGER TO TEXT
void UInt32ToText(const unsigned long int ValueToConvert)
{
  //  WE ONLY NEED ONE ARRAY TO STORE ALL THE POSSIBLE TEXTUAL WORDS FOR NUMBERS. THIS
  //  MAKES IT EASIER TO USE IN OUR LOGIC. WE WANT TO MAKE THIS A CONSTANT CHAR ARRAY
  //  BECAUSE THE DATA NEVER CHANGES.
  const char *Numbers[] = {"zero",    "one",     "two",       "three",    "four",
                           "five",    "six",     "seven",     "eight",    "nine",
                           "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                           "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                           "twenty",  "thirty",  "fourty",    "fifty",    "sixty",
                           "seventy", "eighty",  "ninety",    "hundred",  "thousand",
                           "million", "billion"
                          };

  //  THE BLOCK LENGTH IS HOW MANY DIGITS ARE GROUPED, WHICH NORMALLY IS THREE: THE
  //  HUNDREDS, TENS, AND ONES POSITIONS: (I.E.  4'294'967'295)
  //  THIS NEEDS TO BE CONST SINCE IT WILL NOT CHANGE.
  //  WE WANT TO USE AN UNSIGNED INT AS WE DO NOT WANT TO DEAL WITH NEGATIVE NUMBERS.
  const unsigned int BlockLength = 3;

  //  A 32-BIT UNSIGNED INTEGER ONLY CONTAINS 10 CHARACTERS, AND WE NEED THE 11TH FOR
  //  THE '\0' END OF THE STRING CHARACTER
  char NumberString[11];

  //  THE SNPRINTF STATEMENT CONVERTS A NUMBER TO A CHAR STRING, STORES IT IN A PREDEFINED
  //  STRING VARIABLE AND RETURNS THE SIZE OF THE STRING, INCLUDING THE '\0' CHARACTER.
  int NumberSize = snprintf(NumberString, 11, "%lu", ValueToConvert);

  //  THE DIGIT POINTER IS SIMPLY A NUMERICAL POINTER THAT KEEPS TRACK OF THE CURRENT
  //  POSITION WE ARE IN IN THE NUMBER CHAR ARRAY. HERE'S A TEXTUAL CHART TO EXPLAIN:
  //
  //  THE "INDEX" IS THE INDEX OF THE CHAR ARRAY (32-BIT INTEGER)
  //  THE "VALUE" IS THE VERBAL NAMED NUMBER POSITIONS
  //  THE "PIB" IS THE "POSITION IN BLOCK"
  //
  //    PIB:   2   0   1   2   0   1   2   0   1   2   <-- THIS IS THE
  //         K---|---BLOCK---|---BLOCK---|---BLOCK---|     WRONG ORDER
  //  INDEX: : 0 | 1 : 2 : 3 | 4 : 5 : 6 | 7 : 8 : 9 |
  //  -------:---|---:---:---|---:---:---|---:---:---|
  //  VALUE: : O | H : T : O | H : T : O | H : T : O |
  //         : N | U : E : N | U : E : N | U : E : N |
  //         : E | N : N : E | N : N : E | N : N : E |
  //         :   | D :   :   | D :   :   | D : S : S |
  //         : B | R : M : M | R : T : T | R :   :   |
  //         : I | E : I : I | E : H : H | E :   :   |
  //         : L | D : L : L | D : O : O | D :   :   |
  //         : L |   : L : L |   : U : U | S :   :   |
  //         : I | M : I : I | T : S : S |   :   :   |
  //         : O | I : O : O | H : A : A |   :   :   |
  //         : N | L : N : N | O : N : N |   :   :   |
  //         :   | L :   :   | U : D : D |   :   :   |
  //         :   | I :   :   | S :   :   |   :   :   |
  //         :   | O :   :   | A :   :   |   :   :   |
  //         :   | N :   :   | N :   :   |   :   :   |
  //         :   |   :   :   | D :   :   |   :   :   |
  //         K---|---BLOCK---|---BLOCK---|---BLOCK---|

  unsigned int DigitPointer = 0;

  //  WHEN WE LOOP THROUGH THE NUMBERS, WE WILL ACCESS THEM FROM LEFT TO RIGHT, WITH THE
  //  LEFT-MOST DIGIT BEING OF THE HIGHEST NUMERICAL VALUE.
  for(DigitPointer = 0; DigitPointer < NumberSize; DigitPointer++)
  {
    //  THE INVERSE-DIGIT-POINTER FLIPS THE DIGIT-POINTER VALUE SO THE ONES LOCATION WILL
    //  BE AT OFFSET 0 INSTEAD OF THE END OF THE NUMBER STRING. HERES A TEXTUAL CHART TO EXPLAIN:
    //
    //  THE "PIB" IS THE "POSITION IN BLOCK"
    //
    //    PIB:   0   2   1   0   2   1   0   2   1   0   <-- NOW THIS IS
    //         K---|---BLOCK---|---BLOCK---|---BLOCK---|     THE CORRECT
    //  INDEX: : 9 | 8 : 7 : 6 | 5 : 4 : 3 | 2 : 1 : 0 |     ORDER
    //  -------:---|---:---:---|---:---:---|---:---:---|
    //  VALUE: : O | H : T : O | H : T : O | H : T : O |
    //         : N | U : E : N | U : E : N | U : E : N |
    //         : E | N : N : E | N : N : E | N : N : E |
    //         :   | D :   :   | D :   :   | D : S : S |
    //         : B | R : M : M | R : T : T | R :   :   |
    //         : I | E : I : I | E : H : H | E :   :   |
    //         : L | D : L : L | D : O : O | D :   :   |
    //         : L |   : L : L |   : U : U | S :   :   |
    //         : I | M : I : I | T : S : S |   :   :   |
    //         : O | I : O : O | H : A : A |   :   :   |
    //         : N | L : N : N | O : N : N |   :   :   |
    //         :   | L :   :   | U : D : D |   :   :   |
    //         :   | I :   :   | S :   :   |   :   :   |
    //         :   | O :   :   | A :   :   |   :   :   |
    //         :   | N :   :   | N :   :   |   :   :   |
    //         :   |   :   :   | D :   :   |   :   :   |
    //         K---|---BLOCK---|---BLOCK---|---BLOCK---|

    unsigned int InverseDigitPointer = (NumberSize - 1) - DigitPointer;

    //  GET THE CURRENT POSITION IN THE NUMBER BLOCK (I.E: 0, 1, OR 2)
    //  WE WANT TO GET THE CURRENT POSITION OF THE INVERSED INDEX POINTER
    unsigned int PositionInBlock = InverseDigitPointer % BlockLength;

    //  THESE PRINTF STATEMENTS CAN BE REMOVED, OR COMMENTED OUT, IF YOU WANT TO
    //  TO PRINT THE NUMBER VERBIAGE IN A STRAIGHT LINE
    printf("NumberString[%d] = ", DigitPointer);
    printf("%d - ", (NumberString[DigitPointer] - '0'));

    //  CHECK TO SEE IF WE ARE IN THE SECOND (HUNDREDS) POSITION IN THE CURRENT
    //  BLOCK, AND SEE IF THE HUNDREDS VALUE IS GREATER THE ZERO. IF IT IS, THEN
    //  PRINT THE SINGLE DIGIT NAME (I.E: ONE) AND THE WORD, "HUNDRED", WHICH IS
    //  AT THE INDEX OF 28 IN THE NUMBER NAMES ARRAY.
    //  THE "-'0'" PART OF THE EQUATION TURNS THE ASCII '0' TO A NUMERICAL VALUE.
    //  THE '0' EQUATES TO &H30 (HEXIDECIMAL) OR 48 IN DECIMAL.
    if((PositionInBlock == 2) && (NumberString[DigitPointer] > '0'))
      printf("%s %s ", Numbers[NumberString[DigitPointer] - '0'], Numbers[28]);

    //  CHECK TO SEE IF WE ARE IN THE FIRST (TENS) POSITION IN THE CURRENT BLOCK.
    //  IF WE ARE AND THE CURRENT NUMBER IN THE INDEX POSITION IS ONE, THEN WE
    //  WANT TO PRINT THE TWO DIGIT NAME (FROM: TEN TO NINETEEN)
    //  THE "-'0'" PART OF THE EQUATION TURNS THE ASCII '0' TO A NUMERICAL VALUE.
    //  THE '0' EQUATES TO &H30 (HEXIDECIMAL) OR 48 IN DECIMAL.
    if((PositionInBlock == 1) &&
       (NumberString[DigitPointer] == '1'))
      printf("%s ", Numbers[(NumberString[DigitPointer] - '0')
             * 10 + (NumberString[DigitPointer + 1] - '0')]);

    //  CHECK TO SEE IF WE ARE IN THE FIRST (TENS) POSITION IN THE CURRENT BLOCK.
    //  IF WE ARE AND THE CURRENT NUMBER IN THE INDEX POSITION IS GREATER THEN ONE,
    //  THEN WE WANT TO PRINT THE TENS NAME (TWENTY TO NINETY). WHEN TRUE, THE VALUE
    //  WILL BE A MINIMUM OF TWO, SO WE WANT TO ADD EIGHTEEN TO IT TO MAKE TWENTY.
    if((PositionInBlock == 1) &&
       (NumberString[DigitPointer] > '1'))
      printf("%s ", Numbers[(NumberString[DigitPointer] - '0') + 18]);

    //  CHECK TO SEE IF WE ARE IN THE ZERO (ONES) POSITION IN THE CURRENT BLOCK.
    if(PositionInBlock == 0)
    {
      //  CHECK TO SEE IF THE INVERSE-DIGIT-POINTER IS EQUAL TO THE LARGEST INDEX,
      //  AND IF SO, THEN WE KNOW THERE ARE NO TENS POSITION AFTERWARDS, SO WE CAN
      //  SAFELY PRINT THE ONES VALUE WITHOUT CHECK IF IT IS PART OF THE 'TEENS'
      //  VALUES.
      if((InverseDigitPointer == (NumberSize - 1)))
        printf("%s ", Numbers[NumberString[DigitPointer] - '0']);

      //  CHECK TO SEE IF THE INVERSE-DIGIT-POINTER IS LESS THEN THE LARGEST INDEX.
      //  IF IT IS, THEN WE ARE SAFE TO CHECK THE TENS POSITION.
      if((InverseDigitPointer < (NumberSize - 1)))
        //  CHECK THE TENS POSITION TO MAKE SURE IT IS NOT ONE
        if((NumberString[DigitPointer - 1] != '1'))
          //  SINCE THE TENS POSITION IS NOT ONE, WE CAN SAFELY PRINT THE SINGLE
          //  ONES NUMBER VERBIAGE.
          printf("%s ", Numbers[NumberString[DigitPointer] - '0']);

      //  CHECK TO SEE IF THE INVERSE-DIGIT-POINTER IS GREATER THEN TWO.
      if(InverseDigitPointer > 2)
        //  SINCE THE INVERSE-DIGIT-POINTER IS GREATER THEN TWO, THE WE CAN SAFELY
        //  PRINT THE BLOCK SECTION'S NUMERICAL NAME (I.E: THOUSANDS, MILLIONS,
        //  BILLIONS, ETC...).
        printf("%s ", Numbers[(InverseDigitPointer / 3) + 28]);
    }

    //  THIS PRINTF STATEMENT CAN BE REMOVED, OR COMMENTED OUT, IF YOU WANT TO
    //  TO PRINT THE NUMBER VERBIAGE IN A STRAIGHT LINE
    printf("\n");
  }
}

int main()
{
  //
  //  THIS SECTION SHOULD BE EASILY UNDERSTANDABLE, AND IT WILL NOT BE EXPLAINED.
  //

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
