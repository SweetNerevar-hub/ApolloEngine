#include "pch.h"
#include "ECSMemoryPool.h"

namespace Apollo::ECS
{
	ECSMemoryPool::ECSMemoryPool()
	{
		m_pool.reserve(32); // Change for some initial amount of components

		m_tags.resize(Global::Instance().maxEntities);
		m_active.resize(Global::Instance().maxEntities);
	}

	size_t ECSMemoryPool::createEntity(const std::string& tag)
	{
		size_t index = getFirstFreeIndex();

		m_tags[index] = tag;
		m_active[index] = true;
		m_totalEntities++;

		return index;
	}

	void ECSMemoryPool::destroyEntity(size_t entityID)
	{
		for (const auto& [typeIndex, componentArray] : getComponentPool())
		{
			auto* arr = dynamic_cast<ComponentArrayBase*>(componentArray.get());
			arr->removeEntity(entityID);
		}

		m_active[entityID] = false;
		m_totalEntities--;
	}

	const std::string& ECSMemoryPool::getTag(size_t entityID) const
	{
		return m_tags[entityID];
	}

	size_t ECSMemoryPool::getFirstFreeIndex()
	{
		for (int i = 0; i < m_active.size(); i++)
		{
			if (m_active[i] == false)
			{
				return i;
			}
		}

		return -1;
	}

	const ComponentPool& ECSMemoryPool::getComponentPool() const
	{
		return m_pool;
	}
}