#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Vector2D.h"
#include "Ball.h"


void Ball::update() {
	Vector2D prevPos = coord;
	Vector2D collVector;
	SDL_Rect destRect = getRect();
	coord = coord + velocidad;
	if (game->collides(destRect, collVector, velocidad)) { // llama al collides del game

		//velocidad.normalize();

		velocidad = velocidad - (collVector * (2 * (velocidad*collVector)));
		coord = prevPos + velocidad;
	}
	if (coord.getY() > 600 && game->getVidas() > 0)
	{
		resetBall();
	}

}
void Ball::resetBall() {
	coord = { 390,450 };
	game->menosVida();
}
void Ball::nuevoNv() {
	coord = { 390,450 };
}
