#include <stdio.h>
#include <stdbool.h>
#include "connectn.h"

void get_userMove(char** filled_board, int rows, int columns, int win_condition) {
  int move;
  move = get_validMove(columns, filled_board);
  //printf("%d\n", move);
  board_updater(filled_board, move, rows, columns, win_condition);
}
void board_updater(char** filled_board, int move, int rows, int columns, int win_condition) {
  char turn = 'X';
  bool x_win = false;
  bool o_win = false;
  int win = false;
  // MIGHT NEED TO RESTRUCTURE ENTIRE SECTION!!! ARRAY HAS BEEN REFORMATTED
  while (x_win == false || o_win == false) {
    if (filled_board[rows - 1][move] == '*') {
      filled_board[rows - 1][move] = turn;
      if (turn == 'X') {
        turn = 'O';
      } else if (turn == 'O') {
        turn = 'X';
      }
      print_board(filled_board, rows, columns);
      win = checkWin(filled_board, rows, columns, win_condition, turn);
      if (win == 1) {
        printf("Player 1 Won!\n");
        break;
      } else if (win == 0) {
        printf("Player 2 Won!\n");
        break;
      } else if (win == 3) {
        printf("Tie game!\n");
        break;
      }
      move = get_validMove(columns, filled_board);
    } else if (filled_board[rows - 1][move] == 'X' || filled_board[rows - 1][move] == 'O') {
      // need to make a new function to check if play is valid or not.
      int tempVar = rows - 1;
      while(true) {
        if (filled_board[tempVar][move] == 'X' || filled_board[tempVar][move] == 'O') {
          tempVar = tempVar - 1;
          continue;
        } else if (filled_board[tempVar][move] == '*') {
          filled_board[tempVar][move] = turn;
          break;
        }
      }
      tempVar = 0;
      if (turn == 'X') {
        turn = 'O';
      } else if (turn == 'O') {
        turn = 'X';
      }
      print_board(filled_board, rows, columns);
      win = checkWin(filled_board, rows, columns, win_condition, turn);
      if (win == 1) {
        printf("Player 1 Won!\n");
        break;
      } else if (win == 0) {
        printf("Player 2 Won!\n");
        break;
      } else if (win == 3) {
        printf("Tie game!\n");
        break;
      }
      move = get_validMove(columns, filled_board);
    }
  }
}
int row_win(char** filled_board, int rows, int columns, int win_condition) {
  int i,k;
  int x_count = 0;
  int o_count = 0;
  for (i = 0; i < rows; i++) {
    for (k = 0; k < columns; k++) {
      if (filled_board[i][k] == 'X') {
        x_count++;
        o_count = 0;
        if (x_count == win_condition){
          return 1;
        }
      } else if (filled_board[i][k] == 'O') {
        o_count++;
        x_count = 0;
        if (o_count == win_condition){
          return 0;
        }
      } else if (filled_board[i][k] == '*') {
        x_count = 0;
        o_count = 0;
      }
    }
    x_count = 0;
    o_count = 0;
  }
  return 2;
}
int col_win(char** filled_board, int rows, int columns, int win_condition) {
  int i,k;
  int x_count = 0;
  int o_count = 0;
  for (i = 0; i < columns; ++i) {
    for (k = 0; k < rows; ++k) {
      if (filled_board[k][i] == 'X') {
        x_count++;
        o_count = 0;
        if (x_count == win_condition){
          return 1;
        }
      } else if (filled_board[k][i] == 'O') {
        o_count++;
        x_count = 0;
        if (o_count == win_condition){
          return 0;
        }
      }
    }
    x_count = 0;
    o_count = 0;
  }
  return 2;
}
int left_diag_win (char** filled_board, int rows, int columns, int win_condition, char turn) {
  int a, b, c;
  //int x_count = 0;
  for (a = 0; a < rows; a++) {
    for (b = columns - 1; b > 0; b--) {
      if (filled_board[a][b] == turn) {
        for(c = 0; c < win_condition; c++) {
          if (((a + c) >= rows || (b - c) < 0) || filled_board[a + c][b - c] != turn) {
            break;
          }
        } if (c == win_condition) {
          if (turn == 'X') {
            return 1;
          }
          else if (turn == 'O') {
            return 0;
          }
        }
      }
    }
  }
  return 2;
}
int right_diag_win (char** filled_board, int rows, int columns, int win_condition, char turn) {
  int a, b, c;
  //int x_count = 0;
  for (a = 0; a < rows; a++) {
    for (b = 0; b < columns; b++) {
      if (filled_board[a][b] == turn) {
        for(c = 0; c < win_condition; c++) {
          if (((a + c) >= rows || (b + c) >= columns) || filled_board[a + c][b + c] != turn) {
            break;
          }
        } if (c == win_condition) {
          if (turn == 'X') {
            return 1;
          }
          else if (turn == 'O') {
            return 0;
          }
        }
      }
    }
  }
  return 2;
}
int checkWin (char** filled_board, int rows, int columns, int win_condition, char turn) {
  if (row_win(filled_board, rows, columns, win_condition) == 1 || col_win(filled_board, rows, columns, win_condition) == 1 || right_diag_win(filled_board, rows, columns, win_condition, 'X') == 1 || left_diag_win(filled_board, rows, columns, win_condition, 'X') == 1) {
    return 1;
  } else if (row_win(filled_board, rows, columns, win_condition) == 0 || col_win(filled_board, rows, columns, win_condition) == 0 || right_diag_win(filled_board, rows, columns, win_condition, 'O') == 0 || left_diag_win(filled_board, rows, columns, win_condition, 'O') == 0) {
    return 0;
  } else if (row_win(filled_board, rows, columns, win_condition) == 2 && col_win(filled_board, rows, columns, win_condition) == 2 && right_diag_win(filled_board, rows, columns, win_condition, turn) == 2 && left_diag_win(filled_board, rows, columns, win_condition, turn) == 2) {
    int status = 0;
    for(int i = 0; i < rows; ++i) {
      for (int k = 0; k < columns; ++k) {
        if (filled_board[i][k] != '*') {
          status++;
        } else {
          break;
        }
      }
    }
    if (status == (rows * columns)) {
      return 3;
    }
  }
  return 2;
}
