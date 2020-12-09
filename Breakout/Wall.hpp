#pragma once

#include "GameObject.hpp"

class Wall : public GameObject {
public:
	Wall(const char* texture, SDL_Renderer* ren, int x, int y);
	virtual void move(int x, int y);
	virtual void update();
	virtual vector<string> getBrickDetails();
	virtual void setBrickDetails(vector<string> details);
	virtual void playBreakSound();
	virtual void playHitSound();
};

