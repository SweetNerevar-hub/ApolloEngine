#include "pch.h"
#include "SMovement.h"

using namespace Apollo::ECS;

void SMovement::update(Entities& entities)
{
	for (Entity& e : entities)
	{
		if (e.has<CMoveSpeed>() && e.has<CVelocity>())
		{
			float moveSpeed = e.get<CMoveSpeed>().moveSpeed;
			sf::Vector2f vel = e.get<CVelocity>().velocity;

			e.get<CPosition>().position += vel * moveSpeed;
		}
	}
}