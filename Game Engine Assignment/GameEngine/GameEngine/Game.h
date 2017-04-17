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

	/**
	 * \brief Default constructor
	 */
	Game();

	/**
	 * \brief Initializes the Game using the render window and the defined world
	 * \param window window
	 * \param world world
	 * \return bool
	 */
	bool initialize(sf::RenderWindow* window, b2World* world);

	/**
	 * \brief updates the game frame by frame
	 * \param deltaTime deltatime
	 * \return bool
	 */
	bool update(const float& deltaTime);
	/**
	 * \brief Draws everything in the game world
	 */
	void draw();

private:

	/**
	 * \brief Sets the player's movement speed
	 */
	const float PLAYER_MOVEMENT_SPEED = 500.0f;
	/**
	 * \brief Sets the player's jump height and fuel
	 */
	float playerJumpHeight = 40.0f;

	/**
	 * \brief Points to the window
	 */
	sf::RenderWindow* window;
	/**
	 * \brief Points to the world
	 */
	b2World* world;	

	/**
	 * \brief Creates and instance of the resource manager to load in the textures
	 */
	ResourceManager resourceManager;
	/**
	 * \brief Creates and instance of the input manager
	 */
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


	/**
	 * \brief Creates a vector of gameObjects
	 */
	std::vector<GameObject*> boxes;

};

