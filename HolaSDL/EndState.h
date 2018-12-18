#pragma once
#include "GameState.h"
class EndState: public GameState {
protected:
public:
	EndState(SDLApplication * app):
		GameState(app){}
	void render();
	void update();
	void handleEvent(SDL_Event Event);
	~EndState();
};