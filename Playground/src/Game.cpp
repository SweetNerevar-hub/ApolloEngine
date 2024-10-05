#include "pch.h"
#include "Game.h"

using namespace Apollo;
using namespace Apollo::ECS;

void Game::init()
{
	IECS::registerSystem(std::make_unique<SCollision>());
	IECS::registerSystem(std::make_unique<SMovement>());
}

void Game::handleEvents(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			createCircle();
		}
		break;
	}
}

void Game::update()
{
	//std::cout << "Updating!" << std::endl;

	IECS::updateSystems();

	for (Entity& e : IECS::getEntities())
	{
		if (e.has<CShape>())
		{
			e.get<CShape>().shape.setPosition(e.get<CPosition>().position);
		}
	}
}

void Game::render(sf::RenderWindow& window)
{
	for (Entity& e : IECS::getEntities())
	{
		if (e.has<CShape>())
		{
			window.draw(e.get<CShape>().shape);
		}
	}
}

void Game::createCircle()
{
	Entity circle = IECS::createEntity("Circle");
	circle.add<CPosition>(400.f, 300.f);
	circle.add<CVelocity>(1.f, 1.f);
	circle.add<CShape>(10.f, sf::Color::Green);
	circle.add<CMoveSpeed>(3.f);
}

Apollo::IGame* Apollo::createGame()
{
	return new Game();
}