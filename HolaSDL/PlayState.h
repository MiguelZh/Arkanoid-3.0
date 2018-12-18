#pragma once
#include "GameState.h"
#include <list>
#include "MenuButton.h"
class PlayState :public GameState {
protected:
	list<GameObject*> gameObjects;
public:
	PlayState(SDLApplication * app);
	~PlayState();

	void update();
	void render();
	void handleEvents(SDL_Event Event);
};