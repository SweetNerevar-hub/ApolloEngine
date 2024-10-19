#include "pch.h"
#include "ApolloECS.h"

namespace Apollo
{
	void ApolloECS::initialise()
	{
		s_entityManager.init();
	}

	ECS::Entity ApolloECS::createEntity(const std::string& tag)
	{
		return s_entityManager.create(tag);
	}

	void ApolloECS::destroyEntity(ECS::Entity entity)
	{
		s_entityManager.destroy(entity);
	}

	std::vector<ECS::Entity>& ApolloECS::getEntities()
	{
		return s_entityManager.entities;
	}

	void ApolloECS::updateSystems()
	{
		s_systemsManager.updateSystems(s_entityManager.entities);
	}

	void ApolloECS::createPrefab(ECS::Entity archetype, const std::string& name)
	{
		s_prefabManager.createPrefab(archetype, name);
	}

	ECS::Entity ApolloECS::instantiate(const std::string& name)
	{
		return s_prefabManager.instaniate(name);
	}

	void ApolloECS::updateEntityList()
	{
		s_entityManager.update();
	}

	void ApolloECS::removeDeadEntities()
	{
		s_entityManager.remove();
	}
}