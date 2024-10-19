#pragma once

#include "Entity.h"

namespace Apollo::ECS
{
	class EntityManager
	{
	public:
		std::vector<Entity> entities;

		// Reserve a block of memory for the initial max entity count
		void init();

		// Adds the entities from the addNextFrame list, 
		// into the main entities list at the beginning of each frame,
		// to avoid iterator invalidation
		void update();

		// Iterates through the entities array and compares each id against
		// the ones that are marked to be removed as listed in m_toRemove
		// and erases them from the array, as well as 
		void remove();

		// Creates a new entity
		// \param tag: This is the tag that will associated with the entity
		Entity create(const std::string& tag);

		// Marks the entity to be removed at the end of the frame
		// \param entity: The entity that will be removed from the scene
		void destroy(Entity entity);

		// Destroys all entities and clears the array
		void clear();

		// Returns the first entity with the given tag
		// \param tag: The tag by which you want to retrieve and entity
		Entity getEntityByTag(const std::string& tag);

		// Returns an array containing every entity with a given tag
		// \param tag: The tag by which you want to retrieve all entities
		std::vector<Entity> getEntitiesByTag(const std::string& tag);

	private:
		std::vector<Entity> m_addNextFrame;
		std::vector<size_t> m_toRemove;
	};
}