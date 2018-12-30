#pragma once
#include "GameState.h"
#include <list>
#include "MenuButton.h"
#include "PauseState.h"
#include "Ball.h"
#include "Paddle.h"
#include "Reward.h"
#include <time.h>
#include <stdlib.h>
#include "BlocksMap.h"
#include "Wall.h"
#include <vector>;

class PlayState :public GameState {
private:
	Vector2D velocidad = Vector2D(1, -1);
	Paddle * paddle = nullptr;
	Ball * bola = nullptr;
	Reward * reward = nullptr;
	BlocksMap * mapa = nullptr;
	Wall * wallTop = nullptr, *wallDer = nullptr, *wallIzq = nullptr;
protected:
public:
	PlayState(SDLApplication * app);
	PlayState(SDLApplication * app, string filename);
	~PlayState();
	void render();
	void update();
	bool handleEvent(SDL_Event& event);
	//vector objetos
	void rellenaVector();
	//metodos de ball
	int vidas = 3;
	void masVida();
	void menosVida();
	int getVidas();
	//collision
	bool collides(const SDL_Rect destRect, Vector2D &collVector, const Vector2D &vel);
	// rewards
	void reset();
	void alargar();
	void acortar();
	void rewardMasNivel();
	void spawnReward(Vector2D coord);
	void destruyeReward();
	Paddle *getPaddle();
	vector <Reward*> rewards;
	//blocksmap
	uint nivelActual = 0;
	string niveles[3] = { "..//maps//level01.ark","..//maps//level02.ark","..//maps//level03.ark" };
	//saveGame
	void saveGame();
};