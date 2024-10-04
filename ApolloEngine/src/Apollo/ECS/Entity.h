#pragma once

#include "pch.h"
#include "ECSMemoryPool.h"

namespace Apollo::ECS
{
	class Entity
	{
	public:
		size_t id = 0;

		Entity() = default;
		Entity(size_t id) : id(id) {}
		~Entity() {}

		template<typename T, typename... TArgs>
		void add(TArgs&&... args)
		{
			auto& c = get<T>();
			c = T(std::forward<TArgs>(args));

			return ECSMemoryPool::Instance().add<T>(id);
		}

		template<typename T>
		T& remove()
		{
			return ECSMemoryPool::Instance().remove<T>(id);
		}

		template<typename T>
		T& get()
		{
			return ECSMemoryPool::Instance().get<T>(id);
		}

		template<typename T>
		bool has()
		{
			return ECSMemoryPool::Instance().has<T>(id);
		}

		const std::string& getTag()
		{
			return ECSMemoryPool::Instance().getTag(id);
		}

		void destroy()
		{
			ECSMemoryPool::Instance().destroyEntity(id);
		}
	};
}