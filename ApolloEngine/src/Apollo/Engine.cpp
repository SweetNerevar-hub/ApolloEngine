#include "Engine.h"

namespace Apollo
{
    Engine::Engine(IGame* game) : m_game(game) {}

	void Engine::run()
	{
        m_isRunning = true;

        // Abstract out the window functionality
        m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Apollo");
        m_window->setFramerateLimit(60);

        m_game->init();

        // Game Loop
        while (m_isRunning)
        {
            handleEvents();
            update();
            render();
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

            else if (m_event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    shutdown();
                }
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