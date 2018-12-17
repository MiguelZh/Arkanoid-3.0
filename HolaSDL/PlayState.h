#pragma once
#include "GameState.h"
#include <list>
class PlayState :public GameState {
protected:
	list<GameObject*> gameObjects;
public:
	PlayState();
	~PlayState();

	void update();
	void render();
	void handleEvent(SDL_Event e);
};