#pragma once

#include "GameObject.hpp"

class Player : public GameObject {

public:
	Player(const char* texture, SDL_Renderer* ren, int x, int y);

	int speed;

	int getX();
	int getY();
	virtual void move(int x, int y);
	virtual void update();
	virtual vector<string> getBrickDetails();
	virtual void setBrickDetails(vector<string> details);
	virtual void playBreakSound();
	virtual void playHitSound();

};