#pragma once

#include "Entity.h"

namespace Apollo::ECS
{
	class EntityManager
	{
	public:
		EntityManager()
		{
			// Max amount of entities
			entities.reserve(100000);
		}

		std::vector<Entity> entities;

		// Adds the entities from the addNextFrame list, 
		// into the main entities list at the beginning of each frame,
		// to avoid interator invalidation
		void update();

		// Creates a new entity
		Entity create(const std::string& tag);

		// Destroys all entities and clears the list
		void clear();

		// Returns the first entity with the given tag
		Entity getEntityByTag(const std::string& tag);

		// Returns a list containing every entity with a given tag
		std::vector<Entity> getEntitiesByTag(const std::string& tag);

	private:
		std::vector<Entity> m_addNextFrame;
	};
}