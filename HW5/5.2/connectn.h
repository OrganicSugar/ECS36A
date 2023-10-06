#ifndef CONNECTN_H
  #define CONNECTN_H
  void get_board_dimensions(int* arguments, char** argv, int* rows, int* columns, int* win_condition);
  char** create_empty_matrix(int rows, int columns);
  void create_board(char** filled_board, int rows, int columns);
  void print_board(char** filled_board, int rows, int columns);
  void get_userMove(char** filled_board, int rows, int columns, int win_condition);
  int get_validMove(int columns, char** filled_board);
  void board_updater(char** filled_board, int move, int rows, int columns, int win_condition);
  int checkWin (char** filled_board, int rows, int columns, int win_condition, char turn);
  void delete_board(char*** board, int rows, int columns);

#endif
