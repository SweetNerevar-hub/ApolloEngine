#pragma once

#include "pch.h"

namespace Apollo 
{
	class IGame
	{
	public:
		virtual ~IGame() = default;

		virtual void init() = 0;
		virtual void handleEvents(sf::Event& event) = 0;
		virtual void update() = 0;
		virtual void render(sf::RenderWindow& window) = 0;
	};

	IGame* createGame();
}