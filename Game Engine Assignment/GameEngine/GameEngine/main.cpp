#include "LogManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "Box2D/Box2D.h"
#include  "Physics.h"
#include "PhysicsDynamic.h"
#include "Button.h"
#include "Game.h"

/*! \mainpage Welcome to the Slap Engine Documentation
*
* \section intro_sec Introduction
*
* To get started hit the Class tab or try the search bar.
* 
*  
*  
*
*  \author    James Pyke
*  \version   1.0
* 
*/


int main()
{
	LogManager logger;
	InputManager input;

	sf::RenderWindow window(sf::VideoMode(1024, 768), "SlapEngine");

	sf::Clock deltaClock;
	float deltaTime = 0.0f;
	
	window.setFramerateLimit(60);

	b2Vec2 gravity(0.0f, 30.f);
	b2World world(gravity);

	Game game;

	game.initialize(&window, &world);

	while (window.isOpen())
	{
		// Event Loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					input.setKeyState(event.key.code, true);
					break;
				case sf::Event::KeyReleased:
					input.setKeyState(event.key.code, false);
					break;	
				case sf::Event::MouseButtonPressed:
					input.setMouseState(event.mouseButton.button, true);
					break;
				case sf::Event::MouseButtonReleased:
					input.setMouseState(event.mouseButton.button, false);
					break;
				default: 
					break;
			}
		}

		input.swapKeyStates();
		input.swapMouseStates();

		game.update(deltaTime);
		game.draw();



		deltaTime = deltaClock.restart().asSeconds();

	}

	return 0;
}