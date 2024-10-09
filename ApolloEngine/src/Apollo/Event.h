#pragma once

namespace Apollo::Event
{
	class GameEvent
	{
	public:
		virtual ~GameEvent() = default;

		virtual void process() = 0;
	};
}