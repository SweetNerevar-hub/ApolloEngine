#pragma once

#include "System.h"

namespace Apollo::ECS
{
	class SystemsManager
	{
	public:
		void updateSystems(Entities& entities);

		template<typename T>
		void registerSystem()
		{
			m_systems.emplace_back(std::make_unique<T>());
		}

	private:
		std::vector<std::unique_ptr<System>> m_systems;
	};
}