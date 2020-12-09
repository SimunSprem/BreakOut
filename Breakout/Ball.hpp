#pragma once

#include "GameObject.hpp"
#include <random>
#include <math.h>
#include <time.h>
#include <chrono>

class Ball : public GameObject {

public:
	Ball(const char* texture, SDL_Renderer* ren, int x, int y);

	double speed;
	int brickHits;
	double coef;

	void collision();
	virtual void move(int x, int y);
	virtual void update();
	virtual vector<string> getBrickDetails();
	virtual void setBrickDetails(vector<string> details);
	virtual void playBreakSound();
	virtual void playHitSound();

	double generateDirection();
	static void createBallRandom(SDL_Renderer* ren, int x, int y);

	static vector<Ball*> balls;


private:
	int lastCollision, limit;
	Uint32 now;
	int directionX, directionY;
	double a;
};

