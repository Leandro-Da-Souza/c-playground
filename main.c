#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  if(!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("SDL init failed: %s", SDL_GetError());
    return 1;
  }

  SDL_Window *window = SDL_CreateWindow(
      "It Lives!",
      800,
      800,
      0
  );

  if (!window) {
    SDL_Log("Window create fail: %s", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  bool running = true;

  while(running) {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_EVENT_QUIT) {
        running = false;
      }
    }

  }
  
  SDL_Delay(16);

  SDL_Quit();
  return 0;
}
