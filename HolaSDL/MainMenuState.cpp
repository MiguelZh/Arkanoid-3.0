#include "MainMenuState.h"
#include "SDLApplication.h"
MainMenuState::MainMenuState(SDLApplication * app): GameState(app){
	playButton = new MenuButton(app->getTexture(0), 200, 200, 100, 100, onHitPlayButton);
}
MainMenuState::~MainMenuState() {

}
void MainMenuState::onHitPlayButton(SDLApplication * app) {

}
void MainMenuState::render() {
	playButton->render();
}
void MainMenuState::update() {

}
void MainMenuState::handleEvents(SDL_Event Event) {
	
}