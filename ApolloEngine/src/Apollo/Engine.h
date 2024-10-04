#pragma once

#include "IGame.h"
#include "IECS.h"

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
		IGame* m_game = nullptr;

		sf::RenderWindow* m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Apollo");

		bool m_isRunning = false;

		void shutdown();
	};
}