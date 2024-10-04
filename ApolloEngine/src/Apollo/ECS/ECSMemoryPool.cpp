#include "pch.h"
#include "ECSMemoryPool.h"

namespace Apollo::ECS
{
	ECSMemoryPool::ECSMemoryPool(size_t maxEntities)
	{
		fillComponentVectors(m_pool, maxEntities, std::make_index_sequence<std::tuple_size<decltype(m_pool)>::value>{});
		m_tags.resize(maxEntities);
		m_active.resize(maxEntities);
	}

	size_t ECSMemoryPool::createEntity(const std::string& tag)
	{
		size_t index = getFirstFreeIndex();

		resetComponentVectors(m_pool, index, std::make_index_sequence<std::tuple_size<decltype(m_pool)>::value>{});
		m_tags[index] = tag;
		m_active[index] = true;
		m_totalEntities++;
		return index;
	}

	void ECSMemoryPool::destroyEntity(size_t entityID)
	{
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
}