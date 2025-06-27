#include<stdio.h>
#include<string.h>

int main() {
  int counterOne[4] = {0, 0, 0, 0};
  int counterTwo[4] = {0, 0, 0, 0};

  char strOne[] = "dbb cccccaacb cdbababdcdcdab dcdad";
  char strTwo[] = "bbbcc bdddccccad cdbbaaacaccdabdd";

  for (int i = 0; i < strlen(strOne); i++) {
    if (strOne[i] == 'a') {
      counterOne[0]++;
    } else if (strOne[i] == 'b') {
      counterOne[1]++;
    } else if (strOne[i] == 'c') {
      counterOne[2]++;
    } else if (strOne[i] == 'd') {
      counterOne[3]++;
    } else {
      continue;
    }
  }

    for (int i = 0; i < strlen(strTwo); i++) {
    if (strTwo[i] == 'a') {
      counterTwo[0]++;
    } else if (strOne[i] == 'b') {
      counterTwo[1]++;
    } else if (strOne[i] == 'c') {
      counterTwo[2]++;
    } else if (strOne[i] == 'd') {
      counterTwo[3]++;
    } else {
      continue;
    }
  }

  int flag = 0;

  for (int i = 0; i < 4; i++) {
    if (counterOne[i] != counterTwo[i]) {
      flag = 1;
    }
  }

    if (flag == 0) {
      printf("Anagram!");
    } else {
      printf("Not Anagram!");
    }

}
