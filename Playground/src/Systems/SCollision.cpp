#include "Systems.h"

using namespace Apollo::ECS;

void SCollision::update(Entities& entities)
{
	for (Entity& e : entities)
	{
		if (e.has<Shape>() && e.has<Velocity>())
		{
			boundryCheck(e);
		}
	}
}

void SCollision::boundryCheck(Entity e)
{
	// Check if the bounds of the entity has reached the window border,
	// then have the entity bounce off
	Position& pos = e.get<Position>();
	Shape& shape = e.get<Shape>();
	sf::FloatRect bounds = shape.shape.getGlobalBounds();

	if (pos.y <= 0.f || 
		pos.y + bounds.height >= Apollo::Window::getWindowSize().y)
	{
		e.get<Velocity>().vy = -e.get<Velocity>().vy;
	}

	if (pos.x <= 0.f ||
		pos.x + bounds.width >= Apollo::Window::getWindowSize().x)
	{
		e.get<Velocity>().vx = -e.get<Velocity>().vx;
	}
}

void SCollision::updateColliders(Entity e)
{
	// Update entity colliders
}