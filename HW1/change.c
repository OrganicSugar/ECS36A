#include <stdio.h>
int main()
{
  printf("Please enter the amount of money you wish to withdraw: ");
  int userMoney;
  int hundreds;
  int remainder;
  int fifty;
  int twenty;
  int ten;
  int five;
  int one;
  scanf("%d", &userMoney);
  hundreds = (userMoney / 100);
  remainder = userMoney - (hundreds * 100);
  fifty = (remainder / 50);
  remainder = remainder - (fifty * 50);
  twenty = (remainder / 20);
  remainder = remainder - (twenty * 20);
  ten = (remainder / 10);
  remainder = remainder - (ten * 10);
  five = (remainder / 5);
  remainder = remainder - (five * 5);
  one = remainder;
  printf("You received %d hundred(s)\n", hundreds);
  printf("You received %d fifty(s)\n", fifty);
  printf("You received %d twenty(s)\n", twenty);
  printf("You received %d ten(s)\n", ten);
  printf("You received %d five(s)\n", five);
  printf("You received %d one(s)\n", one);
  return 0;
}
