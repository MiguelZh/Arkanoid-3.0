#pragma once
#include"MovingObject.h"
class Ball : public MovingObject
{
public:
	Ball();
	~Ball();
	void update();
	void resetBall();
	void nuevoNv();
};

