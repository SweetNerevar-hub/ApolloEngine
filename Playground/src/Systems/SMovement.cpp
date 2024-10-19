#include "Systems.h"

using namespace Apollo::ECS;

void SMovement::update(Entities& entities)
{
	for (Entity& e : entities)
	{
		if (e.has<MoveSpeed>() && e.has<Velocity>())
		{
			float moveSpeed = e.get<MoveSpeed>().moveSpeed;
			sf::Vector2f vel = { e.get<Velocity>().vx, e.get<Velocity>().vy };

			e.get<Position>().x += vel.x * moveSpeed;
			e.get<Position>().y += vel.y * moveSpeed;
		}
	}
}