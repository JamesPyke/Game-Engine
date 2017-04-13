#include "Game.h"
#include "SFML/Graphics/RenderWindow.hpp"

Game::Game()
{
	window = nullptr;
	world = nullptr;
}

bool Game::initialize(sf::RenderWindow* window, b2World* world)
{
	this->window = window;
	this->world = world;

	return true;
}

bool Game::update(const float& deltaTime)
{
	return true;
}

void Game::draw()
{
	window->clear(sf::Color::Blue);

	window->display();
}
