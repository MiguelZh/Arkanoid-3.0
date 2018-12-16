#pragma once
#include "GameState.h"
#include <stack>
using namespace std;
class GameStateMachine {
protected:
	stack <GameState*> stateStack;
	GameState * currentState = nullptr;
public:
	void pushState(GameState* state);
	void changeState(GameState* state);
	void popState();
	GameState* getCurrentState();
};