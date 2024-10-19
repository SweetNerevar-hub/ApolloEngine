#include "pch.h"
#include "SystemsManager.h"

namespace Apollo::ECS
{
	void SystemsManager::updateSystems(Entities& entities)
	{
		for (auto& system : m_systems)
		{
			system->update(entities);
		}
	}
}