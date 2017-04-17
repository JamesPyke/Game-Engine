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

	fntFuel.loadFromFile("Orkney-Regular.otf");
	

	txtFuel.setFont(fntFuel);
	txtFuel.setString("Fuel: " + std::to_string(playerJumpHeight) + " litres");

	txtrPlayer = resourceManager.getTexture("player.fw.png");
	txtrBlockSingle = resourceManager.getTexture("FloorSingle.fw.png");
	txtrBlockDouble = resourceManager.getTexture("FloorDouble.fw.png");
	txtrBlockGround = resourceManager.getTexture("Ground.fw.png");
	txtrMovable = resourceManager.getTexture("MovableBlock.fw.png");
	txtrTop = resourceManager.getTexture("Top.fw.png");
	txtrEdge = resourceManager.getTexture("Edge.fw.png");
	txtrBackGround = resourceManager.getTexture("background.fw.png");

	objPlayer = GameObject(txtrPlayer, sf::Vector2f(0, 500));
	objPlayer.getSprite()->setOrigin(sf::Vector2f((txtrPlayer.getSize().x / 2.0f - 32), txtrPlayer.getSize().y / 2.0f - 32));
	objPlayer.addPhysics(b2_dynamicBody, world, false);

	//Static Blocks

	objSingle = GameObject(txtrBlockSingle, sf::Vector2f(371, 150));
	objSingle.addPhysics(b2_staticBody, world, false);

	objSingle2 = GameObject(txtrBlockSingle, sf::Vector2f(250, 300));
	objSingle2.addPhysics(b2_staticBody, world, false);

	objSingle3 = GameObject(txtrBlockSingle, sf::Vector2f(1000, 100));
	objSingle3.addPhysics(b2_staticBody, world, false);

	objSingle4 = GameObject(txtrBlockSingle, sf::Vector2f(950, 300));
	objSingle4.addPhysics(b2_staticBody, world, false);

	objSingle5 = GameObject(txtrBlockSingle, sf::Vector2f(300, 450));
	objSingle5.addPhysics(b2_staticBody, world, false);

	objDouble = GameObject(txtrBlockDouble, sf::Vector2f(552, 311));
	objDouble.getSprite()->setOrigin(sf::Vector2f((txtrBlockDouble.getSize().x / 4.0f), 0.0f));
	objDouble.addPhysics(b2_staticBody, world, false);

	objDouble2 = GameObject(txtrBlockDouble, sf::Vector2f(window->getSize().x - 96, 500));
	objDouble2.getSprite()->setOrigin(sf::Vector2f((txtrBlockDouble.getSize().x / 4.0f), 0.0f));
	objDouble2.addPhysics(b2_staticBody, world, false);

	objDouble3 = GameObject(txtrBlockDouble, sf::Vector2f(32, 200));
	objDouble3.getSprite()->setOrigin(sf::Vector2f((txtrBlockDouble.getSize().x / 4.0f), 0.0f));
	objDouble3.addPhysics(b2_staticBody, world, false);

	objDouble4 = GameObject(txtrBlockDouble, sf::Vector2f(700, 100));
	objDouble4.getSprite()->setOrigin(sf::Vector2f((txtrBlockDouble.getSize().x / 4.0f), 0.0f));
	objDouble4.addPhysics(b2_staticBody, world, false);

	objDouble5 = GameObject(txtrBlockDouble, sf::Vector2f(800, 411));
	objDouble5.getSprite()->setOrigin(sf::Vector2f((txtrBlockDouble.getSize().x / 4.0f), 0.0f));
	objDouble5.addPhysics(b2_staticBody, world, false);

	objGround = GameObject(txtrBlockGround, sf::Vector2f(500,  700 - txtrBlockGround.getSize().y/2));
	objGround.getSprite()->setOrigin(sf::Vector2f(((txtrBlockGround.getSize().x / 2.0f) - 32), 0.0f));
	objGround.addPhysics(b2_staticBody, world, false);

	objTop = GameObject(txtrTop, sf::Vector2f(608, -64));
	objTop.getSprite()->setOrigin(sf::Vector2f(((txtrTop.getSize().x / 2.0f) - 32), 0.0f));
	objTop.addPhysics(b2_staticBody, world, false);

	objLeft = GameObject(txtrEdge, sf::Vector2f(-64, 0));
	objLeft.getSprite()->setOrigin(sf::Vector2f(((txtrEdge.getSize().x / 2.0f) - 32), 0.0f));
	objLeft.addPhysics(b2_staticBody, world, false);

	objRight = GameObject(txtrEdge, sf::Vector2f(window->getSize().x, 0));
	objRight.getSprite()->setOrigin(sf::Vector2f(txtrEdge.getSize().x / 2.0f - 32, 0.0f));
	objRight.addPhysics(b2_staticBody, world, false);

	objBackGround = GameObject(txtrBackGround, sf::Vector2f(0, 0));

	//Dynamics 

	objMoveableBox1 = GameObject(txtrMovable, sf::Vector2f(371, 86));
	objMoveableBox1.getSprite()->setOrigin(sf::Vector2f(txtrMovable.getSize().x /2 - 32.0f, txtrMovable.getSize().y /2 - 32.0f));
	objMoveableBox1.addPhysics(b2_dynamicBody, world, true);

	objMoveableBox2 = GameObject(txtrMovable, sf::Vector2f(371, 54));
	objMoveableBox2.getSprite()->setOrigin(sf::Vector2f(txtrMovable.getSize().x / 2 - 32.0f, txtrMovable.getSize().y / 2 - 32.0f));
	objMoveableBox2.addPhysics(b2_dynamicBody, world, true);

	objMoveableBox3 = GameObject(txtrMovable, sf::Vector2f(700, 68));
	objMoveableBox3.getSprite()->setOrigin(sf::Vector2f(txtrMovable.getSize().x / 2 - 32.0f, txtrMovable.getSize().y / 2 - 32.0f));
	objMoveableBox3.addPhysics(b2_dynamicBody, world, true);

	objMoveableBox4 = GameObject(txtrMovable, sf::Vector2f(1000, 68));
	objMoveableBox4.getSprite()->setOrigin(sf::Vector2f(txtrMovable.getSize().x / 2 - 32.0f, txtrMovable.getSize().y / 2 - 32.0f));
	objMoveableBox4.addPhysics(b2_dynamicBody, world, true);

	objMoveableBox5 = GameObject(txtrMovable, sf::Vector2f(500, 200));
	objMoveableBox5.getSprite()->setOrigin(sf::Vector2f(txtrMovable.getSize().x / 2 - 32.0f, txtrMovable.getSize().y / 2 - 32.0f));
	objMoveableBox5.addPhysics(b2_dynamicBody, world, true);

	objMoveableBox6 = GameObject(txtrMovable, sf::Vector2f(300, 200));
	objMoveableBox6.getSprite()->setOrigin(sf::Vector2f(txtrMovable.getSize().x / 2 - 32.0f, txtrMovable.getSize().y / 2 - 32.0f));
	objMoveableBox6.addPhysics(b2_dynamicBody, world, true);

	objMoveableBox7 = GameObject(txtrMovable, sf::Vector2f(50, 18));
	objMoveableBox7.getSprite()->setOrigin(sf::Vector2f(txtrMovable.getSize().x / 2 - 32.0f, txtrMovable.getSize().y / 2 - 32.0f));
	objMoveableBox7.addPhysics(b2_dynamicBody, world, true);

	objMoveableBox8 = GameObject(txtrMovable, sf::Vector2f(400, 200));
	objMoveableBox8.getSprite()->setOrigin(sf::Vector2f(txtrMovable.getSize().x / 2 - 32.0f, txtrMovable.getSize().y / 2 - 32.0f));
	objMoveableBox8.addPhysics(b2_dynamicBody, world, true);

	objMoveableBox9 = GameObject(txtrMovable, sf::Vector2f(250, 300));
	objMoveableBox9.getSprite()->setOrigin(sf::Vector2f(txtrMovable.getSize().x / 2 - 32.0f, txtrMovable.getSize().y / 2 - 32.0f));
	objMoveableBox9.addPhysics(b2_dynamicBody, world, true);

	objMoveableBox10 = GameObject(txtrMovable, sf::Vector2f(800, 200));
	objMoveableBox10.getSprite()->setOrigin(sf::Vector2f(txtrMovable.getSize().x / 2 - 32.0f, txtrMovable.getSize().y / 2 - 32.0f));
	objMoveableBox10.addPhysics(b2_dynamicBody, world, true);

	objMoveableBox11 = GameObject(txtrMovable, sf::Vector2f(1000, 100));
	objMoveableBox11.getSprite()->setOrigin(sf::Vector2f(txtrMovable.getSize().x / 2 - 32.0f, txtrMovable.getSize().y / 2 - 32.0f));
	objMoveableBox11.addPhysics(b2_dynamicBody, world, true);


	boxes.push_back(&objMoveableBox1);

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
		txtFuel.setString("Fuel: " + std::to_string(playerJumpHeight) + " litres");
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
	window->draw(*objBackGround.getSprite());

	for (auto& box : boxes)
		window->draw(*box->getSprite());

	window->draw(*objMoveableBox1.getSprite());
	window->draw(*objMoveableBox2.getSprite());
	window->draw(*objMoveableBox3.getSprite());
	window->draw(*objMoveableBox4.getSprite());
	window->draw(*objMoveableBox5.getSprite());
	window->draw(*objMoveableBox6.getSprite());
	window->draw(*objMoveableBox7.getSprite());
	window->draw(*objMoveableBox8.getSprite());
	window->draw(*objMoveableBox9.getSprite());
	window->draw(*objMoveableBox10.getSprite());
	window->draw(*objMoveableBox11.getSprite());


	window->draw(*objPlayer.getSprite());
	window->draw(*objGround.getSprite());

	window->draw(*objSingle.getSprite());
	window->draw(*objSingle2.getSprite());
	window->draw(*objSingle3.getSprite());
	window->draw(*objSingle4.getSprite());
	window->draw(*objSingle5.getSprite());

	window->draw(*objDouble.getSprite());
	window->draw(*objDouble2.getSprite());
	window->draw(*objDouble3.getSprite());	
	window->draw(*objDouble4.getSprite());
	window->draw(*objDouble5.getSprite());

	window->draw(*objTop.getSprite());
	window->draw(*objLeft.getSprite());
	window->draw(*objRight.getSprite());

	window->draw(txtFuel);
	window->display();
}
