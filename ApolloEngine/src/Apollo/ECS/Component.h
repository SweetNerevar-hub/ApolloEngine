#pragma once

namespace Apollo::ECS
{
	class Component
	{
	public:
		virtual ~Component() = default;

		bool active = false;
	};
}