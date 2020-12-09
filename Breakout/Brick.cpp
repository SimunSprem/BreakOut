#include "Brick.hpp"


int Brick::numOfImpenetrableBricks;

Brick::Brick(const char* textureFile, SDL_Renderer* ren, int x, int y) : GameObject(textureFile, ren, 0, 0) {

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.h = 16;
	destRect.w = 800;


	boxCollider = new BoxCollider(x, y, destRect.w, destRect.h, "Brick");

}

Brick::Brick(std::vector<std::string> &info, SDL_Renderer* renderer, int x, int y) : GameObject(info.at(1).c_str(), renderer, x, y) {

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.h = 20;
	destRect.w = 35;

	boxCollider = new BoxCollider(x, y, destRect.w, destRect.h, "Brick");

	id = info.at(0);
	textureFile = info.at(1);
	hitPoints = info.at(2);
	hitSound = info.at(3);
	if (id != "I") {
		breakSound = info.at(4);
		breakScore = info.at(5);
	}
	else
		numOfImpenetrableBricks++;

	hitSFX = new Sound(hitSound.c_str());
	breakSFX = new Sound(breakSound.c_str());

	GameObject::gameObjects.push_back(this);
}

Brick::~Brick() {}

void Brick::resizeBrick(int w, int h) {
	this->destRect.w = w;
	this->destRect.h = h;
	this->setBoxColliderSize(w, h);
}

void Brick::addToBricks(Brick* brick) {
	Brick::bricks.push_back(brick);
}

void Brick::move(int x, int y) {

}

void Brick::update() {

}

vector<string> Brick::getBrickDetails() {
	return vector<string>{id, textureFile, hitPoints, hitSound, breakSound, breakScore};
}

void Brick::reduceHP() {
	hitPoints = to_string(stoi(hitPoints) - 1);
}

void Brick::setBrickDetails(vector<string> details) {
		id = details.at(0);
		textureFile = details.at(1);
		hitPoints = details.at(2);
		hitSound = details.at(3);
		if (id != "I") {
			breakSound = details.at(4);
			breakScore = details.at(5);
		}
}

void Brick::playBreakSound() {
	this->breakSFX->playSound();
}

void Brick::playHitSound() {
	this->hitSFX->playSound();
}
