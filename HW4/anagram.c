#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
bool checkLetters (char* wordOne, char* wordTwo) {
  // To check if the letters in a word that are the same length are the same
  int i = 0, wordOneTotal = 1, wordTwoTotal = 1;
  // Create another way to store the lower case values of the string
  char wordOneLower[20];
  char wordTwoLower[20];
  // The following while loop continues until the array hits a null value
  while (wordOne[i] != '\0' && wordTwo[i] != '\0') {
    // Using the hint, I multiplied up the total of the words since each letter has it's own distinct value
    // Lowercase the letters in the strings since upper case and lower strings have different number values
    // So to ensure proper multiplication, I need to lower case the strings so the program can be case insensitive'
    // Multiplcation over addition since addition gives a chance for the strings to be the same by chance
    wordOneLower[i] = tolower(wordOne[i]);
    wordTwoLower[i] = tolower(wordTwo[i]);
    wordOneTotal = wordOneLower[i] * wordOneTotal;
    wordTwoTotal = wordTwoLower[i] * wordTwoTotal;
    ++i;
  }
  /* Then I compared the two final values and returned false if they didn't add up to the same number
  meaning that there was a different letter */
  //printf("%d, %d\n", wordOneTotal, wordTwoTotal); //Used for testing purposes
  if (wordOneTotal != wordTwoTotal) {
    return false;
  }
  // Otherwise, the entire function would return true
  return true;
}
int checkLength (char* wordOne, char* wordTwo) {
  // This function's goal is to check the length of the words using strlen
  bool valid;
  /* If the length of the strings are the same, then it can move on, if it doesn't then it
  can't be an anagram */
  if (strlen(wordOne) == strlen(wordTwo)){
    valid = checkLetters(wordOne, wordTwo);
    /* If the lengths are the same, sends the strings to next function
    in order to check if the letters in the string are the same */
    if (valid == true) {  // If the bool function return true, then the strings are an anagram
      printf("%s is an anagram of %s\n", wordOne, wordTwo);
    } else {  // if the letters aren't the same, then they can't be an anagram
      printf("%s is NOT an anagram of %s\n", wordOne, wordTwo);
    }
  } else {
    printf("%s is NOT an anagram of %s\n", wordOne, wordTwo);
  }
  return 0;
}
int main () {
  // Gets the user input of the two string, with a 20 character limit
  char wordOne[20];
  char wordTwo[20];
  printf("Please enter the first word: ");
  scanf("%s", wordOne);
  printf("Please enter the second word: ");
  scanf("%s", wordTwo);
  checkLength(wordOne, wordTwo);
  return 0;
}
