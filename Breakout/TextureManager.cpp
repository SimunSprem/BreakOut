#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* renderer)
{

	SDL_Surface* surface = IMG_Load(texture);
	SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return playerTexture;
}