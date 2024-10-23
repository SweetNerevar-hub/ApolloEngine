#pragma once

#include "Interfaces/IGame.h"
#include "Interfaces/ApolloECS.h"

#include "Window.h"
#include "GameEventManager.h"

namespace Apollo
{
	class APOLLO_API Engine
	{
	public:
		void run();
		void handleInput();
		void update();
		void render();

		Engine(IGame* game);
		~Engine()
		{
			std::cout << "Goodbye!" << std::endl;
		}

	private:
		IGame* m_game = nullptr;

		Window* m_window = new Window(800, 600, "Apollo::Playground", 60, false);

		Event::GameEventManager m_gameEventManager;

		int m_currentFrame = 0;
		bool m_isRunning = false;

		void shutdown();
	};
}