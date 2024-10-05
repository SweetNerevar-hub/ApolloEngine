#include "pch.h"
#include "EntityManager.h"

namespace Apollo::ECS
{
	void EntityManager::update()
	{
		for (auto& e : m_addNextFrame)
		{
			entities.push_back(e);
		}

		m_addNextFrame.clear();
	}

	Entity EntityManager::create(const std::string& tag)
	{
		size_t index = ECSMemoryPool::Instance().createEntity(tag);
		Entity e = Entity(index);

		m_addNextFrame.push_back(e);

		return e;
	}

	void EntityManager::clear()
	{
		for (Entity& e : entities)
		{
			e.destroy();
		}

		entities.clear();
	}

	Entity EntityManager::getEntityByTag(const std::string& tag)
	{
		for (Entity& e : entities)
		{
			if (e.getTag() == tag)
			{
				return e;
			}
		}

		return Entity();
	}

	std::vector<Entity> EntityManager::getEntitiesByTag(const std::string& tag)
	{
		std::vector<Entity> entitiesWithTag;

		for (Entity& e : entities)
		{
			if (e.getTag() == tag)
			{
				entitiesWithTag.push_back(e);
			}
		}

		return entitiesWithTag;
	}
}