#pragma once
#include <list>
#include "GameObject.h"
#include "checkML.h"
using namespace std;
class SDLApplication;
class GameState {
protected:
	list<GameObject*> gameObjects;
	SDLApplication * app;
public:
	GameState(SDLApplication * app):
		app(app) {}
	virtual ~GameState();
	virtual void update();
	virtual void render();
	virtual bool handleEvent(SDL_Event& event);

};