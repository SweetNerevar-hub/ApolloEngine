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
	CShape& shape = e.get<CShape>();
	sf::FloatRect bounds = shape.shape.getGlobalBounds();

	if (bounds.getPosition().y <= 0.f || 
		bounds.getPosition().y + bounds.height >= 600.f)
	{
		e.get<CVelocity>().velocity.y = -e.get<CVelocity>().velocity.y;
	}

	if (bounds.getPosition().x <= 0.f ||
		bounds.getPosition().x + bounds.width >= 800.f)
	{
		e.get<CVelocity>().velocity.x = -e.get<CVelocity>().velocity.x;
	}
}

void SCollision::updateColliders(Entity e)
{
	// Update entity colliders
}