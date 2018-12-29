#include "Ball.h"
#include "PlayState.h"
Ball::~Ball()
{
	textura = nullptr;
}
void Ball::update() {
	Vector2D prevPos = coord;
	Vector2D collVector;
	SDL_Rect destRect = getRect();
	coord = coord + velocidad;
	if (playstate->collides(destRect, collVector, velocidad)) { // llama al collides del game

		//velocidad.normalize();

		velocidad = velocidad - (collVector * (2 * (velocidad*collVector)));
		coord = prevPos + velocidad;
	}
	if (coord.getY() > 600 && playstate->getVidas() > 0)
	{
		resetBall();
	}

}
void Ball::resetBall() {
	coord = { 390,450 };
	playstate->menosVida();
}
void Ball::nuevoNv() {
	coord = { 390,450 };
}
bool Ball::handleEvents(SDL_Event& event) {
	return false;
}
