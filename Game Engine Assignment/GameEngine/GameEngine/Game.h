#pragma once
#include "ResourceManager.h"
#include "GameObject.h"
#include "InputManager.h"

namespace sf {
	class RenderWindow;
}

class b2World;

class Game
{

public:

	Game();

	bool initialize(sf::RenderWindow* window, b2World* world);

	bool update(const float& deltaTime);
	void draw();

private:

	const float PLAYER_MOVEMENT_SPEED = 500.0f;
	float playerJumpHeight = 40.0f;

	sf::RenderWindow* window;
	b2World* world;	

	ResourceManager resourceManager;
	InputManager inputManager;

	sf::Texture txtrPlayer;
	sf::Texture txtrBlockSingle;
	sf::Texture txtrBlockDouble;
	sf::Texture txtrBlockGround;
	sf::Texture txtrMovable;

	GameObject objPlayer;

	GameObject objMoveableBox;
	GameObject objSingle;
	GameObject objDouble;
	GameObject objGround;


	std::vector<GameObject*> boxes;

};

