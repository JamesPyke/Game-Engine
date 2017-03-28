#pragma once
#include "Box2D/Box2D.h"

#include <vector>

class Physics
{
public:

	Physics(b2World world, float x, float y, float width, float height);

	Physics();


protected:
	b2Body *body;

	/**
	 * \brief Create a vector of all physics bodies created
	 */
	static std::vector<b2Body*> physicsBodies;
	/**
	 * \brief Create a static ground sprite
	 * \param b2World world 
	 * \param float x 
	 * \param float y 
	 */
};

