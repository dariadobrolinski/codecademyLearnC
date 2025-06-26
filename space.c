#include <stdio.h>

int main() {
  
  double weight;
  int x;

  printf("Please enter your current Earth weight:");
  scanf("%lf", &weight);

  printf("\nI have information for the following planets:\n\n");
  printf("1. Mercury\n2. Venus\n3. Mars\n4. Jupiter");
  printf("\n5. Saturn\n6. Uranus\n7. Neptune\n\n");
 
  printf("Which planet are you visiting? ");
  scanf("%d", &x);

  if (x == 1) {
    weight *= 0.38;
  } else if (x == 2) {
    weight *= 0.91;
  } else if (x == 3) {
    weight *= 0.38;
  } else if (x == 4) {
    weight *= 2.34;
  } else if (x == 5) {
    weight *= 1.06;
  } else if (x == 6) {
    weight *= 0.92;
  } else if (x == 7) {
    weight *= 1.19;
  }

  printf("\nYour weight: %lf\n", weight);

}