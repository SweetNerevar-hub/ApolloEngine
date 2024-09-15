#include "Game.h"

void Game::init()
{
	shape.setRadius(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.setOrigin(shape.getGlobalBounds().width / 2.f, shape.getGlobalBounds().height / 2.f);
	shape.setPosition(400, 300);
}

void Game::handleEvents(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			std::cout << "Key Input!" << std::endl;
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
	window.draw(shape);
}

Apollo::IGame* Apollo::createGame()
{
	return new Game();
}