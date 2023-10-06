#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
double finalCalculationsTemp (double origTemperature, char origUnit) {
  char newUnit;
  double newTemperature;
  char x[10];
  printf("Enter the new unit type (F, C, or K): ");
  scanf(" %s", x);
  if (strlen(x) == 1) {
    newUnit = x[0];
    newUnit = toupper(newUnit);
    if (newUnit == 'F' || newUnit == 'C' || newUnit == 'K') {
      if (origUnit == 'F' && newUnit == 'C') {
        newTemperature = (origTemperature - 32) * ((double) 5 / (double) 9);
        printf("%.2f%c is %.2f%c\n", origTemperature, origUnit, newTemperature, newUnit);
      } else if (origUnit == 'F' && newUnit == 'K') {
        newTemperature = (origTemperature - 32) * ((double) 5 / (double) 9) +273.15;
        printf("%.2f%c is %.2f%c\n", origTemperature, origUnit, newTemperature, newUnit);
      } else if (origUnit == 'F' && newUnit == 'F') {
        newTemperature = origTemperature;
        printf("%.2f%c is %.2f%c\n", origTemperature, origUnit, newTemperature, newUnit);
      } else if (origUnit == 'C' && newUnit == 'F') {
        newTemperature = (origTemperature * (1.8)) + 32;
        printf("%.2f%c is %.2f%c\n", origTemperature, origUnit, newTemperature, newUnit);
      } else if (origUnit == 'C' && newUnit == 'C') {
        newTemperature = origTemperature;
        printf("%.2f%c is %.2f%c\n", origTemperature, origUnit, newTemperature, newUnit);
      } else if (origUnit == 'C' && newUnit == 'K') {
        newTemperature = origTemperature + 273.15;
        printf("%.2f%c is %.2f%c\n", origTemperature, origUnit, newTemperature, newUnit);
      } else if (origUnit == 'K' && newUnit == 'F') {
        newTemperature = ((origTemperature - 273.15)*(1.8)) + 32;
        printf("%.2f%c is %.2f%c\n", origTemperature, origUnit, newTemperature, newUnit);
      } else if (origUnit == 'K' && newUnit == 'C') {
        newTemperature = origTemperature - 273.15;
        printf("%.2f%c is %.2f%c\n", origTemperature, origUnit, newTemperature, newUnit);
      } else if (origUnit == 'K' && newUnit == 'K') {
        newTemperature = origTemperature;
        printf("%.2f%c is %.2f%c\n", origTemperature, origUnit, newTemperature, newUnit);
      }
    }
    else {
      printf("%c is not a valid temperature type. Ending program.\n", newUnit);
      exit(0);
    }
  } else {
    printf("Invalid formatting. Ending program.\n");
    exit(0);
  }

  return 0;
}
double finalCalculationsDistance (double origDistance, char origUnit) {
  char newUnit;
  double newDistance;
  char x[10];
  printf("Enter the new unit type (I,F,Y,M): ");
  scanf(" %s", x);
  if (strlen(x) == 1) {
    newUnit = x[0];
    newUnit = toupper(newUnit);
    if (newUnit == 'I' || newUnit == 'F' || newUnit == 'Y' || newUnit == 'M') {
      if (origUnit == 'I' && newUnit == 'I') {
        newDistance = origDistance;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'I' && newUnit == 'F') {
        newDistance = origDistance / (double) 12;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'I' && newUnit == 'Y') {
        newDistance = origDistance / (double) 36;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'I' && newUnit == 'M') {
        newDistance = origDistance / (double) 63360;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'F' && newUnit == 'I') {
        newDistance = origDistance * 12;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'F' && newUnit == 'F') {
        newDistance = origDistance;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'F' && newUnit == 'Y') {
        newDistance = origDistance / (double) 3;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'F' && newUnit == 'M') {
        newDistance = origDistance / (double) 5280;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'Y' && newUnit == 'I') {
        newDistance = origDistance * 36;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'Y' && newUnit == 'F') {
        newDistance = origDistance * 3;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'Y' && newUnit == 'Y') {
        newDistance = origDistance;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'Y' && newUnit == 'M') {
        newDistance = origDistance / (double) 1760;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'M' && newUnit == 'I') {
        newDistance = origDistance * 63360;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'M' && newUnit == 'F') {
        newDistance = origDistance * 5280;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'M' && newUnit == 'Y') {
        newDistance = origDistance * 1760;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      } else if (origUnit == 'M' && newUnit == 'M') {
        newDistance = origDistance;
        printf("%.2f%c is %.2f%c\n", origDistance, origUnit, newDistance, newUnit);
      }
    } else {
      printf("%c is not a valid distance type. Ending program.\n", newUnit);
      exit(0);
    }
  } else {
    printf("Invalid formatting. Ending program.\n");
    exit(0);
  }

  return 0;
}
double temperatureConversion () {
  double origTemperature;
  char origUnit;
  char x[10];
  printf("Enter the temperature followed by its suffix (F, C, or K): ");
  scanf(" %lf %s", &origTemperature, x);
  if (strlen(x) == 1) {
    origUnit = x[0];
    origUnit = toupper(origUnit);
    if (origUnit == 'F' || origUnit == 'C' || origUnit == 'K') {
      //printf("Enter the new unit type (F, C, or K): ");
      //scanf(" %c", &newUnit);
      //newUnit = toupper(newUnit);
      finalCalculationsTemp(origTemperature, origUnit);
    } else {
      printf("%c is not a valid temperature type. Ending program.\n", origUnit);
      exit(0);
    }
  } else {
    printf("Invalid formatting. Ending program.\n");
    exit(0);
  }

  return 0;
}
double distanceConversion () {
  double origDistance;
  char origUnit;
  char x[10];
  printf("Enter the distance followed by its suffix (I,F,Y,M): ");
  scanf(" %lf %s", &origDistance, x);
  if (strlen(x) == 1) {
    origUnit = x[0];
    origUnit = toupper(origUnit);
    if (origUnit == 'I' || origUnit == 'F' || origUnit == 'Y' || origUnit == 'M') {
      //printf("%lf %c\n", origDistance, origUnit);
      finalCalculationsDistance(origDistance, origUnit);
    } else {
      printf("%c is not a valid distance type. Ending program.\n", origUnit);
      exit(0);
    }
  } else {
    printf("Invalid formatting. Ending program.\n");
    exit(0);
  }

  return 0;
}
bool choiceOneLetter (char userChoice) {
  if (userChoice == 'T' || userChoice == 't') {
    temperatureConversion();
    return 0;
} else if (userChoice == 'D' || userChoice == 'd') {
    distanceConversion();
    return 0;
} else {
    printf("Unknown conversion type %c chosen. Ending program.\n", userChoice);
    exit(0);
  }
  return 0;
}
int choiceOne () {
  char x[10];
  char userChoice;
  scanf(" %s", x);
  if (strlen(x) == 1) {
    userChoice = x[0];
    choiceOneLetter(userChoice);
  } else {
    printf("Invalid formatting. Ending program.\n");
    exit(0);
  }
  return 0;
}

int main () {
   //char userInput[100];
   //char userChoice
printf("Pick the type of conversion that you would like to do.\n");
printf("T or t for temperature\n");
printf("D or d for distance\n");
printf("Enter your choice: ");
choiceOne();

return 0;
}
