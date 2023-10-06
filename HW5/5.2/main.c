#include <stdio.h>
#include "connectn.h"
int main(int argc, char* argv[]) {
  char** board;
  int num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win;
  int arguments = argc;
  get_board_dimensions(&arguments, argv, &num_rows, &num_columns, &number_of_pieces_in_a_row_needed_to_win);
  board = create_empty_matrix(num_rows, num_columns);
  create_board(board, num_rows, num_columns);
  print_board(board, num_rows, num_columns);
  get_userMove(board, num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win);
  //board_updater(board, move, num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win);
  delete_board(&board, num_rows, num_columns);
  return 0;
}
