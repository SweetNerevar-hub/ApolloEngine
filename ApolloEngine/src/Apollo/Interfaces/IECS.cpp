#include "pch.h"
#include "IECS.h"

namespace Apollo
{
	ECS::EntityManager IECS::s_entityManager;
	void IECS::updateEntityList()
	{
		s_entityManager.update();
	}

	ECS::Entity IECS::createEntity(const std::string& tag)
	{
		return s_entityManager.create(tag);
	}

	std::vector<ECS::Entity>& IECS::getEntities()
	{
		return s_entityManager.entities;
	}

	ECS::SystemsManager IECS::s_systemsManager;
	void IECS::updateSystems()
	{
		s_systemsManager.updateSystems(s_entityManager.entities);
	}

	void IECS::registerSystem(std::unique_ptr<ECS::System> system)
	{
		s_systemsManager.registerSystem(std::move(system));
	}
}