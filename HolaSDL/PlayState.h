#pragma once
#include "GameState.h"
#include <list>
#include "MenuButton.h"
#include "PauseState.h"
#include "Vector2D.h"
#include "Wall.h"
#include "Ball.h"
#include"Paddle.h"
typedef unsigned int uint;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint FRAME_RATE = 10;
class PlayState :public GameState {
protected:
	list<GameObject*> gameObjects;
	MenuButton * pauseButton;
	Wall * wallTop = nullptr, *wallDer = nullptr, *wallIzq = nullptr;
	Ball * bola = nullptr;
	Paddle * paddle = nullptr;
	int vidas = 3;
	Vector2D velocidad = Vector2D(1, -1);
public:
	PlayState(SDLApplication * app);
	~PlayState();
	void update();
	void render();
	bool handleEvent(SDL_Event& event);

	//metodos del juego
	int getVidas();
	void menosVida();
	void masVida();
	bool collides(const SDL_Rect destRect, Vector2D &collVector, const Vector2D &vel);

};