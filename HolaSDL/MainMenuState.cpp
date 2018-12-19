#include "MainMenuState.h"
#include "SDLApplication.h"
MainMenuState::MainMenuState(SDLApplication * app): GameState(app){
	playButton = new MenuButton(app,app->getTexture(0), 200, 200, 200, 100, onHitPlayButton);
	gameObjects.push_front(playButton);
}
MainMenuState::~MainMenuState() {

}
void MainMenuState::onHitPlayButton(SDLApplication * app) {
	cout << " playState";
	app->getStateMachine()->pushState(new PlayState(app));
}
void MainMenuState::render() {
	playButton->render();
}
void MainMenuState::update() {

}
void MainMenuState::handleEvents(SDL_Event Event) {
	while (SDL_PollEvent(&Event) && !exit) {
		playButton->handleEvents(Event);
	}
}