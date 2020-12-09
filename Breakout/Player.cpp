#include "Player.hpp"


Player::Player(const char* texture, SDL_Renderer* ren, int x, int y) : GameObject("Assets/player.png", ren, x, y) {
	speed = 7;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.h = 12;
	destRect.w = 150;

	boxCollider = new BoxCollider(x, y, destRect.w, destRect.h, "Player");
	GameObject::gameObjects.push_back(this);
}

void Player::move(int x, int y) {
	SDL_Rect destRect = getDestRect();
	if (x > 0) {
		if (destRect.x < 630) {
			setDestRectCoordinates(destRect.x + x, y);
			boxCollider->moveCollider(destRect.x + x, y);
		}
	}
	else {
		if (destRect.x > 20) {
			setDestRectCoordinates(destRect.x + x, y);
			boxCollider->moveCollider(destRect.x + x, y);
		}
	}
}

void Player::update() {

}

vector<string> Player::getBrickDetails() {
	return vector<string>(' ');
}

void Player::setBrickDetails(vector<string> details) {

}

void Player::playBreakSound() {

}
void Player::playHitSound() {

}