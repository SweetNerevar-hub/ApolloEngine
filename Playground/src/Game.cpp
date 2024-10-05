#include "pch.h"
#include "Game.h"

using namespace Apollo;
using namespace Apollo::ECS;
using namespace Apollo::Utils;

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
			createCircle(1000);
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

void Game::createCircle(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		float rx = Math::randomRange(-2.f, 2.f);
		float ry = Math::randomRange(-2.f, 2.f);

		Entity circle = IECS::createEntity("Circle");
		circle.add<CPosition>(350.f, 250.f);
		circle.add<CVelocity>(rx, ry);
		circle.add<CShape>(10.f, getRandomColour());
		circle.add<CMoveSpeed>(3.f);
	}

	std::cout << "Total Entities: " << IECS::getEntities().size() + amount << std::endl;
}

sf::Color Game::getRandomColour()
{
	int r = Math::randomRange(0, 7);
	switch (r)
	{
	case 0:
		return sf::Color::Black;

	case 1:
		return sf::Color::Blue;

	case 2:
		return sf::Color::Cyan;

	case 3:
		return sf::Color::Green;

	case 4:
		return sf::Color::Magenta;

	case 5:
		return sf::Color::Red;

	case 6:
		return sf::Color::White;

	case 7:
		return sf::Color::Yellow;
	}
}

Apollo::IGame* Apollo::createGame()
{
	return new Game();
}