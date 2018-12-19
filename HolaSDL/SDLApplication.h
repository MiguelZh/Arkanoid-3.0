#pragma once
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "checkML.h"
#include <iostream>
#include "GameStateMachine.h"
#include "Texture.h"
using namespace std;

typedef unsigned int uint;
class SDLApplication {
private:
	const enum textureName {menu,play,pause,end};
	string nombreMenus[4] = { "..\\images\\menu.png", "..\\images\\play.png", "..\\images\\pause.png","..\\images\\end.png", }; // nombre de las imagenes
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Texture * textures[4];
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
	Texture * getTexture(int num);
	GameStateMachine * getStateMachine();

};