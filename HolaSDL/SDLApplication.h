#pragma once
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "checkML.h"
#include <iostream>
#include "GameStateMachine.h"

using namespace std;

typedef unsigned int uint;
class SDLApplication {
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	const uint winWidth = 800;
	const uint winHeight = 600;
	bool exit = false;
	GameStateMachine * stateMachine = nullptr;
public:
	SDLApplication();
	~SDLApplication();
	void run();
	void render() const;
	void handleEvents();
	void update();

};