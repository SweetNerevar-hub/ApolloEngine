#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "IGame.h"

namespace Apollo
{
	class Engine
	{
	public:
		Engine(IGame* game);
		~Engine()
		{
			std::cout << "Goodbye!" << std::endl;
		}

		void run();
		void handleEvents();
		void update();
		void render();

	private:
		sf::RenderWindow* m_window = nullptr;

		IGame* m_game = nullptr;
		
		bool m_isRunning = false;

		void shutdown();
	};
}