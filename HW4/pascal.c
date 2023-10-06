#include <stdio.h>
int pascalTriangle (int levels) {
  // Create an array to store the values for the triangle
  int triangle[levels][levels], row, i; // i is the each number in the row
  // Creates a Row for each of the level
  for(row = 0; row < levels; ++row) {
    // Then Goes through the row individually to assign values
    for(i = 0; i <= row; ++i){
      if (row == 1 || i == 0) {
        // The first value for the row will always be 1
        triangle[row][i] = 1;
        printf("%d ", triangle[row][i]);
      } else if (i == row) {
        // The last value will also always be 1, and the row length is equal to the level of the row!
        triangle[row][i] = 1;
        printf("%d ", triangle[row][i]);
      } else {
        /* For each value in between, the calculation is simple. You go up a row, and then add that
        to the value that also up a row, but back by 1 place */
        triangle[row][i] = triangle[row - 1][i] + triangle[row - 1][i - 1];
        printf("%d ", triangle[row][i]);
      }
    }
    printf("\n");
  }
  return 0;
}
int main () {
  // Get user input for the amount of levels of the triangle and sends it to the pascalTriangle function
  int levels;
  printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
  scanf("%d", &levels);
  pascalTriangle(levels);
}
