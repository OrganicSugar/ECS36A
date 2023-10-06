#include <stdio.h>
int main () {
  int rows, columns; // Sets a variable to the rows and columns
  int a[100][100], b[100][100], total[100][100];
  int i, k; // The i is the column that the array is set at, while the k is place along that row
  // Get the rows and columns
  printf("Please enter the number of rows: ");
  scanf("%d", &rows);
  printf("Please enter the number of columns: ");
  scanf("%d", &columns);
  printf("Enter Matrix A\n");
  // Gets the input for matrix A
  for (i = 0; i < rows; ++i) {
    // Starts the first row of the array of Matrix A
      for (k = 0; k < columns; ++k) {
        // Then for each column along that row, it gets the user input and sets it to that i and k
        scanf(" %d", &a[i][k]);
      }
    }
  printf("Enter Matrix B\n");
  // Gets the input for matrix B
  for (i = 0; i < rows; ++i) {
    // Starts the first row of the array of Matrix B
      for (k = 0; k < columns; ++k) {
        // Then for each column along that row, it gets the user input and sets it to that i and k
        scanf(" %d", &b[i][k]);
      }
    }
  // Adding the matrix
  for (i = 0; i < rows; ++i) {
    // For each row of both array
    for (k = 0; k < columns; ++k) {
      // For each column of that row in both arrays, we add them up to equal a new total value
      total[i][k] = (a[i][k] + b[i][k]);
    }
  }
  // Printing the Output after the addition
  printf("A + B =\n");
  for (i = 0; i < rows; ++i) {
    // For each row of the total array
    for (k = 0; k < columns; ++k) {
      // For each column of the total array print out the given value from the total array
      printf("%d ", total[i][k]);
      if (k == (columns - 1)) {  // Adds a newline after the first row of the Matrix is complete
        printf("\n");
      }
    }
  }
  return 0;
}
