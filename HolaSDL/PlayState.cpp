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
PlayState::PlayState(SDLApplication* app, string filename) : GameState(app) {
	ifstream file;
	file.open("..\\saves\\" + filename + ".txt");
	mapa = new BlocksMap(winWidth, winHeight, app->getTexture(8));
	mapa->LeerFichero("..\\saves\\" + filename + ".txt", true);
	int a, b;
	file >> a; file >> b;
	velocidad = { (double)a ,(double)b };
	file >> a; file >> b;
	int c, d; file >> c; file >> d;
	paddle = new Paddle(c, d, { (double)a,(double)b }, app->getTexture(5), velocidad);
	file >> a; file >> b;
	velocidad = { (double)a ,(double)b };
	file >> a; file >> b;
	file >> c; file >> d;
	bola = new Ball(c, d, { (double)a,(double)b }, app->getTexture(4), { 1,1 }, this);
	file >> a; file >> b; file >> c; file >> d;
	wallTop = new Wall(c, d, { (double)a,(double)b }, app->getTexture(7), "Top");
	file >> a; file >> b; file >> c; file >> d;
	wallDer = new Wall(c, d, { (double)a,(double)b }, app->getTexture(6), "Right");
	file >> a; file >> b; file >> c; file >> d;
	wallIzq = new Wall(c, d, { (double)a,(double)b }, app->getTexture(6), "Left");
	nivelActual++;
	rellenaVector();
}
PlayState::~PlayState() {
	delete wallTop; delete wallDer; delete wallIzq;
	delete paddle;
	delete bola;
	delete mapa;
}
void PlayState::render() {
	for (int i = 0; i < rewards.size(); i++) {
		rewards[i]->render();
	}
	mapa->render();
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
	if (vidas <= 0) {
		app->getStateMachine()->pushState(new EndState(app));
	}
}
bool PlayState:: handleEvent(SDL_Event& event){
	GameState::handleEvent(event);
	if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
		if (event.key.keysym.sym == SDLK_ESCAPE) {
			app->getStateMachine()->pushState(new PauseState(app));
			cout << " pause";
		}
		if (event.key.keysym.sym == SDLK_s) {
			saveGame();
		}
	}
	return true;
}
void PlayState::rellenaVector() {	
	gameObjects.push_back(paddle);
	gameObjects.push_back(bola);
	gameObjects.push_back(wallTop);
	gameObjects.push_back(wallDer);
	gameObjects.push_back(wallIzq);
	gameObjects.push_back(mapa);
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
void PlayState::saveGame() {
	system("cls");
	cout << "Escribe el nombre del archivo: " << endl;
	string nombre;
	cin >> nombre;
	string filename = "..\\saves\\" + nombre + ".txt";
	ofstream file(filename, ofstream::trunc); // borra todo lo que ya este guardado, si existe un archivo igual
	// tamaño paddle, bola,walltop,wallder,wallizq,mapa
	for (auto *n : gameObjects) {
		ArkanoidObject * object = static_cast<ArkanoidObject*>(n);
		object->saveToFile(file);
	}
	file.close();
}
