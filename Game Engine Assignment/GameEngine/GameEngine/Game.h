#pragma once
namespace sf {
	class RenderWindow;
}

class b2World;

class Game
{

public:

	Game();

	bool initialize(sf::RenderWindow* window, b2World* world);

	bool update(const float& deltaTime);
	void draw();

private:

	sf::RenderWindow* window;
	b2World* world;	

};

