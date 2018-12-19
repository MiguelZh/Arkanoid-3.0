#include "GameState.h"

GameState::~GameState() {

}

void GameState::render() {
	for (list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end();) {
		(*it++)->render();
	}
}

void GameState::update() {
	for (list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end();) {
		(*it++)->update();
	}
}

bool GameState::handleEvent(SDL_Event& event) {
	bool handled = false;
	auto it = gameObjects.begin();
	while (it != gameObjects.end() && !handled) {

		if ((*it)->handleEvents(event)) {
			handled = true;
		}
		else {
			++it;
		}
	}
	return handled;
}