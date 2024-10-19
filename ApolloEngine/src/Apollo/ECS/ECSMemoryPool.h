#pragma once

#include "ComponentArray.h"

namespace Apollo::ECS
{
	using ComponentPool = std::unordered_map<std::type_index, std::unique_ptr<ComponentArrayBase>>;

	class APOLLO_API ECSMemoryPool
	{
	public:
		static ECSMemoryPool& Instance()
		{
			static ECSMemoryPool memoryPool;
			return memoryPool;
		}

		template<typename T>
		void add(size_t entityID)
		{
			getComponentArray<T>().add(entityID);
		}

		template<typename T>
		void remove(size_t entityID)
		{
			getComponentArray<T>().remove(entityID);
		}

		template<typename T>
		T& get(size_t entityID)
		{
			checkComponentRegistration<T>();
			return getComponentArray<T>().get(entityID);
		}

		template<typename T>
		bool has(size_t entityID)
		{
			return getComponentArray<T>().has(entityID);
		}

		template<typename T>
		void registerComponent()
		{
			m_pool[getTypeID<T>()] = std::make_unique<ComponentArray<T>>();
		}

		size_t createEntity(const std::string& tag);
		void destroyEntity(size_t entityID);
		const std::string& getTag(size_t entityID) const;
		const ComponentPool& getComponentPool() const;

	private:
		size_t m_totalEntities = 0;
		ComponentPool m_pool;
		std::vector<std::string> m_tags;
		std::vector<bool> m_active;

		size_t getFirstFreeIndex();

		template<typename T>
		ComponentArray<T>& getComponentArray()
		{
			return *static_cast<ComponentArray<T>*>(m_pool[getTypeID<T>()].get());
		}

		template<typename T>
		const std::type_index getTypeID() const
		{
			return std::type_index(typeid(T));
		}

		template<typename T>
		void checkComponentRegistration()
		{
			auto itr = m_pool.find(getTypeID<T>());
			if (itr == m_pool.end())
			{
				registerComponent<T>();
			}
		}

		ECSMemoryPool();
		ECSMemoryPool(ECSMemoryPool const&) = delete;
		ECSMemoryPool& operator= (ECSMemoryPool const&) = delete;
	};
}

//// (std::size_t... I)			Fold expression of each index of the tuple
//		// (std::index_sequence<I...>)	Sets up a container of those indicies for the "iterator" to work through?
//template<size_t... I>
//void resetComponentVectors(size_t index, std::index_sequence<I...>)
//{
//	// Perform an operation on this index of the tuple
//	// Then with (...) move onto the next index
//	((std::get<I>(m_pool)[index].active = false), ...);
//}