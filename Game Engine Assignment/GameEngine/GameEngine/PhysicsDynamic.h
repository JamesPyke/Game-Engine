#pragma once
#include "Physics.h"
class PhysicsDynamic :
	public Physics
{
public:
	PhysicsDynamic(b2World world, float x, float y, float width, float height);
	/**
	* \brief Create a dynamic circle sprite
	* \param b2World world
	* \param int mouseX
	* \param int mouseY
	* \param float radius
	*/
//	static void createCircle(b2World& world, int mouseX, int mouseY, float radius);



};

