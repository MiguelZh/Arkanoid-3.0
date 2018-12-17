#include "SDLApplication.h"

SDLApplication::~SDLApplication() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Quit();
};
SDLApplication::SDLApplication() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	stateMachine->pushState();
}
void SDLApplication::run() {
	while (!exit) {
		handleEvents();
		update();
		render();
	}
}
void SDLApplication::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) {
			exit = true;
		}
		else {
			stateMachine->getCurrentState()->handleEvent(event);
		}
	}

}
void SDLApplication::update() {
	//llamo al update de la maquina de estado, render currentState
	stateMachine->getCurrentState()->update();
}
void SDLApplication::render() const {
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;
	else {
		SDL_RenderClear(renderer);
		//llamo al render de la maquina de estado, render currentState
		stateMachine->getCurrentState()->render();
		SDL_RenderPresent(renderer);
	}
}