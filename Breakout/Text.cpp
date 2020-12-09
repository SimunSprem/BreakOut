#include "Text.hpp"

std::vector<Text*> Text::texts;

Text::Text(const char* t, TTF_Font* f, SDL_Renderer* ren, int xPos, int yPos) {
	color = { 255, 255, 255 };
	text = t;
	font = f;
	renderer = ren;

	surface = TTF_RenderText_Solid(font, text, color);

	texture = SDL_CreateTextureFromSurface(ren, surface);
	texW = 0;
	texH = 0;
	x = xPos;
	y = yPos;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	dstrect = { xPos, yPos, texW, texH };
	Text::texts.push_back(this);
}

void Text::updateText(const char* t) {
	color = { 255, 255, 255 };
	text = t;
/*
	SDL_FreeSurface(this->surface);
	SDL_DestroyTexture(this->texture);*/

	surface = TTF_RenderText_Solid(font, text, color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	texW = 0;
	texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	dstrect = { x, y, texW, texH };
}

void Text::render() {
	//updateText(text);
	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	//SDL_RenderPresent(renderer);
}

void Text::clean() {
	for (Text* t : Text::texts) {
		SDL_DestroyTexture(t->texture);
		SDL_FreeSurface(t->surface);
	}

}