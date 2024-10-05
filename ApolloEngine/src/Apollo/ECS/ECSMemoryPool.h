#pragma once

#include "Components.h"

namespace Apollo::ECS
{
	typedef std::tuple<
		std::vector<CPosition>,
		std::vector<CVelocity>,
		std::vector<CMoveSpeed>,
		std::vector<CShape>
	> ComponentsTuple;

	class APOLLO_API ECSMemoryPool
	{
	public:
		static ECSMemoryPool& Instance()
		{
			static ECSMemoryPool memoryPool(1200);
			return memoryPool;
		}

		// (std::size_t... I)			Fold expression of each index of the tuple
		// (std::index_sequence<I...>)	Sets up a container of those indicies for the "iterator" to work through?
		template<size_t... I>
		void fillComponentVectors(size_t size, std::index_sequence<I...>)
		{
			// Perform an operation on this index of the tuple
			// Then with (...) move onto the next index
			(std::get<I>(m_pool).resize(size), ...);
		}

		template<size_t... I>
		void resetComponentVectors(size_t index, std::index_sequence<I...>)
		{
			((std::get<I>(m_pool)[index].active = false), ...);
		}

		template<typename T>
		void add(size_t entityID)
		{
			std::get<std::vector<T>>(m_pool)[entityID].active = true;
		}

		template<typename T>
		void remove(size_t entityID)
		{
			std::get<std::vector<T>>(m_pool)[entityID].active = false;
		}

		template<typename T>
		T& get(size_t entityID)
		{
			return std::get<std::vector<T>>(m_pool)[entityID];
		}

		template<typename T>
		bool has(size_t entityID)
		{
			return std::get<std::vector<T>>(m_pool)[entityID].active;
		}

		size_t createEntity(const std::string& tag);
		void destroyEntity(size_t entityID);
		const std::string& getTag(size_t entityID) const;
		size_t getFirstFreeIndex();

	private:
		size_t m_totalEntities = 0;
		ComponentsTuple m_pool;
		std::vector<std::string> m_tags;
		std::vector<bool> m_active;

		ECSMemoryPool(size_t maxEntities);
		ECSMemoryPool(ECSMemoryPool const&) = delete;
		ECSMemoryPool& operator= (ECSMemoryPool const&) = delete;
	};
}