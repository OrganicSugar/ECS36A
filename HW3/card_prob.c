#include <stdio.h>
double Probability (double totalCards, double copies, double initialHandSize, double mulligan, int turnNeeded) {
  double currentHandSize = 0;
//  double m;
  const int turn = turnNeeded;
  // Initial Probability
  double probabilityChance = (totalCards - copies) / totalCards;
  // Draw cards and adding that to the probability
  while (currentHandSize != (initialHandSize - 1)) {
    totalCards -= 1;
    currentHandSize += 1;
    probabilityChance = ((totalCards - copies) / totalCards) * probabilityChance;
  }
  totalCards -= 1;
  currentHandSize += 1;
  // Mulligan Calculations
  double m = mulligan;
  while (m != 0) {
    probabilityChance = ((totalCards - copies) / totalCards) * probabilityChance;
    totalCards -= 1;
    m -= 1;
  }
  totalCards += mulligan;
  // After Mulligan but before draw calculation
  if (turn == 0){
    probabilityChance = probabilityChance;
  } else {
    probabilityChance = ((totalCards - copies) / totalCards) * probabilityChance;
  }
  // Probability of the given turns except for the last one
  while (turnNeeded != 1) {
    if (turn == 0) {
      break;
    } else {
    totalCards -= 1;
    probabilityChance = ((totalCards - copies) / totalCards) * probabilityChance;
    turnNeeded -= 1;
  }
  }

  double percentage = 1 - probabilityChance;
  // Turned the probability not chance, to the actual chance for printing
  printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %.0f cards is %.2f\n", turn, mulligan, percentage);
  return 0;
}
int main (){
  double totalCards, copies, initialHandSize, mulligan;
  int turnNeeded;
  printf("Enter how many total cards there are in the deck: ");
  scanf("%lf", &totalCards);
  printf("Enter how many copies of the card that you are looking for are in the deck: ");
  scanf("%lf", &copies);
  printf("Enter your initial hand size: ");
  scanf("%lf", &initialHandSize);
  printf("Enter how many cards you are mulliganing: ");
  scanf("%lf", &mulligan);
  printf("Enter what turn you want to draw the card by: ");
  scanf("%d", &turnNeeded);
  // Sents all the variables needed to the calculation function
  Probability(totalCards, copies, initialHandSize, mulligan, turnNeeded);
}
