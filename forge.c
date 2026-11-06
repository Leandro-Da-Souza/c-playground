#include <stdio.h>

typedef struct {
  int oreCost;
  int coalCost;
} Recipe;

const Recipe ironIngot = {
    .oreCost = 3,
    .coalCost = 2,
};

int craftIronIngots(int *ore, int *coal) {
  int oreLimit = *ore / ironIngot.oreCost;
  int coalLimit = *coal / ironIngot.coalCost;

  int ingots = oreLimit > coalLimit ? coalLimit : oreLimit;

  *ore -= (ingots * ironIngot.oreCost);
  *coal -= (ingots * ironIngot.coalCost);

  return ingots;
}

int craft(int *ore, int *coal, Recipe recipe) {
  int oreLimit = *ore / recipe.oreCost;
  int coalLimit = *coal / recipe.coalCost;

  int amount = oreLimit > coalLimit ? coalLimit : oreLimit;

  *ore -= (amount * recipe.oreCost);
  *coal -= (amount * recipe.coalCost);

  return amount;
}

int main() {
  int ore = 12;
  int coal = 5;

  printf("Ore before crafting: %d\n", ore);
  printf("Coal before crafting: %d\n", coal);
  int ingots = craft(&ore, &coal, ironIngot);

  printf("Total ingots crafted: %d\n", ingots);

  printf("Ore after crafting: %d\n", ore);
  printf("Coal after crafting: %d\n", coal);

  return 0;
}
