#pragma once
#include <Box2D/Dynamics/b2Body.h>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace sf {
	class Texture;
}

class GameObject
{

public:
	
	/**
	 * \brief Default constructor
	 */
	GameObject();
	/**
	 * \brief Constructor
	 * \param texture texture
	 * \param position position
	 */
	GameObject(sf::Texture& texture, const sf::Vector2f& position);

	/**
	 * \brief Add Physics to an object using the body type and set rotation
	 * \param bodyType body type
	 * \param world world
	 * \param hasRotation has rotation 
	 */
	void addPhysics(const b2BodyType& bodyType, b2World* world, bool hasRotation);
	/**
	 * \brief Deconstructor for the Physics
	 */
	void removePhysics() const;

	/**
	 * \brief Points to a rigidbody
	 * \return Rigidbody
	 */
	b2Body* getRigidbody();
	/**
	 * \brief Points to a sprite
	 * \return sprite
	 */
	sf::Sprite* getSprite();

private:

	/**
	 * \brief Sets the sprite
	 */
	sf::Sprite sprite;
	/**
	 * \brief Sets the rigidbody
	 */
	b2Body* rigidbody;
	/**
	 * \brief Sets the world
	 */
	b2World* world;

};

