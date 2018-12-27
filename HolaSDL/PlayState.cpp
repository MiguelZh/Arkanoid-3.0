#include "PlayState.h"
#include"SDLApplication.h"
PlayState::PlayState(SDLApplication* app) : GameState(app) {
	//pauseButton = new MenuButton(app, app->getTexture(1), 0, 0, 50, 50, onHitPauseButton);
}
PlayState::~PlayState() {
	delete wallTop; delete wallDer; delete wallIzq;
	wallTop = nullptr; wallDer = nullptr; wallIzq = nullptr;
	delete bola; bola = nullptr; 
	delete paddle; paddle = nullptr;
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
int PlayState::getVidas() {
	return vidas;
}
bool PlayState::collides(const SDL_Rect destRect, Vector2D &collVector, const Vector2D &vel) {
	//if (mapa->detectCollision(destRect, collVector, vel, this)) return true;
	if (wallDer->collides(destRect, collVector)) return true;
	if (wallIzq->collides(destRect, collVector)) return true;
	if (wallTop->collides(destRect, collVector)) return true;
	if (paddle->collides(destRect, collVector)) return true;
	return false;
}
void PlayState::menosVida() {
	cout << " Perdiste una vida";
	vidas--;
}
void PlayState::masVida() {
	cout << " Conseguiste una vida";
	vidas++;
}