#include <stdbool.h>
#include <stdio.h>

bool spendGold(int *gold, int cost) {
  if (cost > *gold) {
    printf("You poor stupid goblin, you are %d gold short..\n", cost - *gold);
    return false;
  } else {
    *gold -= cost;
    return true;
  }
}

bool buyPotion(int *gold, int *stock, int cost, int *potions) {
  if (*stock <= 0)
    return false;

  if (spendGold(gold, cost) == false)
    return false;

  (*stock)--;
  (*potions)++;
  return true;
}

int main() {
  printf("Potion shop\n");

  int gold = 30;
  int stock = 3;
  int potions = 0;
  printf("Starting gold: %d\n", gold);
  printf("Starting stock: %d\n", stock);
  printf("Starting potions: %d\n", potions);

  buyPotion(&gold, &stock, 10, &potions);
  buyPotion(&gold, &stock, 400, &potions);

  printf("Gold after spending: %d\n", gold);
  printf("Stock after spending: %d\n", stock);
  printf("Potions after spending: %d\n", potions);

  return 0;
}
