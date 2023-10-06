#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
int countWords (FILE* file) {
  char c;
  int wordCount = 0;
  char lastChar = 'a';  // Sets this as some random char
  fscanf(file, "%c", &c);  // Reads the first line
  while(!feof(file)) {
    if (isspace(c) && lastChar != '\n') {  // Checks if there is a space and makes sure there isn't a blank line
      wordCount++;  // Adds 1 to the word count if the condition is true
    }
    lastChar = c;  // Sets the current word as the previous character to be used in the next iteration
    fscanf(file, "%c", &c); // Reads the next line
  }
  return wordCount;
}
int main (int argc, char* argv[]) {
  FILE* file = fopen(argv[1], "r");  // Opens the file from the command line for reading
  int wordCount = countWords(file);  // Sends it to the function to read the character
  printf("There are %d word(s).\n", wordCount);
  fclose(file);  // Closes the file after done
}
