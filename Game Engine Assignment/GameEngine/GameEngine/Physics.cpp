#include "Physics.h"

std::vector<b2Body*> Physics::physicsBodies;

Physics::Physics(b2World world, float x, float y, float width, float height)
{
	sprite.setOrigin(width / 2.0f, height / 2.0f);

	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(x / 30.0f, y / 30.0f);
	bodyDef.type = b2_staticBody;
	body = world.CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox((width / 2)/30.0f, (height / 2) / 30.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.density = 0.0f;
	fixtureDef.shape = &shape;
	body->CreateFixture(&fixtureDef);

	physicsBodies.push_back(body);
}

Physics::Physics()
{
}

sf::Vector2f Physics::getPosition(float x, float y)
{
	x = x / 30.f;
	y = y / 30.f;

	return position;
}

