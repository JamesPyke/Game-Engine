#include <SFML/Graphics.hpp>
#include "Logger.h"
#include "InputManager.h"

int main()
{
	Logger logger;
	InputManager input;

	sf::RenderWindow window(sf::VideoMode(800, 800), "SlapEngine");

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
			}
		}

		// Update
		input.swapKeyStates();
		input.swapMouseStates();

		// Draw

		window.clear();
				
		window.display();
	}

	return 0;
}