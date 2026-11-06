#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#define MAX_INPUT 32
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

typedef struct {
  const char *label;
  int ceiling;
} DifficultyOptions;

int randomNumber(int ceiling) {
  return (rand() % ceiling) + 1;
}

int main()
{
  srand(time(NULL));

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  const DifficultyOptions options[] = {
    {"EASY", 25},
    {"NORMAL", 50},
    {"HARD", 100}
  };

  size_t options_count = ARRAY_SIZE(options);
  size_t selected = 0;

  while (1) {
    erase();

    for(size_t i = 0; i < options_count; i++) {
      printw("%s %s\n", i == selected ? ">" : " ", options[i].label);   
    }

    refresh();
    int key = getch();

    if (key == '\n') {
      break;
    }

    switch(key) {
      case KEY_DOWN:
        if(selected + 1 < options_count) {
          selected++;
        }
        break;
      case KEY_UP:
        if(selected > 0) {
          selected--;
        }
        break;
    }
  }
  
  endwin();

  int ceiling = options[selected].ceiling;
  long secret = randomNumber(ceiling);

  while(1) {
    char input[MAX_INPUT];
    char *end;

    printf("Guess a number between 1 and %d\n", ceiling);

    if (fgets(input, sizeof(input), stdin) == NULL) {
      return 1;
    };

    long conversion = strtol(input, &end, 10);

    if (end == input) {
      printf("Please, please only numbers...\n");
      continue;
    }

    if (*end != '\n' && *end != '\0') {
      printf("I see what you are trying to do little sneak...\n");
      continue;
    }
  
    if (conversion < secret) {
      printf("Too low!\n");
    } else if (conversion > secret) {
      printf("Too high!\n");
    } else {
      printf("You got it! Your guess: %ld | Secret: %ld\n", conversion, secret);
      break;
    }

  }
    
  return 0;
}

