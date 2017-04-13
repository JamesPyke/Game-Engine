#include "Game.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include <Box2D/Box2D.h>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"

Game::Game()
{
	window = nullptr;
	world = nullptr;
}

bool Game::initialize(sf::RenderWindow* window, b2World* world)
{
	this->window = window;
	this->world = world;

	txtrPlayer = resourceManager.getTexture("Player.png");

	objPlayer = GameObject(txtrPlayer, sf::Vector2f(0, 0));
	objPlayer.addPhysics(b2_dynamicBody, world);

	
	objMoveableBox = GameObject(txtrPlayer, sf::Vector2f(128.0f, window->getSize().y - (txtrPlayer.getSize().y * 2.0f)));
	objMoveableBox.addPhysics(b2_dynamicBody, world);

	boxes.push_back(&objMoveableBox);

	for(int i = 0; i < ((window->getSize().x - 128.0f) / txtrPlayer.getSize().x); ++i)
	{
		GameObject* box = new GameObject(txtrPlayer, sf::Vector2f(txtrPlayer.getSize().x * i, window->getSize().y - txtrPlayer.getSize().y));
		box->addPhysics(b2_staticBody, world);

		boxes.push_back(box);
	}

	return true;
}

bool Game::update(const float& deltaTime)
{
	world->Step(1 / 60.0f, 8, 3);

	b2Vec2 velocity = b2Vec2(0.0f, 0.0f);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= PLAYER_MOVEMENT_SPEED * deltaTime;
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += PLAYER_MOVEMENT_SPEED * deltaTime;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y -= playerJumpHeight * deltaTime;
		if(playerJumpHeight > 0)
			playerJumpHeight -= 0.01f;
		printf("Fuel: %f\n", playerJumpHeight);
	}

	b2Vec2 currentVelocity = objPlayer.getRigidbody()->GetLinearVelocity();
	objPlayer.getRigidbody()->SetLinearVelocity(b2Vec2(velocity.x, currentVelocity.y + velocity.y));

	for (b2Body* rigidbody = world->GetBodyList(); rigidbody != nullptr; rigidbody = rigidbody->GetNext())
	{
		GameObject* gameObject = static_cast<GameObject*>(rigidbody->GetUserData());

		if(gameObject != nullptr)
		{
			sf::Sprite* sprite = gameObject->getSprite();

			sprite->setPosition(sf::Vector2f(rigidbody->GetPosition().x * 30.0f, rigidbody->GetPosition().y * 30.0f));
			sprite->setRotation(rigidbody->GetAngle() * 180 / b2_pi);
		}

	}
	return true;
}

void Game::draw()
{
	window->clear(sf::Color::Black);

	for (auto& box : boxes)
		window->draw(*box->getSprite());
	window->draw(*objPlayer.getSprite());

	window->display();
}
