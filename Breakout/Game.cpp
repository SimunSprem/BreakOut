#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "Wall.hpp"
#include "XMLLoader.hpp"
#include "Level.hpp"
#include "SDL_ttf.h"
#include "SceneManager.hpp"

using namespace std;

vector<Brick*> Brick::bricks;
vector<GameObject*> GameObject::gameObjects;
int Game::score = 0;
int Game::lives = 6;

Game::Game() {}
Game::~Game() {}

Player* player;
Ball* ball;
Brick* brick1;
Brick* brick2;
Brick* brick3;
Brick* brick4;
Wall* wall1;
Wall* wall2;
Level* level;
XMLLoader* loader;
SceneManager* sm;

SDL_Event Game::event;
TTF_Font* Game::font;


int counter = 0;



void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	srand(time(NULL));
	int flags = 0;
	if (fullscreen) 
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialised" << std::endl;
		TTF_Init();

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
			std::cout << "Window created!" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			std::cout << "Renderer created!" << std::endl;
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		}

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048))
			std::cout << "Sounds enabled!" << std::endl;
		Game::font = TTF_OpenFont("./Fonts/arial.ttf", 25);

		isRunning = true;
	}
	sm = new SceneManager("MainMenu", renderer);
}

void Game::update() 
{
	for (int i = 0; i < Ball::balls.size(); i++) {
		Ball::balls[i]->update();
	}
	sm->update();
}

void Game::render() {
	SDL_RenderClear(renderer);

	for (GameObject* go : GameObject::gameObjects) {
		go->render();
	}
	for (Ball* b : Ball::balls) {
		b->render();
	}
	if (sm->getSID() != "MainMenu") {
		SceneManager::scoreNum->updateText(to_string(Game::score).c_str());
		SceneManager::livesNum->updateText(to_string(Game::lives).c_str());
		if (Game::lives == 0) {
			SDL_Delay(2000);
			Game::isRunning = false;
		}
	}
	for (Text* t : Text::texts) {
		t->render();
	}

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Text::clean();
	TTF_CloseFont(font);
	TTF_Quit();
	Mix_Quit();	
	SDL_Quit();


	std::cout << "Quitting..." << std::endl;
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					GameObject::gameObjects.at(1)->move(-7, GameObject::gameObjects.at(1)->getDestRect().y);
					break;
				case SDLK_RIGHT:
					GameObject::gameObjects.at(1)->move(7, GameObject::gameObjects.at(1)->getDestRect().y);
					break;
				case SDLK_UP:
					if (sm->getSID() == "MainMenu") {
						sm->setSelected(0);
						sm->mainMenuPointer->setDestRectCoordinates(400, 220);
					}
					break;
				case SDLK_DOWN:
					if (sm->getSID() == "MainMenu") {
						sm->setSelected(1);
						sm->mainMenuPointer->setDestRectCoordinates(400, 420);
					}
					break;
				case SDLK_RETURN:
					if (sm->getSID() == "MainMenu") {
						if (sm->getSelected() == 0)
							sm->nextLevel("Level1");
						else if (sm->getSelected() == 1)
							isRunning = false;
					}
					break;
				default:
					break;
			}
			break;
		default:
			break;
		}
	}
}



