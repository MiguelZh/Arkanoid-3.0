#pragma once
#include "GameState.h"
class EndState: public GameState {
protected:
public:
	EndState(SDLApplication * app):
		GameState(app){}
	~EndState();
};