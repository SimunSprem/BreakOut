#include "BoxCollider.hpp"

vector<BoxCollider*> BoxCollider::boxColliders;

BoxCollider::BoxCollider(int x, int y, int w, int h, const char* type) {

	xpos = x;
	ypos = y;
	width = w;
	height = h;
	objectType = type;
	
	BoxCollider::boxColliders.push_back(this);
}

BoxCollider::~BoxCollider() {};

void BoxCollider::moveCollider(int x, int y) {
	xpos = x;
	ypos = y;
	//std::cout << "Box collider coordinates are: " << xpos << " : " << ypos << std::endl;
}

BoxCollider* BoxCollider::checkCollision(BoxCollider* other) {
	int otherX = other->getX();
	int otherY = other->getY();
	int otherW = other->getWidth();
	int otherH = other->getHeight();

	int thisX = this->getX();
	int thisY = this->getY();
	int thisW = this->getWidth();
	int thisH = this->getHeight();

	if (thisX < (otherX + otherW) &&
		(thisX + thisW) > otherX &&
		thisY < (otherY + otherH) &&
		(thisY + thisH) > otherY)
		return other;

	return nullptr;

}

int BoxCollider::getX() { return xpos; }

int BoxCollider::getY() { return ypos; }

int BoxCollider::getWidth() { return width; }

int BoxCollider::getHeight() { return height; }

const char* BoxCollider::getObjectType() { return objectType; }

void BoxCollider::setSize(int w, int h) {
	width = w;
	height = h;
}
