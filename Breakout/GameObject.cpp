#include "GameObject.hpp"

GameObject::GameObject(const char* textureFile, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(textureFile, ren);

	xpos = x;
	ypos = y;


}

GameObject::~GameObject() {}

void GameObject::render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

void GameObject::setDestRectCoordinates(int x, int y) {
	destRect.x = x;
	destRect.y = y;
}

SDL_Rect GameObject::getDestRect() {
	return destRect;
}

void GameObject::changeTextureFile(const char* textureFile) {
	objTexture = TextureManager::LoadTexture(textureFile, renderer);
}

bool GameObject::checkForDeletion(BoxCollider* boxCollider) {
	vector<GameObject*> gameObjectsCopy;
	int toDelete = NULL;
	for (int i = 0; i < GameObject::gameObjects.size(); i++) {
		gameObjectsCopy.push_back(GameObject::gameObjects.at(i));
	}
	for (int i = 0; i < gameObjectsCopy.size(); i++) {
		GameObject* current = GameObject::gameObjects.at(i);
		if (current->boxCollider == boxCollider) {
			vector<string> brickDetails = current->getBrickDetails();
			if (brickDetails.at(0) == "I") {
				current->playHitSound();
				break;
			}
			int currentHP = stoi(brickDetails.at(2));
			if (currentHP <= 1) {
				toDelete = i;
				current->playBreakSound();
				delete current;
				delete boxCollider;
				Game::score += stoi(brickDetails[5]);
			}
			else {
				string id = brickDetails[0];
				if (id == "M") {
					current->changeTextureFile("Textures/Bricks/Medium_broken.dds");
				}
				else if(id == "H") {
					if (brickDetails[2] == "3"){
						current->changeTextureFile("Textures/Bricks/Hard_broken1.dds");
					}
					else {
						current->changeTextureFile("Textures/Bricks/Hard_broken2.dds");
					}
				}
				current->playHitSound();

				brickDetails[2] = to_string(stoi(brickDetails[2]) - 1);
				current->setBrickDetails(brickDetails);
			}
			break;
		}
	}
	if (toDelete) {
		GameObject::gameObjects.erase(GameObject::gameObjects.begin() + toDelete);
		return true;
	}
	return false;
}

void GameObject::setBoxColliderSize(int w, int h) {

	boxCollider->setSize(w, h);

}

void GameObject::setDestRectSize(int w, int h) {
	destRect.w = w;
	destRect.h = h;
}

