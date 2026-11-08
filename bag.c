#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *space;
  size_t count;
  size_t capacity;
} Bag;

bool addToBag(Bag *bag, int value) {
  if (bag->count == bag->capacity) {
    size_t newCapacity = bag->capacity == 0 ? 1 : bag->capacity * 2;
    int *resized = realloc(bag->space, newCapacity * (sizeof *bag->space));

    if (resized == NULL) {
      return false;
    }

    bag->space = resized;
    bag->capacity = newCapacity;
  }

  bag->space[bag->count] = value;
  bag->count++;
  return true;
}

int main(void) {
  printf("Goblin's Magic Bag\n");

  Bag goblinBag = {
      .space = NULL,
      .count = 0,
      .capacity = 0,
  };

  if (addToBag(&goblinBag, 100) == false) {
    free(goblinBag.space);
    return 1;
  }

  if (addToBag(&goblinBag, 200) == false) {
    free(goblinBag.space);
    return 1;
  }

  if (addToBag(&goblinBag, 300) == false) {
    free(goblinBag.space);
    return 1;
  }

  /*
  goblinBag.capacity = 3;
  goblinBag.space = malloc(goblinBag.capacity * sizeof *goblinBag.space);

  if (goblinBag.space == NULL) {
    printf("Could not do magic and allocate any memory\n");
    return 1;
  }

  goblinBag.space[goblinBag.count] = 100;
  goblinBag.count++;
  goblinBag.space[goblinBag.count] = 200;
  goblinBag.count++;
  goblinBag.space[goblinBag.count] = 300;
  goblinBag.count++;
  */

  for (size_t i = 0; i < goblinBag.count; i++) {
    printf("Accessing memory baby: %d\n", goblinBag.space[i]);
  }

  /*
  size_t newCapacity = goblinBag.capacity + 1;

  int *resized =
      realloc(goblinBag.space, newCapacity * (sizeof *goblinBag.space));

  if (resized == NULL) {
    printf("Ancient rites could not reallocate more memory..");
    free(goblinBag.space);
    return 1;
  }

  goblinBag.space = resized;
  goblinBag.capacity = newCapacity;
  goblinBag.space[goblinBag.count] = 400;
  goblinBag.count++;
  */

  if (addToBag(&goblinBag, 400) == false) {
    free(goblinBag.space);
    return 1;
  }

  for (size_t i = 0; i < goblinBag.count; i++) {
    printf("Accessing even more memory baby: %d\n", goblinBag.space[i]);
  }

  free(goblinBag.space);
  /*
  size_t newCapacity = 4;
  int *resized = realloc(numbers, newCapacity * (sizeof *numbers));

  if (resized == NULL) {
    printf("Could not do magic and REallocate any more memory\n");
    free(numbers);
    return 1;
  }

  numbers = resized;
  capacity = newCapacity;
  numbers[3] = 400;

  printf("Tinkering with reallocatin of memory...\n");

  for (size_t i = 0; i < capacity; i++) {
    printf("Accessing realloced values sugar! %d\n", numbers[i]);
  }

  free(numbers);
  */
  return 0;
}
