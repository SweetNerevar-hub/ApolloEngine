#pragma once

#include <cassert>

#include "Entity.h"

namespace Apollo::ECS
{
	struct Prefab
	{
		std::string prefabName;
		Entity prefabEntity;
		std::vector<Component*> prefabComponents;
	};

	class PrefabManager
	{
	public:
		void createPrefab(Entity archetype, const std::string& name);
		Entity instaniate(const std::string& name);

	private:
		std::unordered_map<std::string, Prefab> m_prefabs;
	};
}