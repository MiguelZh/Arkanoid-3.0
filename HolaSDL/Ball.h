#pragma once
#include"MovingObject.h"
class PlayState;
class Ball : public MovingObject
{
private:
	PlayState * playstate;
public:
	Ball(uint ancho, uint alto, Vector2D coord, Texture * textura, Vector2D vel, PlayState * p) :
		MovingObject(ancho, alto, coord, textura, vel), playstate(p) {}
	~Ball();
	void update();
	void resetBall();
	void nuevoNv();
};

