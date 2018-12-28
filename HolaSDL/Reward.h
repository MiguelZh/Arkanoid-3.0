#pragma once
#include "MovingObject.h"
#include "Paddle.h"
#include "Ball.h"
class PlayState;
class Reward:public MovingObject
{
protected:
	uint rewardT; float velocidadAnim = 0.02; uint Frame = 0;  uint tiempo = 0; PlayState * playstate; Paddle * paddle; Ball * bola;
public:
	Reward(uint width, uint height, Vector2D coord, Texture * t, Vector2D vel, uint type, PlayState *p) :
		MovingObject(width, height, coord, t, vel), rewardT(type), playstate(p) {}
	~Reward();
	void render();
	void update(); // debatir un update que llame a otro update del padre para que sea mas eficiente(posterior)
	void TipodeRecompensa();
	bool handleEvents(SDL_Event& event);
};

