#pragma once

#include "pch.h"
#include "ECS/EntityManager.h"

namespace Apollo
{
	class IECS
	{
	public:
		static void updateEntityManager()
		{
			em.update();
		}

		static ECS::Entity createEntity(const std::string& tag)
		{
			return em.create(tag);
		}

	public:
		static ECS::EntityManager em;
	};
}