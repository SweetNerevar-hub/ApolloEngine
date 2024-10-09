#pragma once

#include "Export.h"
#include "Event.h"

namespace Apollo::Event
{
	class APOLLO_API GameEventManager
	{
	public:
		void processEvents();
		static void publish(std::unique_ptr<GameEvent> gameEvent);

	private:
		inline static std::queue<std::unique_ptr<GameEvent>> m_gameEvents;
	};
}