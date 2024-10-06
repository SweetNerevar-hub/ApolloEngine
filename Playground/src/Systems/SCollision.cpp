#include "SCollision.h"

using namespace Apollo::ECS;

void SCollision::update(Entities& entities)
{
	for (Entity& e : entities)
	{
		if (e.has<CShape>() && e.has<CVelocity>())
		{
			boundryCheck(e);
		}
	}
}

void SCollision::boundryCheck(Entity e)
{
	// Check if the bounds of the entity has reached the window border,
	// then have the entity bounce off
	CPosition& pos = e.get<CPosition>();
	CShape& shape = e.get<CShape>();
	sf::FloatRect bounds = shape.shape.getGlobalBounds();

	if (pos.position.y <= 0.f || 
		pos.position.y + bounds.height >= 600.f)
	{
		e.get<CVelocity>().velocity.y = -e.get<CVelocity>().velocity.y;
	}

	if (pos.position.x <= 0.f ||
		pos.position.x + bounds.width >= 800.f)
	{
		e.get<CVelocity>().velocity.x = -e.get<CVelocity>().velocity.x;
	}
}

void SCollision::updateColliders(Entity e)
{
	// Update entity colliders
}