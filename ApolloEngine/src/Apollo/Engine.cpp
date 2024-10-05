#include "pch.h"
#include "Engine.h"

namespace Apollo
{
    Engine::Engine(IGame* game) : m_game(game)
    {
        // Set a random seed
        srand(time(0));
    }

	void Engine::run()
	{
        m_isRunning = true;

        // Abstract out the window functionality
        m_window->setFramerateLimit(60);

        m_game->init();

        // Game Loop
        while (m_isRunning)
        {
            sf::Clock frameTime;

            IECS::updateEntityList();
            handleEvents();
            update();
            render();
            m_currentFrame++;

            if (m_currentFrame % 60 == 0)
            {
                printf("FPS: %f\n", 1 / frameTime.getElapsedTime().asSeconds());
            }
        }

        m_window->close();
	}

    void Engine::handleEvents()
    {
        sf::Event m_event;
        while (m_window->pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Closed)
            {
                shutdown();
            }

            m_game->handleEvents(m_event);
        }
    }

    void Engine::update()
    {
        m_game->update();
    }

    void Engine::render()
    {
        m_window->clear();

        m_game->render(*m_window);

        m_window->display();
    }

    void Engine::shutdown()
    {
        m_isRunning = false;
    }
}