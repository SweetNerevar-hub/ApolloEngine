#pragma once

#include "EntityManager.h"

namespace Apollo::ECS
{
	typedef std::vector<Entity> Entities;

	class System
	{
	protected:
		virtual void update(Entities& entities) = 0;
	};
}