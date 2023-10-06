#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
// Function is in charge of the final calculations after finding the points in the circle
double finalCalculations (double pointsInCircle, const double iterations) {
  double pi = ((double) pointsInCircle / (double) iterations) * 4; //Formula for pi
  printf("The value of pi is %.3f.\n", pi);
  return 0;
}
double randomNumGenerator (int seed, const int iterations) {
  int i;
  double max = 1;  // max is 1 and min is -1. Since our parameters are (-1,1)
  double min = -1;
  int pointsInCircle = 0;
  srand(seed);  // Sets the seed from the user input to the rand setup
  for (i = 0; i < iterations; ++i){  // Goes through as many times as the user inputted in iterations
    double numberX = ((double) rand()) / RAND_MAX;  // Creates a random number for x
    double numberY = ((double) rand()) / RAND_MAX;  // Creates a random number for y
    double rangeX = (max - min) * numberX;
    double rangeY = (max - min) * numberY;
    double x = min + rangeX;  // Forces the randomized x to be in between -1 and 1
    double y = min + rangeY;  // Forces the randomized y to be in between -1 and 1
    if (pow((double)x,2) + pow((double)y,2) <= 1) { // Formula for finding if the point is in the circle or not
      pointsInCircle = pointsInCircle + 1;  // If the value is true, then adds a unit to pointsInCircle
    } else {
      pointsInCircle = pointsInCircle + 0;  // Honestly, kinda redundant, but here to make sure everything is in working order
    }
  }
  finalCalculations(pointsInCircle, iterations);  // Sends all the needed values to the next function for final calculations
  return 0;
}
bool isValidFormat (const int numArgsRead, const int numArgsNeeded) {
  bool formatIsGood = numArgsRead == numArgsNeeded;  // Checks if the format is correct and checks for any additional
// characters from the user
  char character;
  do {
    scanf("%c", &character);
      if (!isspace(character)) {
        formatIsGood = false;
      }
  } while(character != '\n');  // Forces the user to keep entering inputs until one is valid
  return formatIsGood;
}
int getValidInt (const char* prompt) {
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %d", &num);
  }while(!isValidFormat(numArgsRead, numArgsNeeded));  // Sends the input to the next function to check for
  // additional characters
  return num;
  }
  int getValidInt1 (const char* prompt) {  // Requires different valid int since this can't be negative
    int num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do{
      printf("%s", prompt);
      numArgsRead = scanf(" %d", &num);
      if (num > 0) {
        continue;
      }
      else {
        numArgsRead = 3;
      }
    }while(!isValidFormat(numArgsRead, numArgsNeeded));  // Sends the input to the next function to check for
    // additional characters
    return num;
    }
int main () {
  int seed = getValidInt("Enter the seed for the random number generator: ");
  // Asks for the user input and then activates the getValidInt function
  int iterations = getValidInt1("Enter the number of iterations to run: ");
  // Asks for the user input and then activates the getValidInt function
  randomNumGenerator(seed, iterations);  // Runs the seed and iterations to the fucntions for pi to be calculated

return 0;
}
