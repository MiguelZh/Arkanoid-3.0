#pragma once
#include "GameState.h"
#include <list>
#include "MenuButton.h"
#include "PauseState.h"
#include "Ball.h"
class PlayState :public GameState {
protected:
	list<GameObject*> gameObjects;
	MenuButton * pauseButton;
public:
	PlayState(SDLApplication * app);
	~PlayState();
	void update();
	void render();
	bool handleEvent(SDL_Event& event);
	//metodos de ball
	int vidas = 3;
	void masVida();
	void menosVida();
	int getVidas();
	//collision
	bool collides(const SDL_Rect destRect, Vector2D &collVector, const Vector2D &vel);

};