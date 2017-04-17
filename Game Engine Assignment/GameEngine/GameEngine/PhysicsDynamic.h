#pragma once
#include "Physics.h"
class PhysicsDynamic :
	public Physics
{
public:

	/**
	 * \brief Creates a Dynamic body using the base Physics class
	 * \param world world 
	 * \param x x position 
	 * \param y y poisiton 
	 * \param width width 
	 * \param height height 
	 */
	PhysicsDynamic(b2World world, float x, float y, float width, float height);
	/**
	* \brief Create a dynamic circle sprite
	* \param world world
	* \param mouseX mouse position x 
	* \param mouseY mouse position y 
	* \param radius radius
	*/
//	static void createCircle(b2World& world, int mouseX, int mouseY, float radius);
};

