#pragma once
#include "GameState.h"
#include <list>
#include "MenuButton.h"
#include "PauseState.h"
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

};