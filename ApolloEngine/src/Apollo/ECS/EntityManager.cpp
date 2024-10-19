#include "pch.h"
#include "EntityManager.h"

namespace Apollo::ECS
{
	void EntityManager::init()
	{
		entities.reserve(Global::Instance().maxEntities);
	}

	void EntityManager::update()
	{
		for (auto& e : m_addNextFrame)
		{
			entities.push_back(e);
		}

		m_addNextFrame.clear();
	}

	void EntityManager::remove()
	{
		if (m_toRemove.empty()) return;

		sf::Clock removeTime;

		std::sort(m_toRemove.begin(), m_toRemove.end());
		m_toRemove.erase(std::unique(m_toRemove.begin(), m_toRemove.end()), m_toRemove.end());

		entities.erase(std::remove_if(entities.begin(), entities.end(), [this](const Entity& e)
		{
			return std::binary_search(m_toRemove.begin(), m_toRemove.end(), e.id);
		}), entities.end());

		for (size_t id : m_toRemove)
		{
			ECSMemoryPool::Instance().destroyEntity(id);
		}
		
		m_toRemove.clear();

		std::cout << "Remove Time: " << removeTime.getElapsedTime().asMicroseconds() << std::endl;
	}

	Entity EntityManager::create(const std::string& tag)
	{
		size_t index = ECSMemoryPool::Instance().createEntity(tag);
		Entity e = Entity(index);

		m_addNextFrame.emplace_back(e);

		return e;
	}

	void EntityManager::destroy(Entity entity)
	{
		m_toRemove.emplace_back(entity.id);
	}

	void EntityManager::clear()
	{
		for (Entity& e : entities)
		{
			destroy(e);
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