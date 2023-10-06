#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int comparision (double minPayment, double applyLoanInvestment, double monthlyIncome) {
  if (minPayment > applyLoanInvestment) {  // If making minimum payments is more profitable by retirement, then print the given message
    printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
    printf("If you do you will have $%.2f when you retire as opposed to $%.2f if you payed off your loan before investing.\n", minPayment, applyLoanInvestment);
  } else if (minPayment < applyLoanInvestment) {  // If paying off the loan first is more profitable by retirement, then print the given message.
    printf("You should apply all $%.2f towards your loan before making any investments.\n", monthlyIncome);
    printf("If you do you will have $%.2f when you retire as opposed to $%.2f if you only made minimum payments.\n", applyLoanInvestment, minPayment);
  }
  return 0;
}
double applyLoan (double monthlyIncome, double loan, double minimumPayment, int age, int retirementAge, double monthlyInterest, double monthlyReturnRate) {
  /* This function calculates the investment if you put all your
  money to paying off the loan first, then putting the rest
  into the investment */
  int time = (retirementAge - age) * 12;  // Gets the time interval and multiply by 12 to get the months
  const double x = monthlyIncome;  // Sets a variable x to monthlyIncome as a const.
  double investment = 0;  // Sets initial investment to 0
  while (loan > 0) {
    time = time - 1;
    // In one month, the loan increases by the monthly interest, and the user uses all the monthly income to pay off the loan.
    monthlyIncome = x;
    loan = loan + (loan * monthlyInterest);
    loan = loan - monthlyIncome;
    if (loan <= 0) {  // Until the user's loan is paid off
      investment = (loan * -1) + investment;
      // Sets the extra money paid on the loan back to the investment and breaks the loop
      break;
    } else if (time == 0 && loan > 0) {
      // Prints a warning message and breaks the program if the loan isn't paid off by time
      printf("Warning! After you retire you will still have $%.2f in loans left.\n", loan);
      break;
    } else {
      continue;
    }
  }
  // This while loop just calculates the investment with the time remaining
  while (time != 0) {
    monthlyIncome = x;
    investment = investment + (investment * monthlyReturnRate);
    investment = investment + monthlyIncome;
    monthlyIncome = 0;
    time = time - 1;
  }
  return investment;
}
double minimumPaymentMethod (double monthlyIncome, double loan, const double minimumPayment, int age, int retirementAge, double monthlyInterest, double monthlyReturnRate) {
  /* This method is using some of the monthly income to pay the minimum on the
     and then setting the rest to the investment*/
  int time = (retirementAge - age) * 12;  // Gets the time interval and multiply by 12 to get the months
  const double x = monthlyIncome;  // Sets a variable x to monthlyIncome as a const.
  double investment = 0;
  //printf("%lf\n", monthlyInterest);
  while(loan > 0) {
      time = time - 1;
      monthlyIncome = x;
      /* In one month, the loan is increased by the interest
         and the minimum payment is made. Then the minimum
         payment is also subtracted from the monthly monthly.
         The rest is set to the investment*/
      loan = loan + (loan * monthlyInterest);
      loan = loan - minimumPayment;
      monthlyIncome = monthlyIncome - minimumPayment;
      investment = investment + (investment * monthlyReturnRate);
      investment = investment + monthlyIncome;
      monthlyIncome = 0; // Until the user's loan is paid off
      if (loan <= 0) {
        investment = (loan * -1) + investment;
        // Sets the extra money paid on the loan back to the investment and breaks the loop
        break;
      } else if (time == 0 && loan > 0) {
        // Prints a warning message and breaks the program if the loan isn't paid off by time
        printf("Warning! After you retire you will still have $%.2f in loans left.\n", loan);
        break;
      } else {
      continue;
    }
  }
// This while loop just calculates the investment with the time remaining
while(time != 0) {
  monthlyIncome = x;
  investment = investment + (investment * monthlyReturnRate);
  investment = investment + monthlyIncome;
  monthlyIncome = 0;
  time = time - 1;
}
return investment;
}
double monthlyCalculations (double x) {
  //Finds the monthly rate of anything given the annual rate
  double monthlyCalculation = ((double) x) / ((double) 12);
  return monthlyCalculation;
}
bool isValidFormat (const int numArgsRead, const int numArgsNeeded) {
  // Checks for valid formatting and keeps asking for input if characters are added
  bool formatIsGood = numArgsRead == numArgsNeeded;
  char character;
  do {
    scanf("%c", &character);
      if (!isspace(character)) {
        formatIsGood = false;
      }
  } while(character != '\n');
  return formatIsGood;
}
int getValidAge (const char* prompt, int age) {
  /* Gets valid retirement age from user that greater than their
     current age and not less than 0*/
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %d", &num);
    if (num >= age && num >= 0) {
      continue;
    }
    else {
      numArgsRead = 3;
    }
  }while(!isValidFormat(numArgsRead, numArgsNeeded));
  return num;
}
double getValidDouble (const char* prompt) {
  // Gets a valid double input that not negative
  double num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %lf", &num);
    if (num >= 0) {
      continue;
    }
    else {
      numArgsRead = 3;
    }
  }while(!isValidFormat(numArgsRead, numArgsNeeded));
  return num;
}
double getValidMinPayment (const char* prompt, double monthlyIncome) {
  // Gets a valid minimum monthly payment that is not greater than the monthly income
  double num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %lf", &num);
    if (num >= monthlyIncome) {
      printf("You didn't set aside enough money to pay off our loans. Ending program.\n");
      exit(0);
    } else if (num < 0) {
      numArgsRead = 3;
    } else {
      continue;
}
  }while(!isValidFormat(numArgsRead, numArgsNeeded));
  return num;
  }
int getValidInt (const char* prompt) {
  // Gets a valid int that is not negative for age
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %d", &num);
    if (num >= 0) {
      continue;
    }
    else {
      numArgsRead = 3;
    }
  }while(!isValidFormat(numArgsRead, numArgsNeeded));
  return num;
}
int main () {
  // Gets all the user input
  double monthlyIncome = getValidDouble("Enter how much money you will be putting towards loans/retirement each month: ");
  double loan = getValidDouble("Enter how much you owe in loans: ");
  double interest = getValidDouble("Enter the annual interest rate of the loans: ");
  double minimumPayment = getValidMinPayment("Enter your minimum monthly loan payment: ", monthlyIncome);
  int age = getValidInt("Enter your current age: ");
  int retirementAge = getValidAge("Enter the age you plan to retire at: ", age);
  double annualReturnRate = getValidDouble("Enter the annual rate of return you predict for your investments: ");
  double monthlyInterest = monthlyCalculations(interest);
  double monthlyReturnRate = monthlyCalculations(annualReturnRate);
  double minPayment = minimumPaymentMethod(monthlyIncome, loan, minimumPayment, age, retirementAge, monthlyInterest, monthlyReturnRate);
  double applyLoanInvestment = applyLoan(monthlyIncome, loan, minimumPayment, age, retirementAge, monthlyInterest, monthlyReturnRate);
  //printf("%lf, %lf, %lf, %lf, %d, %d, %lf\n", monthlyIncome, loan, interest, minimumPayment, age, retirementAge, annualReturnRate);
  //printf("%lf, %lf\n", monthlyInterest, monthlyReturnRate);
  //printf("%.2f, %.2f\n", minPayment, applyLoanInvestment);
  comparision(minPayment, applyLoanInvestment, monthlyIncome);
return 0;
}
