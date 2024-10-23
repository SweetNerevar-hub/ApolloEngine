#include "pch.h"
#include "Engine.h"

namespace Apollo
{
    Engine::Engine(IGame* game) : m_game(game)
    {
        // Set a random seed
        srand(time(0));

        m_isRunning = true;

        m_window->useVSync(true);

        Global::Instance().maxEntities = game->maxEntities;
        ApolloECS::initialise();
    }

	void Engine::run()
	{
        m_game->init();

        // Game Loop
        while (m_isRunning)
        {
            sf::Clock frameTime;

            m_gameEventManager.processEvents();
            ApolloECS::updateEntityList();
            handleInput();
            update();
            render();

            ApolloECS::removeDeadEntities();

            m_currentFrame++;

            if (m_currentFrame % 60 == 0)
            {
                //printf("FPS: %f\n", 1 / frameTime.getElapsedTime().asSeconds());
            }
        }

        m_window->close();
	}

    void Engine::handleInput()
    {
        sf::Event m_event;
        while (m_window->window()->pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Resized)
            {
                m_window->setWindowSize(m_event.size.width, m_event.size.height);
            }

            if (m_event.type == sf::Event::Closed)
            {
                shutdown();
            }

            m_game->handleInput(m_event);
        }
    }

    void Engine::update()
    {
        m_game->update();
    }

    void Engine::render()
    {
        m_window->window()->clear();

        m_game->render(*m_window->window());

        m_window->window()->display();
    }

    void Engine::shutdown()
    {
        m_isRunning = false;
    }
}