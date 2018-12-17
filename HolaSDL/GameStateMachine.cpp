#include "GameStateMachine.h"


void GameStateMachine::pushState(GameState* state) {
	stateStack.push(state);// error de lectura
	currentState = stateStack.top();
}
void GameStateMachine::changeState(GameState* state) {
	popState();
	pushState(state);
}
void GameStateMachine::popState() {
	if (!stateStack.empty()) {
		delete stateStack.top();
		stateStack.pop();
	}
}
GameState * GameStateMachine::getCurrentState() {
	return currentState;
}