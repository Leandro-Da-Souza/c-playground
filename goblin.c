#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct {
  float health;
  float attack;
  int gold;
  char name[10];
} Goblin;

int modifier(int n) {
  return (rand() % n) + 1;
}

float damageCalculator(float attack)
{
  if (attack <= 0) {
    return 0.0f;
  }
  
  return attack * modifier(9);
}

float healCalculator(float health)
{
  float healing = (health / 2) * modifier(4);
  return healing; 
}

bool coinFlip()
{
  return rand() % 2;
}

void gameLoop(Goblin *attacker, Goblin *defender)
{
  float damage = damageCalculator(attacker->attack);

  printf("%s attacked %s for %.2f damage!\n", attacker->name, defender->name, damage);
  defender->health -= damage;

  if (defender->health <= 0) {
    printf("%s has been defeated!\n", defender->name);
    return;
  }

  if (defender->gold > 0 && coinFlip()) {
    defender->health += healCalculator(defender->health);
    defender->gold -= 1;

    if (defender->health > 100) {
      defender->health = 100.0f;
    }

    printf("%s gulps a suspicious potion! Health: %.1f | Gold left: %d\n",
       defender->name, defender->health, defender->gold);
  }
}

int main() {
  srand(time(NULL));
  
  Goblin Grub = {100.0f, 5.0f, 10, "Grub"};
  Goblin Jenkins = {100.0f, 5.0, 10, "Jenkins"};

  int round = 1;
  
  printf("GOBLIN ARENA\n");

  bool fate = coinFlip();
  Goblin *attacker = fate ? &Grub : &Jenkins;
  Goblin *defender = fate ? &Jenkins : &Grub;

  while(Grub.health > 0 && Jenkins.health > 0) {
    printf("ROUND: %d\n", round);

    gameLoop(attacker, defender); 

    printf("Grub: %.1f | Jenkins: %.1f\n",
        Grub.health, Jenkins.health);

    Goblin *temp = attacker;
    attacker = defender;
    defender = temp;

    round++;

    if (Grub.health > 0 && Jenkins.health > 0) {
      sleep(1);
    }
  }

  return 0;
}
