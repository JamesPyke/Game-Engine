#include "GameObject.h"
#include "SFML/Graphics/Sprite.hpp"
#include "Box2D/Box2D.h"

GameObject::GameObject()
{
	rigidbody = nullptr;
	world = nullptr;
}

GameObject::GameObject(sf::Texture& texture, const sf::Vector2f& position)
{
	sprite = sf::Sprite(texture);
	sprite.setPosition(position);
}

void GameObject::addPhysics(const b2BodyType& bodyType, b2World* world)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(sprite.getPosition().x / 30.f, sprite.getPosition().y / 30.f);
	BodyDef.type = bodyType;
	BodyDef.userData = this;
	rigidbody = world->CreateBody(&BodyDef);
	

	b2PolygonShape Shape;

	float spriteWidth = sprite.getGlobalBounds().width;
	float spriteHeight = sprite.getGlobalBounds().height;

	Shape.SetAsBox(spriteWidth / 2.0f / 30.0f, spriteHeight / 2.0f / 30.f); 

	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;  
	FixtureDef.shape = &Shape; 
	rigidbody->CreateFixture(&FixtureDef);
}

void GameObject::removePhysics() const
{
	if(rigidbody != nullptr && world != nullptr)
	{
		world->DestroyBody(rigidbody);
	}
}

b2Body* GameObject::getRigidbody()
{
	return rigidbody;
}

sf::Sprite* GameObject::getSprite()
{
	return &sprite;
}
