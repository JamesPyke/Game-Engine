#include "CreateButton.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>


CreateButton::CreateButton()
{
}


CreateButton::~CreateButton()
{
}

CreateButton::CreateButton(std::string string, sf::Font& font, sf::Vector2f position, sf::Uint32 style)
{
}

void CreateButton::setColourTextNormal(sf::Color text)
{
	textNormal = text;
}

void CreateButton::setColourTextHover(sf::Color text)
{
	textHover = text;
}

void CreateButton::setColorTextClicked(sf::Color text)
{
	textClicked = text;
}

void CreateButton::setColourNormal(sf::Color colourNormal)
{
	buttonNormal = colourNormal;
}

void CreateButton::setColourHover(sf::Color colourHover)
{
	buttonHover = colourHover;
}

void CreateButton::setColourClicked(sf::Color colourClicked)
{
	buttonClicked = colourClicked;
}

void CreateButton::setBordercolour(sf::Color border)
{
	buttonBorder = border;
}

void CreateButton::setBorderThickness(float thickness)
{
	borderThickness = thickness;
}

void CreateButton::setBorderRadius(float radius)
{
	borderRadius = radius;
}

void CreateButton::setPosition(sf::Vector2f position)
{
	position = position;
}

void CreateButton::setSize(unsigned int size)
{
	size = size;
}

void CreateButton::setText(std::string text)
{
	buttonText.setString(text);
	textShadow = text;
}

void CreateButton::setStyle(sf::Uint32 style)
{
}

void CreateButton::setFont(sf::Font& font)
{
}

sf::Vector2f CreateButton::getPostion()
{
	return position;
}

sf::Vector2f CreateButton::getDimensions()
{
	return sf::Vector2f(createButton.getGlobalBounds().width, createButton.getGlobalBounds().height);
}

sf::Uint32 CreateButton::getState()
{
	return state;
}

void CreateButton::update(sf::Event& event, sf::RenderWindow& window)
{
}

bool CreateButton::getBounds(sf::Window window, int x, int y, int h, int w)
{
	return sf::Mouse::getPosition(window).x > button.getGlobalBounds().left &&
		sf::Mouse::getPosition(window).x < (button.getGlobalBounds().left + button.getGlobalBounds().width && 
		sf::Mouse::getPosition(window).y > button.getGlobalBounds().top && 
		sf::Mouse::getPosition(window).y < (button.getGlobalBounds().top + button.getGlobalBounds().height));
}
