#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/ConvexShape.hpp>

namespace sf {
	class Event;
	class Font;
	class Window;
}

class CreateButton
{
public:
	CreateButton();
	~CreateButton();
	CreateButton(std::string string, sf::Font& font, sf::Vector2f position, sf::Uint32 style);

	void setColourTextNormal(sf::Color text);
	void setColourTextHover(sf::Color text);
	void setColorTextClicked(sf::Color text);
	void setColourNormal(sf::Color colourNormal);
	void setColourHover(sf::Color colourHover);
	void setColourClicked(sf::Color colourClicked);
	void setBordercolour(sf::Color border);
	void setBorderThickness(float thickness);
	void setBorderRadius(float radius);
	void setPosition(sf::Vector2f position);
	void setSize(unsigned int size);
	void setText(std::string text);
	void setStyle(sf::Uint32 style);
	void setFont(sf::Font& font);
	
	sf::Vector2f getPostion();
	sf::Vector2f getDimensions();

	sf::Uint32 getState();
	void update(sf::Event& event, sf::RenderWindow& window);

	sf::Sprite createButton;

	bool getBounds(sf::Window window, int x, int y, int h, int w);

private:

	sf::Color textNormal;
	sf::Color textHover;
	sf::Color textClicked;
	sf::Color buttonNormal;
	sf::Color buttonHover;
	sf::Color buttonClicked;
	sf::Color buttonBorder;

	float borderThickness;
	float borderRadius;

	sf::Vector2f size;
	sf::Vector2f position;

	sf::Uint32 style;
	sf::Uint32 state;

	sf::ConvexShape button;

	sf::Font font;

	unsigned int fontSize;

	sf::Text buttonText;
	std::string textShadow;

};

