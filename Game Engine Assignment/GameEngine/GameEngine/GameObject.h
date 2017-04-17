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
	
	GameObject();
	GameObject(sf::Texture& texture, const sf::Vector2f& position);

	void addPhysics(const b2BodyType& bodyType, b2World* world, bool hasRotation);
	void removePhysics() const;

	b2Body* getRigidbody();
	sf::Sprite* getSprite();

private:

	sf::Sprite sprite;
	b2Body* rigidbody;
	b2World* world;

};

