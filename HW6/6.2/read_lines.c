#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "read_lines.h"


void read_lines(FILE* fp, char*** lines, int* num_lines) {
  // This section reads the total amount of characters in the file in oder to properly allocate memory!
  char c;
  int characterCount = 0;
  fscanf(fp, "%c", &c);  // Reads the first line
  while(!feof(fp)) {
    characterCount++;
    fscanf(fp, "%c", &c); // Reads the next line
  }
  rewind(fp);  // Rewinds the file so it can be read again.
  *num_lines = 0;
  (*lines) = malloc(sizeof(char*));  // Allocates the memory for the first line
  char current_line[characterCount];  // Provides a buffer for the fgets fucntion to use
  while (fgets(current_line, characterCount, fp) && !feof(fp)) {  // Reads through the strings of the file
    int line_length = strlen(current_line);  // Finds out the length of the string
    (*lines)[*num_lines] = malloc(sizeof(char) * (line_length + 1));  // Adds memory for that string
    strcpy((*lines)[*num_lines], current_line);  // Then puts the string into the array
    (*num_lines)++;  // Increase the number of lines
    *lines = realloc(*lines, sizeof(char*) * ((*num_lines) + 1));  // Adds memory for the next line
    }
    *lines = realloc(*lines, sizeof(char*) * (*num_lines));  /* This is to resize the memory allocation
    when the last line is hit and an extra line of memory is allocated, prevents over usage of memory */
  }
