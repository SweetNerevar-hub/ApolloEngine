#include "pch.h"
#include "Engine.h"

namespace Apollo
{
    Engine::Engine(IGame* game) : m_game(game) {}

	void Engine::run()
	{
        m_isRunning = true;

        // Abstract out the window functionality
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

        sf::CircleShape shape;
        shape.setRadius(100.f);
        shape.setFillColor(sf::Color::Green);

        //m_window->draw(shape);
        m_game->render(*m_window);

        m_window->display();
    }

    void Engine::shutdown()
    {
        m_isRunning = false;
    }
}