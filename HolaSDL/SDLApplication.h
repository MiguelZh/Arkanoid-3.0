#pragma once
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "checkML.h"
#include <iostream>
#include "GameStateMachine.h"
#include "Texture.h"
using namespace std;

const int NUM_TEXTURES = 10; // SI AÑADES TEXTURAS AUMENTA ESTE NUMERO
const uint winWidth = 800;
const uint winHeight = 600;
const uint FRAME_RATE = 10;
typedef unsigned int uint;
class SDLApplication {
private:

	const enum textureName {menu,play,pause,end};
	string nombreMenus[NUM_TEXTURES] = { "..\\images\\menu.png", "..\\images\\play.png", "..\\images\\pause.png","..\\images\\end.png",
	"..\\images\\ball.png", "..\\images\\paddle.png", "..\\images\\side.png","..\\images\\topside.png","..\\images\\bricks.png", "..\\images\\rewards.png" }; // nombre de las imagenes
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Texture * textures[NUM_TEXTURES];

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