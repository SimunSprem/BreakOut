#include "Ball.hpp"

vector<Ball*> Ball::balls;

Ball::Ball(const char* texture, SDL_Renderer* ren, int x, int y) : GameObject("Assets/ball.dds", ren, x, y) {

	speed = 2;
	brickHits = 0;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.h = 8;
	destRect.w = 8;
	coef = 0;

	directionX = 1;
	directionY = 1;
	a = 0;


	lastCollision = SDL_GetTicks();

	boxCollider = new BoxCollider(x, y, destRect.w + 2, destRect.h + 2, "Ball");
	Ball::balls.push_back(this);
}


void Ball::move(int x, int y) {
	destRect.x = x;
	destRect.y = y;
	boxCollider->moveCollider(x, y);
}

double Ball::generateDirection() {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution <> dis(0.5, M_PI / 3);
	double deg = dis(gen);
	coef = tan(-deg);
	return coef;
}

void Ball::update() {
	now = SDL_GetTicks();
	if (20 < now - lastCollision) {
		for (int i = 0; i < BoxCollider::boxColliders.size(); i++) {
			BoxCollider* other = boxCollider->checkCollision(BoxCollider::boxColliders.at(i));

			if (other) {

				if (other->getObjectType() == "Player") {
					//cout << "Player" << endl;
					directionY = -1;
					generateDirection();

					brickHits++;
					if (brickHits > 5 && speed < 5) {
						speed *= 1.2;
						brickHits = 0;
					}
				}

				else if (other->getObjectType() == "Brick") {
					//cout << "Brick" << endl;
					directionY = 1;
					int otherX = other->getX();
					int otherY = other->getY();
					if (GameObject::checkForDeletion(other))
						Ball::createBallRandom(renderer, otherX, otherY);

					brickHits++;
					if (brickHits > 5 && speed < 5) {
						speed *= 1.2;
						brickHits = 0;
						//cout << "Box collider set to: " << this->boxCollider->getWidth() << " " << this->boxCollider->getHeight() << endl;
					}
					//cout << cos(coef) << " " << sin(coef) << " " << coef << " " << directionX << " " << directionY << endl;
				}

				else if (other->getObjectType() == "Wall") {
					//cout << "Wall" << endl;
					directionX = -directionX;
					//cout << cos(coef) << " " << sin(coef) << " " << coef << " " << directionX << " " << directionY << endl;
				}

				else if (other->getObjectType() == "Ball") {
					continue;
				}

			}
		}
		lastCollision = SDL_GetTicks();
	}


	a += coef;
	int lowestInt = floor(a);
	a -= lowestInt;

	move(destRect.x + lowestInt * directionX * speed, destRect.y + directionY * speed);
	if (destRect.y > 620) {
		Game::lives--;
		if (Game::lives > 0) {
			if (Ball::balls.size() == 1) {
				this->setDestRectCoordinates(396, 300);
				this->coef = 0;
				this->speed = 2;
			}
			else {
				Ball::balls.erase(find(Ball::balls.begin(), Ball::balls.end(), this));
				delete this;
			}
		}
		else {
			Ball::balls.erase(find(Ball::balls.begin(), Ball::balls.end(), this));
			delete this;
		}
	}
	if (destRect.x < 5) {
		this->setDestRectCoordinates(396, 300);
		this->coef = 0;
		directionY = 1;
	}
	if (destRect.x > 795) {
		this->setDestRectCoordinates(396, 300);
		this->coef = 0;
		directionY = 1;
	}	
	if (destRect.y < 0) {
		this->setDestRectCoordinates(396, 300);
		this->coef = 0;
		directionY = 1;
	}
	//else if (785 >= destRect.x >= 20 || destRect.y < 0) {
	//	this->setDestRectCoordinates(396, 300);
	//	this->coef = 0;
	//}
		
	//cout << destRect.x << ", " << destRect.y << endl;
	//cout  << " " << coef << " " << directionX << " " << directionY << " " << a << endl;

}

vector<string> Ball::getBrickDetails() {
	return vector<string>(' ');
}
void Ball::setBrickDetails(vector<string> details) {

}

void Ball::createBallRandom(SDL_Renderer* ren, int x, int y) {

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution <> dis(0, 1);
	double n = dis(gen);
	if (n <= 0.5) {
		if (GameObject::gameObjects.size() > 4) {
			new Ball("Assets/ball.dds", ren, x, y);
			Game::lives++;
		}
	}

}


void Ball::playBreakSound() {

}
void Ball::playHitSound() {

}
