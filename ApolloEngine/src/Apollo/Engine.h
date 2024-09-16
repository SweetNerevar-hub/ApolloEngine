#pragma once

#include <iostream>

#include "Export.h"
#include "IGame.h"

namespace Apollo
{
	class APOLLO_API Engine
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
		sf::RenderWindow* m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Apollo");

		IGame* m_game = nullptr;
		
		bool m_isRunning = false;

		void shutdown();
	};
}