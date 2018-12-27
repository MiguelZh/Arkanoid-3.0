#include "SDLApplication.h"

SDLApplication::~SDLApplication() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = nullptr;
	window = nullptr;
	delete stateMachine;
	stateMachine = nullptr;
	for (int i = 0; i < NUM_TEXTURES; i++) {
		delete textures[i];
		textures[i] = nullptr;
	}
	SDL_Quit();
};
SDLApplication::SDLApplication() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid 3.0", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	cout << "empieza el juego";
	for (int i = 0; i < NUM_TEXTURES; i++) {
		textures[i] = new Texture(renderer);
		textures[i]->load(nombreMenus[i]);
	}
	stateMachine = new GameStateMachine();
	stateMachine->pushState(new MainMenuState(this));
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
Texture * SDLApplication::getTexture(int num) {
	return textures[num]; // 0 al 3 botones y 3 al 9 del game
}
GameStateMachine * SDLApplication::getStateMachine() {
	return stateMachine;
}