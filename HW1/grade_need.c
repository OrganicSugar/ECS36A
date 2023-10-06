#include <stdio.h>
int main () {
  char wantGrade;
  double percentNeeded;
  double currentPercent;
  double finalWeight;
  double finalExam;
  printf("Enter the grade you want in the class: ");
  scanf("%s", &wantGrade);
  printf("Enter the percent you need to get that grade: ");
  scanf("%lf", &percentNeeded);
  printf("Enter your current percent in the class: ");
  scanf("%lf", &currentPercent);
  printf("Enter the weight of the final: ");
  scanf("%lf", &finalWeight);
  finalExam = (percentNeeded - ((1 - (finalWeight / 100)) * currentPercent)) /
  (finalWeight / 100);
  printf("You need to get at least %.2f%% on the final to get a %c in the class.\n", finalExam, wantGrade);
}
