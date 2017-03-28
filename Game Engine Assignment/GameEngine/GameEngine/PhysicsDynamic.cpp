#include "PhysicsDynamic.h"


PhysicsDynamic::PhysicsDynamic(b2World world, float x, float y, float width, float height)
{
	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(x / 30.f, y / 30.0f);
	bodyDef.type = b2_dynamicBody;
	body = world.CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox((width / 2) / 30.0f, (height / 2) / 30.0f);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &shape;
	body->CreateFixture(&FixtureDef);
	physicsBodies.push_back(body);
}

/*
void PhysicsDynamic::createCircle(b2World& world, int mouseX, int mouseY, float radius)
{
	float32 m_radius = radius;
	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(mouseX / 30.f, mouseY / 30.0f);
	bodyDef.type = b2_dynamicBody;
	b2Body* Body = world.CreateBody(&bodyDef);

	b2CircleShape circle;
	circle.m_p.Set(0, 0);
	circle.m_radius = m_radius;
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circle;
	fixtureDef.density = 1;
	Body->CreateFixture(&fixtureDef);

	b2Vec2 m_position;
	float m_angle;
	b2Vec2 m_linearVelocity;
	physicsBodies.push_back(Body);
}*/
