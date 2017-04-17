#pragma once
#include "Box2D/Box2D.h"

#include <vector>
#include <SFML/Graphics/Sprite.hpp>

class Physics
{
public:

	/**
	 * \brief Creates a default constructor for the Physics class
	 * \param world world 
	 * \param x x position 
	 * \param y y position 
	 * \param width width 
	 * \param height height 
	 */
	Physics(b2World world, float x, float y, float width, float height);

	Physics();
	/**
	 * \brief Points to a b2Body  
	 */
	b2Body *body;

	/**
	 * \brief Create a vector of all physics bodies created
	 */
	static std::vector<b2Body*> physicsBodies;

	sf::Sprite &getSprite() { return sprite; }
	sf::Vector2f getPosition(float x, float y);
	int getRotation() { return angle * 180 / b2_pi; }

private:
	sf::Sprite sprite;
	sf::Vector2f position;
	int angle;
};

