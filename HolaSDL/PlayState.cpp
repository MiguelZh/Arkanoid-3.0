#include "PlayState.h"
#include"SDLApplication.h"
PlayState::PlayState(SDLApplication* app) : GameState(app) {
	//pauseButton = new MenuButton(app, app->getTexture(1), 0, 0, 50, 50, onHitPauseButton);
	
	bola = new Ball(20, 20, Vector2D(400, 500), app->getTexture(4), velocidad, this);
	paddle = new Paddle(75, 15, Vector2D(270, 550), app->getTexture(5), velocidad);
	wallTop = new Wall(winWidth + 30, 15, Vector2D(-15, 0), app->getTexture(7), "Top");
	wallDer = new Wall(15, winHeight, Vector2D(winWidth - 15, 0), app->getTexture(6), "Right");
	wallIzq = new Wall(15, winHeight, Vector2D(0, 0), app->getTexture(6), "Left");
	mapa = new BlocksMap(winWidth, winHeight, app->getTexture(8));
	mapa->LeerFichero(niveles[0], false);
	rellenaVector();
	cout << " correcto";
}
PlayState::~PlayState() {

}
void PlayState::render() {
	for (int i = 0; i < rewards.size(); i++) {
		rewards[i]->render();
	}
	GameState::render();
}
void PlayState::update() {
	GameState::update();
	for (int i = 0; i < rewards.size(); i++) {
		rewards[i]->update();
	}
	if (mapa->pasoNivel() && nivelActual <= 2) {
		mapa->LeerFichero(niveles[nivelActual], false);
		bola->nuevoNv();
		nivelActual++;
	}
}
bool PlayState:: handleEvent(SDL_Event& event){
	GameState::handleEvent(event);
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
		app->getStateMachine()->pushState(new PauseState(app));
		cout << " pause";
	}
	return true;
}
void PlayState::rellenaVector() {
	gameObjects.push_back(mapa);
	gameObjects.push_back(paddle);
	gameObjects.push_back(bola);
	gameObjects.push_back(wallTop);
	gameObjects.push_back(wallDer);
	gameObjects.push_back(wallIzq);
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
	if (mapa->detectCollision(destRect, collVector, vel, this)) return true;
	if (wallDer->collides(destRect, collVector)) return true;
	if (wallIzq->collides(destRect, collVector)) return true;
	if (wallTop->collides(destRect, collVector)) return true;
	if (paddle->collides(destRect, collVector)) return true;
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
	reward = new Reward(50, 30, coord, app->getTexture(9), Vector2D(0, 2), type, this);
	rewards.push_back(reward);
	cout << " reward creado";
}
void PlayState::rewardMasNivel() {
	if (nivelActual < 3) {
		uint width = mapa->getW();
		uint height = mapa->getH();
		delete mapa;
		mapa = new BlocksMap(width, height,app->getTexture(8));
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