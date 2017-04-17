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

	sf::Font fntFuel;
	sf::Text txtFuel;

	sf::Texture txtrPlayer;
	sf::Texture txtrBlockSingle;
	sf::Texture txtrBlockDouble;
	sf::Texture txtrBlockGround;
	sf::Texture txtrMovable;
	sf::Texture txtrTop;
	sf::Texture txtrEdge;
	sf::Texture txtrBackGround;

	//Player
	GameObject objPlayer;

	//Dynamic Blocks
	GameObject objMoveableBox1;
	GameObject objMoveableBox2;
	GameObject objMoveableBox3;
	GameObject objMoveableBox4;
	GameObject objMoveableBox5;
	GameObject objMoveableBox6;
	GameObject objMoveableBox7;
	GameObject objMoveableBox8;
	GameObject objMoveableBox9;
	GameObject objMoveableBox10;
	GameObject objMoveableBox11;


	//Static Blocks
	GameObject objSingle;
	GameObject objSingle2;
	GameObject objSingle3;
	GameObject objSingle4;
	GameObject objSingle5;

	GameObject objDouble;
	GameObject objDouble2;
	GameObject objDouble3;
	GameObject objDouble4;
	GameObject objDouble5;

	GameObject objGround;
	GameObject objBackGround;

	//Outside Bounds
	GameObject objTop;
	GameObject objLeft;
	GameObject objRight;


	std::vector<GameObject*> boxes;

};

