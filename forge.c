#include <stdio.h>

typedef struct {
  int oreCost;
  int coalCost;
  char name[128];
} Recipe;

const Recipe ironIngot = {.oreCost = 3, .coalCost = 2, .name = "ironIngot"};

const Recipe copperChunk = {.oreCost = 4, .coalCost = 5, .name = "copperChunk"};

int craft(int *ore, int *coal, Recipe recipe) {
  int oreLimit = *ore / recipe.oreCost;
  int coalLimit = *coal / recipe.coalCost;

  int amount = oreLimit > coalLimit ? coalLimit : oreLimit;

  *ore -= (amount * recipe.oreCost);
  *coal -= (amount * recipe.coalCost);

  return amount;
}

void printRecipe(int ore, int coal, Recipe recipe, int total) {
  printf("Total %s crafted: %d\n", recipe.name, total);
  printf("Ore after crafting: %d\n", ore);
  printf("Coal after crafting: %d\n", coal);
}

int main() {
  int ore = 12;
  int coal = 5;

  printf("Ore before crafting: %d\n", ore);
  printf("Coal before crafting: %d\n", coal);

  int copper = craft(&ore, &coal, copperChunk);

  printRecipe(ore, coal, copperChunk, copper);

  int ingots = craft(&ore, &coal, ironIngot);
  printRecipe(ore, coal, ironIngot, ingots);
  return 0;
}
