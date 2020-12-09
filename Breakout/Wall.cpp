#include "Wall.hpp"

Wall::Wall(const char* texture, SDL_Renderer* ren, int x, int y) : GameObject("Assets/wall.png", ren, x, y) {

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.h = 600;
	destRect.w = 20;

	boxCollider = new BoxCollider(x, y, destRect.w + 8, destRect.h, "Wall");
	boxCollider->moveCollider(x - 4, y);
	GameObject::gameObjects.push_back(this);
}

void Wall::move(int x, int y) {

}

void Wall::update() {

}

vector<string> Wall::getBrickDetails() {
	return vector<string>(' ');
}

void Wall::setBrickDetails(vector<string> details) {

}

void Wall::playBreakSound() {

}
void Wall::playHitSound() {

}
