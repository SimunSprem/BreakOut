#include "Game.hpp"


Game *game = nullptr;

int main(int argc, char *argv[]) {

	game = new Game();

	game->init("BREAKOUT!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	const int FPS = 90;
	const int frameTime = 1000 / FPS;
	Uint32 frameStart;
	int frameEnd;


	while (game->running()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameEnd = SDL_GetTicks() - frameStart;

		if (frameTime > frameEnd) 
		{
			SDL_Delay(frameTime - frameEnd);
		}

	}

	game->clean();

	return 0;
}
