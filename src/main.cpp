#include <cstdlib>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

static auto shouldQuit = false;

auto ProcessInputs() -> void {
  SDL_Event event;
  while (SDL_PollEvent(&event) > 0) {
    switch (event.type) {
      case SDL_QUIT: {
        shouldQuit = true;
        return;
      }
    }
  }
}

auto main(int argc, char* argv[]) -> int {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }

  auto window = SDL_CreateWindow("Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

  while (!shouldQuit) {
    ProcessInputs();
  }

  return EXIT_SUCCESS;
}
