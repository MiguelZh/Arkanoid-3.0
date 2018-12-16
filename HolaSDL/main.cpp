
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include"SDLApplication.h"

using namespace std;

using uint = unsigned int;

void firstTest() {
	
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char* argv[]){
	SDLApplication game;
	game.run();
	return 0;
}