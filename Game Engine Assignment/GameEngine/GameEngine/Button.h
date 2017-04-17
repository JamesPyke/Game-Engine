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

class Button
{
public:

	/**
	 * \brief Default constructor for create button
	 */
	Button();
	/**
	 * \brief Default deconstructor for create button
	 */
	~Button();
	/**
	 * \brief Constructor for create button
	 * \param string name of string
	 * \param font name of font
	 * \param position position
	 * \param style style
	 */
	Button(std::string string, sf::Font& font, sf::Vector2f position, sf::Uint32 style);

	/**
	 * \brief Sets the colour for the text for the default button look
	 * \param text colour
	 */
	void setColourTextNormal(sf::Color text);
	/**
	 * \brief Sets the colour for the text when the button is hovered 
	 * \param text colour
	 */
	void setColourTextHover(sf::Color text);
	/**
	 * \brief Sets the colour for the text when the button is clicked
	 * \param text colour
	 */
	void setColorTextClicked(sf::Color text);
	/**
	 * \brief Sets the colour for the defualt button 
	 * \param colour colour 
	 */
	void setColourNormal(sf::Color colourNormal);
	/**
	 * \brief Sets the colour for the button when hovered
	 * \param colour colour
	 */
	void setColourHover(sf::Color colourHover);
	/**
	 * \brief Sets the colour for the button when the button is clicked
	 * \param colour colour
	 */
	void setColourClicked(sf::Color colourClicked);
	/**
	 * \brief Sets the colour for the border of the button by default
	 * \param border colour
	 */
	void setBordercolour(sf::Color border);
	/**
	 * \brief Sets the thickness for the border of the button
	 * \param thickness thickness
	 */
	void setBorderThickness(float thickness);
	/**
	 * \brief Sets the radius for the border
	 * \param radius radius
	 */
	void setBorderRadius(float radius);
	/**
	 * \brief Sets the position of the Button
	 * \param position position 
	 */
	void setPosition(sf::Vector2f position);
	/**
	 * \brief Sets the size of the button
	 * \param size size 
	 */
	void setSize(unsigned int size);
	/**
	 * \brief Sets the text inside the button
	 * \param text text 
	 */
	void setText(std::string text);
	/**
	 * \brief Sets the style of the button
	 * \param style style 
	 */
	void setStyle(sf::Uint32 style);
	/**
	 * \brief Sets the font of the Text inside the button
	 * \param font font 
	 */
	void setFont(sf::Font& font);
	
	/**
	 * \brief Gets the position the the button
	 * \return position
	 */
	sf::Vector2f getPostion();
	/**
	 * \brief Gets the dimensions of the button
	 * \return dimensions
	 */
	sf::Vector2f getDimensions();

	/**
	 * \brief Gets the current state of the button
	 * \return state
	 */
	sf::Uint32 getState();
	/**
	 * \brief Update the button using the events and render window
	 * \param event event 
	 * \param window window 
	 */
	void update(sf::Event& event, sf::RenderWindow& window);

	/**
	 * \brief Defines a the sprite for the button
	 */
	sf::Sprite createButton;

	/**
	 * \brief Gets the bounds of the button to check for mouse position
	 * \param window window 
	 * \param x x position 
	 * \param y y position 
	 * \param h height 
	 * \param w width 
	 * \return returns true if mouse is within bounds
	 */
	bool getBounds(sf::Window window, int x, int y, int h, int w);

private:

	/**
	 * \brief Defines a colour for the default text
	 */
	sf::Color textNormal;
	/**
	 * \brief Defines a colour for the text when hovered
	 */
	sf::Color textHover;
	/**
	 * \brief Defines a colour for the text when clicked
	 */
	sf::Color textClicked;
	/**
	 * \brief Defines a colour for the default button
	 */
	sf::Color buttonNormal;
	/**
	 * \brief Defines a colour for the button when hovered
	 */
	sf::Color buttonHover;
	/**
	 * \brief Defines a colour for the button when clicked
	 */
	sf::Color buttonClicked;
	/**
	 * \brief Defines a colour for the buttons border
	 */
	sf::Color buttonBorder;

	/**
	 * \brief Defines a float for the border thickness
	 */
	float borderThickness;
	/**
	 * \brief Defines a float for the border radius
	 */
	float borderRadius;

	/**
	 * \brief Defines a Vector for the size of the butotn
	 */
	sf::Vector2f size;
	/**
	 * \brief Defines a vector for the position of the button
	 */
	sf::Vector2f position;

	/**
	 * \brief Defines a Uint32 for the style of the button
	 */
	sf::Uint32 style;
	/**
	 * \brief Defines a Uint32 for the state of the button
	 */
	sf::Uint32 state;

	/**
	 * \brief Defines the shape of the button
	 */
	sf::ConvexShape button;

	/**
	 * \brief Defines a font for the text
	 */
	sf::Font font;

	/**
	 * \brief Defines a font size for the text
	 */
	unsigned int fontSize;

	/**
	 * \brief Defines the text inside the button
	 */
	sf::Text buttonText;
	/**
	 * \brief Defines a shadows for the text  
	 */
	std::string textShadow;

};

