#pragma once

#include <array>

#include "Component.h"
#include "../Global.h"

namespace Apollo::ECS
{
	class ComponentArrayBase
	{
	public:
		virtual void copyToPrefab(std::vector<Component*>& components, size_t archetypeID) = 0;
		virtual void copyToEntity(std::vector<Component*>& components, size_t entityID) = 0;
		virtual void removeEntity(size_t entityID) = 0;
	};

	template<typename T>
	class ComponentArray : public ComponentArrayBase
	{
	public:
		ComponentArray()
		{
			m_componentArray.resize(Global::Instance().maxEntities);
		}

		void copyToPrefab(std::vector<Component*>& components, size_t archetypeID)
		{
			if (has(archetypeID))
			{
				components.emplace_back(new T(m_componentArray[archetypeID]));
			}
		}

		void copyToEntity(std::vector<Component*>& components, size_t entityID)
		{
			for (auto& comp : components)
			{
				auto* c = static_cast<T*>(comp);
				if (std::type_index(typeid(*c)) == std::type_index(typeid(T)))
				{
					add(entityID);
					m_componentArray[entityID] = *c;
				}
			}
		}

		void removeEntity(size_t entityID)
		{
			if (has(entityID))
			{
				remove(entityID);
			}
		}

		void add(size_t entityID)
		{
			m_componentArray[entityID].active = true;
		}

		void remove(size_t entityID)
		{
			m_componentArray[entityID].active = false;
		}

		T& get(size_t entityID)
		{
			return m_componentArray[entityID];
		}

		bool has(size_t entityID)
		{
			return m_componentArray[entityID].active;
		}

	private:
		std::vector<T> m_componentArray;
	};
}