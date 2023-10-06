#include <stdio.h>
int main () {
double inum1;
double num1;
double inum2;
double num2;
double finalnum;
double finali;
printf("Enter the first complex number in the form ai + b: ");
scanf(" %lf i + %lf", &inum1, &num1);
printf("Enter the second complex number in the form ai + b: ");
scanf(" %lf i + %lf", &inum2, &num2);
finali = num1 * inum2 + num2 * inum1;
finalnum = num1 * num2 - inum1 * inum2;
printf("(%.0fi + %.0f) * (%.0fi + %.0f) = %.0fi + %.0f\n", inum1, num1, inum2, num2, finali, finalnum);
return 0;
}
