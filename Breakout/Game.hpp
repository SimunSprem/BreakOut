#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>
#include "Text.hpp"
#include "Sound.hpp"


class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void update();
	void render();
	void clean();
	void handleEvents();

	static int score;
	int numOfLevel = 1;
	static int lives;

	bool running() { return isRunning; };

	static SDL_Event event;
	static TTF_Font* font;

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

};

