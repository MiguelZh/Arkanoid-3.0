#pragma once
#include "GameState.h"
#include "MainMenuState.h"
#include <stack>
#include <vector>
using namespace std;
class GameStateMachine {
protected:	
	stack <GameState*> stateStack;
	GameState * currentState = nullptr;
public:
	GameStateMachine(){}
	~GameStateMachine();
	void pushState(GameState* state);
	void changeState(GameState* state);
	void popState();
	GameState* getCurrentState();
};