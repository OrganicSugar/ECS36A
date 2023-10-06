#include <stdio.h>
#include <stdlib.h>
#include "connectn.h"
void get_board_dimensions(int* arguments, char** argv, int* rows, int* columns, int* win_condition) {
  if ((*arguments) > 4) {
    printf("Too many arguments entered\n");
    printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);
  } else if ((*arguments) < 4) {
    printf("Not enough arguments entered\n");
    printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);
  } else if ((*arguments) == 4); {
    *rows = atoi(argv[1]);
    *columns = atoi(argv[2]);
    *win_condition = atoi(argv[3]);
    //printf("%d, %d\n", *rows, *columns);
    if (*rows < 0 || *columns < 0 || *win_condition < 0) {
      printf("Arguments must be a positive integer\n");
      printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
      exit(0);
  }
}
}
char** create_empty_matrix(int rows, int columns) {
	int i;
  //rows += 1;
  //columns += 1;
	char** empty_board = malloc(rows * sizeof(char*));
	for (i = 0; i < rows; ++i) {
    empty_board[i] = malloc(columns * sizeof(char));
	}
	return empty_board;
}
void create_board(char** filled_board, int rows, int columns) {
  //rows += 1;
  //columns += 1;
  int i,k;
  for (i = 0; i < rows; i++) {
    for (k = 0; k < columns; k++) {
      filled_board[i][k] = '*';
    }
  }
}
void print_board(char** filled_board, int rows, int columns) {
  //rows += 1;
  //columns += 1;
  int i,k;
  for (i = 0; i < rows + 1; ++i) {
    if (rows < 10) {
      if (i != rows) {
        printf("%d", rows - i - 1);
      } else {
        printf(" ");
      }
    } else if (rows > 10) {
      if (i != rows && i >= 10) {
        printf(" %d", rows - i - 1);
      } else if (i != rows && i < 10) {
        printf("%d", rows - i - 1);
      } else {
        printf(" ");
      }
    }
    for (k = 0; k < columns; ++k) {
      if (rows < 10) {
        if (i != rows) {
          printf(" %c", filled_board[i][k]);
        } else {
          printf(" %d", k);
        }
      }
      else if (rows > 10) {
        if (i != rows) {
          printf("  %c", filled_board[i][k]);
        } else if (k >= 10) {
          printf(" %d", k);
        } else if (k == 0) {
          printf("   %d", k);
        } else {
          printf("  %d", k);
        }
      }
    }
    printf("\n");
  }
}
void delete_board(char*** board, int rows, int columns) {
	for(int i = 0; i < rows; ++i) {
     free((*board)[i]);
  }
  free(*board);
	*board = NULL;
}
