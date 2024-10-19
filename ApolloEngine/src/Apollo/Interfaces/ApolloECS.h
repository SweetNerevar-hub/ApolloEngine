#pragma once

#include "../ECS/EntityManager.h"
#include "../ECS/SystemsManager.h"
#include "../ECS/PrefabManager.h"

namespace Apollo
{
	class APOLLO_API ApolloECS
	{
		friend class Engine;

	public:
		// Creates a new entity
		// \param tag: This is the tag that will associated with the entity
		static ECS::Entity createEntity(const std::string& tag);

		// Marks the entity to be removed at the end of the frame
		// \param entity: The entity that will be removed from the scene
		static void destroyEntity(ECS::Entity entity);


		static std::vector<ECS::Entity>& getEntities();

		static void updateSystems();

		template<typename T>
		static void registerSystem()
		{
			s_systemsManager.registerSystem<T>();
		}

		static void createPrefab(ECS::Entity archetype, const std::string& name);
		static ECS::Entity instantiate(const std::string& name);

		template<typename T>
		static void registerComponent()
		{
			ECS::ECSMemoryPool::Instance().registerComponent<T>();
		}

	private:
		inline static ECS::EntityManager s_entityManager;
		inline static ECS::SystemsManager s_systemsManager;
		inline static ECS::PrefabManager s_prefabManager;

		static void initialise();
		static void updateEntityList();
		static void removeDeadEntities();
	};
}