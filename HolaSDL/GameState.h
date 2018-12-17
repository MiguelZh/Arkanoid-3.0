#pragma once
#include <list>
#include "GameObject.h"
using namespace std;
class SDLApplication;
class GameState {
protected:
	list<GameObject*> gameObjects;
public:
	GameState();
	~GameState();
	virtual void update();
	virtual void render();
	virtual void handleEvent(SDL_Event event);

};