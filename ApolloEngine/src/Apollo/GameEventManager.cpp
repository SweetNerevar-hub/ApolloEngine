#include "pch.h"
#include "GameEventManager.h"

namespace Apollo::Event
{
	void GameEventManager::processEvents()
	{
		while (!m_gameEvents.empty())
		{
			m_gameEvents.front()->process();
			m_gameEvents.pop();
		}
	}

	void GameEventManager::publish(std::unique_ptr<GameEvent> event)
	{
		m_gameEvents.push(std::move(event));
	}
}