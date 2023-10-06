#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "connectn.h"
bool isValidFormat (const int numArgsRead, const int numArgsNeeded) {
  bool formatIsGood = numArgsRead == numArgsNeeded;
  char character;
  do {
    scanf("%c", &character);
      if (!isspace(character)) {
        formatIsGood = false;
      }
  } while(character != '\n');
  return formatIsGood;
}
int get_validMove(int columns, char** filled_board) {
  int num;
  columns = columns - 1;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("Enter a column between 0 and %d to play in: ", columns);
    numArgsRead = scanf(" %d", &num);
    if ((num >= 0) && (num <= columns) && !(filled_board[0][num] == 'X' || filled_board[0][num] == 'O')) {
      continue;
    }
    else {
      numArgsRead = 3;
    }
  }while(!isValidFormat(numArgsRead, numArgsNeeded));
  return num;
  }
