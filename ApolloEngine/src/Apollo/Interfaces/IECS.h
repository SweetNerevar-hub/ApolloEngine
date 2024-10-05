#pragma once

#include "../../pch.h"
#include "../ECS/EntityManager.h"
#include "../ECS/SystemsManager.h"

namespace Apollo
{
	class APOLLO_API IECS
	{
	public:
		static void updateEntityList();
		static ECS::Entity createEntity(const std::string& tag);
		static std::vector<ECS::Entity>& getEntities();

		static void updateSystems();
		static void registerSystem(std::unique_ptr<ECS::System> system);

	private:
		static ECS::EntityManager s_entityManager;
		static ECS::SystemsManager s_systemsManager;
	};
}