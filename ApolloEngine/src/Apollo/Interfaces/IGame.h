#pragma once

#include "pch.h"

namespace Apollo 
{
	class IGame
	{
	public:
		IGame(size_t entityArraySize) : maxEntities(entityArraySize)
		{
			Global::Instance().maxEntities = entityArraySize;
		}

		virtual ~IGame() = default;

		virtual void init() = 0;
		virtual void handleInput(sf::Event& event) = 0;
		virtual void update() = 0;
		virtual void render(sf::RenderWindow& window) = 0;

		size_t maxEntities;
	};

	IGame* createGame();
}

