#include "PlayState.h"

PlayState::PlayState(SDLApplication* app) : GameState(app) {

}
PlayState::~PlayState() {

}
void PlayState::render() {
	GameState::render();
}
void PlayState::update() {
	GameState::update();
}
void PlayState::handleEvents(SDL_Event Event) {

}