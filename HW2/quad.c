#include <stdio.h>
#include <math.h>
#include <string.h>
double Quadroot1(double a, double b, double c) {
  double r1;
    r1 = (-b + sqrt(pow(b,2)-4*a*c))/(2 * a);
  return r1;
}
double Quadroot2(double a, double b, double c) {
  double r2;
    r2 = (-b - sqrt(pow(b,2)-4*a*c))/(2 * a);
  return r2;
}
double discrimant(double a, double b, double c) { //Calculates the discrimant
  double disc;
  double root1;
  double root2;
  double realRoot;
    root1 = Quadroot1(a,b,c);
    root2 = Quadroot2(a,b,c);
    disc = pow(b,2) - 4*a*c; //if the discrimant is negative, no roots. zero, 1 root, positive, 2 roots.
      if (disc < 0) {
        printf("There are no real solutions\n");
      }
      else if (disc > 0) {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2f\n", root1);
        printf("Solution 2: %.2f\n", root2);
      }
      else {
        realRoot = (-b)/(2*a);
        printf("There is one real solution: %.2f\n", realRoot);
      }
  return 0;
}
int main() {
  double a;
  double b;
  double c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
      scanf("%lf", &a);
    printf("Please enter b: ");
      scanf("%lf", &b);
    printf("Please enter c: ");
      scanf("%lf", &c);
    discrimant(a,b,c);
  return 0;
}
