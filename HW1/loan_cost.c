#include <stdio.h>
#include <math.h>
int main () {
  double moneyBorrowed;
  double interest;
  double trueInterest;
  double numberPayments;
  double payment;
  double total;
  double cost;
  printf("Please enter the amount of money you borrowed: $");
  scanf("%lf", &moneyBorrowed);
  printf("Please enter the annual interest rate: ");
  scanf("%lf", &interest);
  printf("Please enter the number of payments to be made: ");
  scanf("%lf", &numberPayments);
  trueInterest = interest / 12;
  payment = (trueInterest * moneyBorrowed) / (1 - (pow((1 + trueInterest), (-1 * numberPayments))));
  printf("A loan of $%.2f with an annual interest of %.2f payed off over %.0f months will have monthly payments of $%.2f.\n", moneyBorrowed, interest, numberPayments, payment);
  total = payment * numberPayments;
  cost = total - moneyBorrowed;
  printf("In total you will pay $%.2f, making the cost of your loan $%.2f.\n", total, cost);
    return 0;
}
