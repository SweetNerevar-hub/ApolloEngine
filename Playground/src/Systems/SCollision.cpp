#include "SCollision.h"

using namespace Apollo::ECS;

void SCollision::update(Entities& entities)
{
	for (Entity e : entities)
	{
		// If entity has box collider
		updateColliders(e);
	}
}

void SCollision::updateColliders(Entity e)
{
	// Update entity colliders
}