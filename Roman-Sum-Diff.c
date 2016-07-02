#include <stdio.h>
#include <string.h>

int Roman_to_Arabic(char *array) {
  int Roman_I = 1;
  int Roman_V = 5;
  int Roman_X = 10;
  int Roman_L = 50;
  int Roman_C = 100;
  int Roman_D = 500;
  int Roman_M = 1000;
  int Running_Result = 0;
  
  for (int i = 0; array[i] != '\0'; ++i) {
  
    switch (array[i]) {
      case 'I':
        Running_Result += Roman_I;
      break;
      case 'V':
        Running_Result += Roman_V;
        if (array[i-1] == 'I') {
          Running_Result -= 2*Roman_I;
        }
      break;
      case 'X':
        Running_Result += Roman_X;
        if (array[i-1] == 'I') {
          Running_Result -= 2*Roman_I;
        } 
      break;
      case 'L':
        Running_Result += Roman_L;
        if (array[i-1] == 'X') {
          Running_Result -= 2*Roman_X;
        } 
      break;
      case 'C':
        Running_Result += Roman_C;
        if (array[i-1] == 'X') {
          Running_Result -= 2*Roman_X;
        } 
      break;
      case 'D':
        Running_Result += Roman_D;
        if (array[i-1] == 'C') {
          Running_Result -= 2*Roman_C;
        }  
      break;
      case 'M':
        Running_Result += Roman_M;
        if (array[i-1] == 'C') {
          Running_Result -= 2*Roman_C;
        } 
      break;
      default:
      printf("Please enter a valid All-Caps Roman Numeral\n");
      break;
    }
  }
  return Running_Result;
}

void Arabic_to_Roman(int num) {
  int Arabic_Key_Values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  char *Roman_Key_Values[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  char result[64] = "\0";
  int i = 0;

  while (num) {
    while (num/Arabic_Key_Values[i]) {
      strcat(result, Roman_Key_Values[i]);
      num -= Arabic_Key_Values[i];
    }
    i++;
  }
  puts(result);
}

int main() {
  char Input_Roman_Numeral_1[1000], Input_Roman_Numeral_2[1000];
  int num1, num2, sum, diff;

  // Recieve two Roman Numbers between 1 and 1000
  printf("Please enter a Roman numeral in all-caps, I (or 1) to M (or 1,000):\n");
  gets(Input_Roman_Numeral_1);
  printf("Please enter a second Roman numeral (smaller) in all-caps, I (or 1) to M (or 1,000):\n");
  gets(Input_Roman_Numeral_2);

  // Convert the two Roman Numbers to equivalent Arabic Numbers
  num1 = Roman_to_Arabic(Input_Roman_Numeral_1);
  num2 = Roman_to_Arabic(Input_Roman_Numeral_2);

  // Debugging Check to be commented out later
  printf("Your first Roman Number in Arabic = %d\n", num1);
  printf("Your second Roman Number in Arabic = %d\n", num2);

  // Perform Addition and Subtraction
  sum = num1 + num2;
  printf("The Arabic sum = %d\n", sum);
  diff = num1 - num2;
  printf("The Arabic diff = %d\n", diff);

  // Convert and Output the sum/diff Roman results
  printf("The Roman Sum = ");
  Arabic_to_Roman(sum);
  if (diff >= 0) {
    printf("The Roman Difference = ");
    Arabic_to_Roman(diff);
  }
  else {
  printf("The Romans did not use negative numbers!\n");
  }    

  return 0;
}
