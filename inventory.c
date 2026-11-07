#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

int main() {
  // array with fixed size of 5, each item can have up to 31 characters plus
  // terminating '\0'.
  char inventory[5][32] = {"Rusty Sword", "Suspicious potion", "Shiny Pebble",
                           "Pouch of teeth", "Gnawed bone"};
  size_t itemCount = 5;

  size_t inventoryCapacity = ARRAY_SIZE(inventory);

  size_t indexToRemove = itemCount;

  for (size_t index = 0; index < itemCount; index++) {
    if (strcmp(inventory[index], "Suspicious potion") == 0) {
      indexToRemove = index;
      break;
    }
  }

  if (indexToRemove < itemCount) {
    for (size_t removedIndex = indexToRemove; removedIndex + 1 < itemCount;
         removedIndex++) {
      strcpy(inventory[removedIndex], inventory[removedIndex + 1]);
    }
    itemCount--;
  }

  if (itemCount < inventoryCapacity) {
    strcpy(inventory[itemCount], "Goblin snack");
    itemCount++;
  } else {
    printf("Bag is full!\n");
  }

  for (size_t i = 0; i < itemCount; i++) {
    printf("%zu. %s\n", (i + 1), inventory[i]);
  }

  return 0;
}
