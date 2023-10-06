#include <stdio.h>
#include <math.h>
double thirtysevenPercent(double leftOver, double amountOwed) {
  double tax;
  tax = leftOver * 0.37;
  amountOwed += tax;
  printf("You were taxed 37.00%% on the next $%.2f you made which is $%.2f.\n", leftOver, tax);
  return amountOwed;
}
double thirtyfivePercent(double leftOver, double amountOwed) {
  double tax;
  if (leftOver <= 311050) {
    tax = leftOver * 0.35;
    amountOwed += tax;
    printf("You were taxed 35.00%% on the next $%.2f you made which is $%.2f.\n", leftOver, tax);
    leftOver = 0;
    return amountOwed;
  } else {
    printf("You were taxed 35.00%% on the next $311050.00 you made which is $108867.50.\n");
    leftOver = leftOver - 311050;
    tax = 108867.50;
    amountOwed += tax;
    return thirtysevenPercent(leftOver, amountOwed);
  }
}
double thirtytwoPercent(double leftOver, double amountOwed) {
  double tax;
  if (leftOver <= 44050) {
    tax = leftOver * 0.32;
    printf("You were taxed 32.00%% on the next $%.2f you made which is $%.2f.\n", leftOver, tax);
    leftOver = 0;
    amountOwed += tax;
    return amountOwed;
  } else {
    printf("You were taxed 32.00%% on the next $44050.00 you made which is $14096.00.\n");
    leftOver = leftOver - 44050.00;
    tax = 14096;
    amountOwed += tax;
    return thirtyfivePercent(leftOver, amountOwed);
  }
}
double twentyfourPercent(double leftOver, double amountOwed) {
  double tax;
  if (leftOver <= 77775) {
    tax = leftOver * 0.24;
    amountOwed += tax;
    printf("You were taxed 24.00%% on the next $%.2f you made which is $%.2f.\n", leftOver, tax);
    leftOver = 0;
    return amountOwed;
  } else {
    printf("You were taxed 24.00%% on the next $77775.00 you made which is $18666.00.\n");
    leftOver = leftOver - 77775.00;
    tax = 18666;
    amountOwed += tax;
    return thirtytwoPercent(leftOver, amountOwed);
  }
}
double twentytwoPercent(double leftOver, double amountOwed) {
  double tax;
  if (leftOver <= 45400) {
    tax = leftOver * 0.22;
    printf("You were taxed 22.00%% on the next $%.2f you made which is $%.2f.\n", leftOver, tax);
    leftOver = 0;
    amountOwed += tax;
    return amountOwed;
  } else {
    printf("You were taxed 22.00%% on the next $45400.00 you made which is $9988.00.\n");
    leftOver = leftOver - 45400.00;
    tax = 9988;
    amountOwed += tax;
    return twentyfourPercent(leftOver, amountOwed);
  }
}

double twelvePercent(double leftOver, double amountOwed) {
double tax;
if (leftOver <= 30250) {
  tax = leftOver * 0.12;
  printf("You were taxed 12.00%% on the next $%.2f you made which is $%.2f.\n", leftOver, tax);
  leftOver = 0;
  amountOwed += tax;
  return amountOwed;
} else {
  printf("You were taxed 12.00%% on the next $30250.00 you made which is $3630.00.\n");
  leftOver = leftOver - 30250.00;
  tax = 3630;
  amountOwed += tax;
  return twentytwoPercent(leftOver, amountOwed);
}
}

double tenPercent(double income) {
  double amountOwed = 0;
  double leftOver;
  double tax;
  if (income <= 9875) {
    tax = income * 0.10;
    printf("You were taxed 10.00%% on the first $%.2f you made which is $%.2f.\n", income, tax);
    leftOver = 0;
    amountOwed += tax;
    return amountOwed;
  } else {
    printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
    leftOver = income - 9875.00;
    tax = 987.50;
    amountOwed += tax;
    return twelvePercent(leftOver, amountOwed);
  }
}

int main () {
double income, finalTax, flatTaxRate;
printf("Enter your income for the year: ");
scanf("%lf", &income);
finalTax = tenPercent(income);
flatTaxRate = ((finalTax) / (income)) * 100;
printf("In total you will pay $%.2f in taxes on the $%.2f you made this year.\n", finalTax, income);
printf("This would amount to a FLAT tax of %.2f%% on all of your income.\n", flatTaxRate);
return 0;
}
