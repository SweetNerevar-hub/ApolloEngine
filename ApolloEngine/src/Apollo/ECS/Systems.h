#pragma once

#include "Entity.h"

namespace Apollo::ECS
{
	typedef std::vector<Entity> Entities;

	class System
	{
	public:
		virtual void update(Entities& entities) = 0;
	};
}