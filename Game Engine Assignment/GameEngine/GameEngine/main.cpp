#include "Logger.h"
#include "InputManager.h"
#include "ResourceManager.h"

int main()
{
	Logger logger;
	InputManager input;

	sf::RenderWindow window(sf::VideoMode(1024, 768), "SlapEngine");

	ResourceManager resourceManager;

	sf::Sound testSound(resourceManager.getAudio("applause.wav"));
	//resourceManager.getMusic("applause.wav").play();

	sf::Sprite testSprite;
	sf::Sprite otherSprite;
	//initialise spirte

	testSprite.setTexture(resourceManager.getTexture("SlapEngineLogo.png"));
	testSprite.setPosition(0, 0);
	otherSprite.setTexture(resourceManager.getTexture("SlapEngineLogo.png"));
	otherSprite.setPosition(1024, 0);
	otherSprite.setScale(-1, 1);

	//testSound.play();

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

		// Update
		input.swapKeyStates();
		input.swapMouseStates();

		// Draw

		window.clear();

		//Draw Sprites
		window.draw(testSprite);
		window.draw(otherSprite);
	
		window.display();
	}

	return 0;
}