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
void PlayState::rellenaVector() {
	objects.push_back(paddle);
	objects.push_back(bola);
	objects.push_back(wallTop);
	objects.push_back(wallDer);
	objects.push_back(wallIzq);
}

void PlayState::masVida() {
	cout << " Ganaste una vida";
	vidas++;
}
void PlayState::menosVida() {
	cout << " Perdiste una vida";
	vidas--;
}
int PlayState::getVidas() {
	return vidas;
}
bool PlayState::collides(const SDL_Rect destRect, Vector2D &collVector, const Vector2D &vel) {
	return false;
}
void PlayState::reset() {
	paddle->setW(75);
}
void PlayState::acortar() {
	reset();
	paddle->setW(paddle->getW() / 1.5);
}
void PlayState::alargar() {
	reset();
	paddle->setW(paddle->getW() * 2);
}
Paddle* PlayState::getPaddle() {
	return paddle;
}
void PlayState::spawnReward(Vector2D coord) {
	srand(time(NULL));
	int type = rand() % 4;
	reward = new Reward(50, 30, coord, textures[rewardText], Vector2D(0, 2), type, this);
	rewards.push_back(reward);
}
void PlayState::rewardMasNivel() {
	if (nivelActual < 3) {
		uint width = mapa->getW();
		uint height = mapa->getH();
		delete mapa;
		mapa = new BlocksMap(width, height, textures[blocksMapText]);
		mapa->LeerFichero(niveles[nivelActual], false);
		nivelActual++;
	}
}
void PlayState::destruyeReward() {
	reward = rewards.back();
	rewards.pop_back();
	delete reward;
	reward = nullptr;
}