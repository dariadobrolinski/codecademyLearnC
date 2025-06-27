#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Race {
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[50];
  char firstPlaceRaceCarColor[50];
};

struct RaceCar {
  char driverName[50];
  char raceCarColor[50];
  int totalLapTime;
};

void printIntro(void) {
  printf("Welcome to our main event digital race fans!\n");
  printf("I hope everybody has their snacks because we are about to begin!\n");
}

void printCountDown(void) {
  printf("Racers Read! In...\n");
  printf("5\n4\n3\n2\n1\n");
  printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race) {
  printf("After lap %d we have %s in the %s race car in first place!\n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race) {
  printf("And our winner is...\n");
  printf("*drumroll*\n");
  printf("%s in the %s race car! Congratulations to %s.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor, race.firstPlaceDriverName);
  printf("It was great having everyone here tonight. Goodnight!");
}

int calculateTimeToCompleteLap(void) {
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;
  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar) {
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
    strcpy(race->firstPlaceDriverName, raceCar1->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
  } else {
    strcpy(race->firstPlaceDriverName, raceCar2->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
  }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {5, 1, "", ""};
  for (int i = 1; i <= race.numberOfLaps; i++) {
    race.currentLap = i;
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
  }
  printCongratulation(race);
}

int main() {
	srand(time(0));

  char name1[50];
  char color1[50];
  printf("Racer 1 Name: ");
  scanf("%s", name1);
  printf("Racer 1 Car Color: ");
  scanf("%s", color1);

  char name2[50];
  char color2[50];
  printf("Racer 2 Name: ");
  scanf("%s", name2);
  printf("Racer 2 Car Color: ");
  scanf("%s", color2);

  struct RaceCar raceCar1;
  strcpy(raceCar1.driverName, name1);
  strcpy(raceCar1.raceCarColor, color1);
  raceCar1.totalLapTime = 0;

  struct RaceCar raceCar2;
  strcpy(raceCar2.driverName, name2);
  strcpy(raceCar2.raceCarColor, color2);
  raceCar2.totalLapTime = 0;

  printIntro();
  printCountDown();
  startRace(&raceCar1, &raceCar2);
};