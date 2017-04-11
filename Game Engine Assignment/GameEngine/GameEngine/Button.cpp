#include "Button.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>


Button::Button()
{
}


Button::~Button()
{
}

Button::Button(std::string string, sf::Font& font, sf::Vector2f position, sf::Uint32 style)
{
}

void Button::setColourTextNormal(sf::Color text)
{
	textNormal = text;
}

void Button::setColourTextHover(sf::Color text)
{
	textHover = text;
}

void Button::setColorTextClicked(sf::Color text)
{
	textClicked = text;
}

void Button::setColourNormal(sf::Color colourNormal)
{
	buttonNormal = colourNormal;
}

void Button::setColourHover(sf::Color colourHover)
{
	buttonHover = colourHover;
}

void Button::setColourClicked(sf::Color colourClicked)
{
	buttonClicked = colourClicked;
}

void Button::setBordercolour(sf::Color border)
{
	buttonBorder = border;
}

void Button::setBorderThickness(float thickness)
{
	borderThickness = thickness;
}

void Button::setBorderRadius(float radius)
{
	borderRadius = radius;
}

void Button::setPosition(sf::Vector2f position)
{
	position = position;
}

void Button::setSize(unsigned int size)
{
	size = size;
}

void Button::setText(std::string text)
{
	buttonText.setString(text);
	textShadow = text;
}

void Button::setStyle(sf::Uint32 style)
{
}

void Button::setFont(sf::Font& font)
{
}

sf::Vector2f Button::getPostion()
{
	return position;
}

sf::Vector2f Button::getDimensions()
{
	return sf::Vector2f(createButton.getGlobalBounds().width, createButton.getGlobalBounds().height);
}

sf::Uint32 Button::getState()
{
	return state;
}

void Button::update(sf::Event& event, sf::RenderWindow& window)
{
}

bool Button::getBounds(sf::Window window, int x, int y, int h, int w)
{
	return sf::Mouse::getPosition(window).x > button.getGlobalBounds().left &&
		sf::Mouse::getPosition(window).x < (button.getGlobalBounds().left + button.getGlobalBounds().width && 
		sf::Mouse::getPosition(window).y > button.getGlobalBounds().top && 
		sf::Mouse::getPosition(window).y < (button.getGlobalBounds().top + button.getGlobalBounds().height));
}
