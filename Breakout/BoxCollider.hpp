#pragma once

#include "Game.hpp"
#include <vector>

using namespace std;

class BoxCollider {
public:
	BoxCollider(int x, int y, int w, int h, const char* type);
	~BoxCollider();
	void moveCollider(int x, int y);
	void setSize(int w, int h);

	static vector<BoxCollider*> boxColliders;
	BoxCollider* checkCollision(BoxCollider* other);

	int getX();
	int getY();
	int getWidth();
	int getHeight();
	const char* getObjectType();

private:
	const char* objectType;
	int xpos, ypos;
	int width, height;
};