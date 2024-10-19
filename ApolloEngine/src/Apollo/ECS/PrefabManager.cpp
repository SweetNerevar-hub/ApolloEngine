#include "pch.h"
#include "PrefabManager.h"
#include "../Interfaces/ApolloECS.h"

namespace Apollo::ECS
{
	void PrefabManager::createPrefab(Entity archetype, const std::string& name)
	{
		Prefab p;
		p.prefabName = name;
		p.prefabEntity = archetype;

		for (const auto& [typeIndex, componentArray] : ECSMemoryPool::Instance().getComponentPool())
		{
			auto* arr = dynamic_cast<ComponentArrayBase*>(componentArray.get());
			arr->copyToPrefab(p.prefabComponents, archetype.id);
		}

		m_prefabs.emplace(name, p);
	}

	Entity PrefabManager::instaniate(const std::string& name)
	{
		// TODO: Create custom assertion with flexible messaging
		// assert((itr != m_prefabs.end() && "Couldn't find prefab by name: "));
		auto itr = m_prefabs.find(name);
		if (itr == m_prefabs.end())
		{
			std::cerr << "Couldn't find prefab by name: " + name << std::endl;
			return Entity(-1);
		}

		Prefab p = m_prefabs[name];
		Entity newEntity = ApolloECS::createEntity(p.prefabEntity.getTag());

		for (const auto& [typeIndex, componentArray] : ECSMemoryPool::Instance().getComponentPool())
		{
			auto* arr = dynamic_cast<ComponentArrayBase*>(componentArray.get());
			arr->copyToEntity(p.prefabComponents, newEntity.id);
		}

		return newEntity;
	}
}