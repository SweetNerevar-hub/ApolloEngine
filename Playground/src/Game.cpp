#include "Game.h"

void Game::init()
{
	shape.setRadius(100.f);
	shape.setFillColor(sf::Color::Blue);
	shape.setOrigin(shape.getGlobalBounds().width / 2.f, shape.getGlobalBounds().height / 2.f);
	shape.setPosition(400, 300);
}

void Game::handleEvents(sf::Event& event)
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
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color::Red);
	rect.setSize(sf::Vector2f{100.f, 100.f});
	rect.setPosition(100.f, 100.f);

	window.draw(rect);
	window.draw(shape);
}

Apollo::IGame* Apollo::createGame()
{
	return new Game();
}