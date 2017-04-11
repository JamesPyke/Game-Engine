#pragma once
#include "Box2D/Box2D.h"

#include <vector>

class Physics
{
public:

	/**
	 * \brief Creates a default constructor for the Physics class
	 * \param b2World world 
	 * \param float x 
	 * \param float y 
	 * \param float width 
	 * \param float height 
	 */
	Physics(b2World world, float x, float y, float width, float height);

	Physics();


protected:
	/**
	 * \brief Points to a b2Body  
	 */
	b2Body *body;

	/**
	 * \brief Create a vector of all physics bodies created
	 */
	static std::vector<b2Body*> physicsBodies;

};

