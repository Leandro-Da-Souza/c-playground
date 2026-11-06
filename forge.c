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

int main() {
  int ore = 12;
  int coal = 5;

  int ingots = craftIronIngots(&ore, &coal);

  printf("%d\n", ingots);

  return 0;
}
