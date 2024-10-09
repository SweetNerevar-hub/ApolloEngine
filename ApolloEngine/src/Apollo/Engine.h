#pragma once

#include "Interfaces/IGame.h"
#include "Interfaces/IECS.h"

#include "GameEventManager.h"

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
		void handleInput();
		void update();
		void render();

	private:
		IGame* m_game = nullptr;

		sf::RenderWindow* m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Apollo");
		Event::GameEventManager m_gameEventManager;

		int m_currentFrame = 0;
		bool m_isRunning = false;

		void shutdown();
	};
}