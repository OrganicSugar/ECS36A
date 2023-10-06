#include <stdio.h>
#include <string.h>

void checkBinaryString (char* givenString, int tempVar) {
  if (tempVar == strlen(givenString)) {
    printf("%s\n", givenString);
    return;
  }
  if (givenString[tempVar] == 'x' || givenString[tempVar] == 'X') {
    givenString[tempVar] = '0';
    checkBinaryString(givenString, tempVar + 1);
    givenString[tempVar] = '1';
    checkBinaryString(givenString, tempVar + 1);
    // Needs this last part in order to get a couple missing combinations
    givenString[tempVar] = 'x';
  }
  else {
    checkBinaryString(givenString, tempVar + 1);
  }
}
int main (int argc, char* argv[]) {
  // Sets a temporary variable to 0 to be used to check each char in the string
  int tempVar = 0;
  checkBinaryString(argv[1], tempVar);
  return 0;
}
