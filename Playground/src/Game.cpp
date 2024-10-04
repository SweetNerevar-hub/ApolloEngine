#include "Game.h"

using namespace Apollo;
using namespace Apollo::ECS;

void Game::init()
{
	
}

void Game::handleEvents(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			std::cout << "Key Input!" << std::endl;
			createCircle();
		}
		break;
	}
}

void Game::update()
{
	std::cout << "Updating!" << std::endl;
}

void Game::render(sf::RenderWindow& window)
{
	for (CShape& circle : m_circles)
	{
		window.draw(circle.shape);
	}
}

void Game::createCircle()
{
	Entity circle = IECS::createEntity("Circle");
	circle.add<CPosition>();
	circle.add<CVelocity>();
	circle.add<CShape>();
	circle.add<CMoveSpeed>();

	CShape& shape = circle.get<CShape>();
	shape.shape.setRadius(20.f);
	shape.shape.setFillColor(sf::Color::Green);

	m_circles.emplace_back(circle);
}

Apollo::IGame* Apollo::createGame()
{
	return new Game();
}