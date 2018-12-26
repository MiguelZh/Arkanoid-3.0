#include "PlayState.h"
#include"SDLApplication.h"
PlayState::PlayState(SDLApplication* app) : GameState(app) {
	//pauseButton = new MenuButton(app, app->getTexture(1), 0, 0, 50, 50, onHitPauseButton);
}
PlayState::~PlayState() {

}
void PlayState::render() {
	GameState::render();
}
void PlayState::update() {
	GameState::update();
}
bool PlayState:: handleEvent(SDL_Event& event){
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
		app->getStateMachine()->pushState(new PauseState(app));
		cout << " pause";
	}
	else { GameState::handleEvent(event); }
	return true;
}