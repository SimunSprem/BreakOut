#pragma once

#include <SDL_ttf.h>
#include <string>
#include <vector>

class Text {
public:
	Text(const char* t, TTF_Font* f, SDL_Renderer* ren, int xPos, int yPos);
	void render();
	static void clean();
	void updateText(const char* t);

	SDL_Renderer* renderer;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Rect dstrect;
	SDL_Color color;
	TTF_Font* font;

	static std::vector<Text*> texts;

private:
	const char* text;
	int texW;
	int texH;
	int x;
	int y;
};