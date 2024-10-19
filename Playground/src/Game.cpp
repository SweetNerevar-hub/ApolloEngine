#include "pch.h"
#include "Game.h"

void Game::init()
{
	ApolloECS::registerSystem<SMovement>();
	ApolloECS::registerSystem<SCollision>();

	ApolloECS::registerComponent<Position>();
	ApolloECS::registerComponent<Velocity>();
	ApolloECS::registerComponent<Shape>();
	ApolloECS::registerComponent<MoveSpeed>();

	if (m_usePrefab)
	{
		Entity	circlePrefab = ApolloECS::createEntity("Circle");
				circlePrefab.add<Position>(350.f, 250.f);
				circlePrefab.add<Shape>(10.f, getRandomColour());
				circlePrefab.add<MoveSpeed>(3.f);
				circlePrefab.add<Velocity>(1.f, 1.f);

		ApolloECS::createPrefab(circlePrefab, "CirclePrefab");
		ApolloECS::destroyEntity(circlePrefab);
	}
}

void Game::handleInput(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			createCircle(100);
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		{
			t = true;
		}

		break;
	}
}

void Game::update()
{
	if (t)
	{
		size_t r = Math::randomRange(0, ApolloECS::getEntities().size() - 1);
		ApolloECS::destroyEntity(ApolloECS::getEntities().at(r));
	}

	ApolloECS::updateSystems();

	for (Entity& e : ApolloECS::getEntities())
	{
		if (e.has<Shape>())
		{
			e.get<Shape>().shape.setPosition(e.get<Position>().x, e.get<Position>().y);
		}
	}
}

void Game::render(sf::RenderWindow& window)
{
	for (Entity& e : ApolloECS::getEntities())
	{
		if (e.has<Shape>())
		{
			window.draw(e.get<Shape>().shape);
		}
	}
}

void Game::createCircle(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		float rx = Math::randomRange(-2.f, 2.f);
		float ry = Math::randomRange(-2.f, 2.f);

		if (m_usePrefab)
		{
			Entity newCircle = ApolloECS::instantiate("CirclePrefab");
			newCircle.add<Velocity>(rx, ry);
		}

		else
		{
			Entity circle = ApolloECS::createEntity("Circle");
			circle.add<Position>(350.f, 250.f);
			circle.add<Shape>(10.f, getRandomColour());
			circle.add<MoveSpeed>(3.f);
			circle.add<Velocity>(rx, ry);
		}
	}

	std::cout << "Total Entities: " << ApolloECS::getEntities().size() + amount << std::endl;
}

sf::Color Game::getRandomColour()
{
	int r = Math::randomRange(0, 6);
	switch (r)
	{
	case 0:
		return sf::Color::Yellow;

	case 1:
		// Events Testing
		GameEventManager::publish(std::make_unique<OnCircleSpawn>(sf::Color::Blue));
		return sf::Color::Blue;

	case 2:
		return sf::Color::Cyan;

	case 3:
		return sf::Color::Green;

	case 4:
		return sf::Color::Magenta;

	case 5:
		// Events Testing
		GameEventManager::publish(std::make_unique<OnCircleSpawn>(sf::Color::Red));
		return sf::Color::Red;

	default:
		return sf::Color::White;
	}
}

Apollo::IGame* Apollo::createGame()
{
	return new Game(1024);
}