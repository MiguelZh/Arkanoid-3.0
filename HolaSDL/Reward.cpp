#include "Reward.h"
#include "PlayState.h"
Reward::~Reward()
{
	playstate = nullptr;
	paddle = nullptr;
	bola = nullptr;
}
void Reward::render() {
	if (SDL_GetTicks() > velocidadAnim + tiempo) {
		Frame++;
		tiempo = SDL_GetTicks();
		if (Frame == 7) {
			Frame = 0;
		}
		renderFrame(rewardT, Frame);
	}
}
bool Reward::handleEvents(SDL_Event& event) {
	return false;
}
void Reward::update() {
	if (coord.getY() > 600)
	{
		playstate->destruyeReward();
	}

	else if (SDL_HasIntersection(&(playstate->getPaddle())->getRect(), &getRect())) {
		TipodeRecompensa();
		playstate->destruyeReward();
	}
	coord = coord + velocidad;
}
void Reward::TipodeRecompensa() {

	switch (rewardT)
	{
	case 0: // nuevo nv
		playstate->rewardMasNivel();
		break;
	case 1: // alargar
		playstate->alargar();
		break;
	case 3: // acortar
		playstate->acortar();
		break;
	case 2: // vida++
		playstate->masVida();
		break;
	}
}

