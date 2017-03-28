#include "Logger.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "Box2D/Box2D.h"
#include  "Physics.h"
#include "PhysicsDynamic.h"
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
	Logger logger;
	InputManager input;
	ResourceManager resourceManager;
	

	sf::RenderWindow window(sf::VideoMode(1024, 768), "SlapEngine");

	sf::Sprite testSprite;
	sf::Sprite otherSprite;
	sf::Sprite box;

	//initialise spirte

	testSprite.setTexture(resourceManager.getTexture("SlapEngineLogo.png"));
	testSprite.setPosition(0, 0);
	otherSprite.setTexture(resourceManager.getTexture("SlapEngineLogo.png"));
	otherSprite.setPosition(1024, 0);
	otherSprite.setScale(-1, 1);

	window.setFramerateLimit(60);

	b2Vec2 gravity(0.0f, 30.f);
	b2World world(gravity);


	//box2D();
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
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
					{
						for (auto body : Physics::physicsBodies )
						{
							world.DestroyBody(body);
						}

						Physics::physicsBodies.clear();
					}
					break;
				case sf::Event::KeyReleased:
					input.setKeyState(event.key.code, false);
					break;	
				case sf::Event::MouseButtonPressed:
					input.setMouseState(event.mouseButton.button, true);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						int mouseX = sf::Mouse::getPosition(window).x;
						int mouseY = sf::Mouse::getPosition(window).y;
					//	dynamic.createDynamicBox(world, mouseX, mouseY);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
					{
						int mouseX = sf::Mouse::getPosition(window).x;
						int mouseY = sf::Mouse::getPosition(window).y;
					//	physics.createGround(world, mouseX, mouseY);
					}
					printf("Body Count: %d\n", Physics::physicsBodies.size());
					break;
				case sf::Event::MouseButtonReleased:
					input.setMouseState(event.mouseButton.button, false);
					break;
				default: 
					break;
			}
		}
		world.Step(1 / 60.0f, 8, 3);
		window.clear(sf::Color::Black);
		for (b2Body* bodyIterator = world.GetBodyList(); bodyIterator != nullptr; bodyIterator = bodyIterator->GetNext())
		{
			if (bodyIterator->GetType() == b2_dynamicBody)
			{
				box.setTexture(resourceManager.getTexture("box.png"));
				box.setOrigin(16.0f, 16.0f);
				box.setPosition(bodyIterator->GetPosition().x *  30.0f, bodyIterator->GetPosition().y *  30.0f);
				box.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);
				window.draw(box);
			}
			else
			{
				sf::Sprite ground;
				ground.setTexture(resourceManager.getTexture("ground.png"));
				ground.setOrigin(64/2, 64/2);
				ground.setPosition(bodyIterator->GetPosition().x * 30.0f, bodyIterator->GetPosition().y * 30.0f );
				ground.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);
				window.draw(ground);
			}
		}
		// Update
		input.swapKeyStates();
		input.swapMouseStates();
		// Draw	
		//window.clear();
		//Draw Sprites
		window.draw(testSprite);
		//window.draw(otherSprite);
		window.display();
	}

	return 0;
}