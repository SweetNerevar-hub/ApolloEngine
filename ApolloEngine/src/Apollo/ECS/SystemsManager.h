#pragma once

#include "Systems.h"

namespace Apollo::ECS
{
	class SystemsManager
	{
	public:
		void updateSystems(Entities& e);
		void registerSystem(std::unique_ptr<System> system);

	private:
		std::vector<std::unique_ptr<System>> m_systems;
	};
}