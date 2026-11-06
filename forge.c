#include <stdio.h>

int craftableIngots(int ore, int coal) {
  int oreLimit = ore / 3;
  int coalLimit = coal / 2;

  return oreLimit > coalLimit ? coalLimit : oreLimit;
}

int main() {
  int ingots = craftableIngots(12, 5);

  printf("%d\n", ingots);

  return 0;
}
