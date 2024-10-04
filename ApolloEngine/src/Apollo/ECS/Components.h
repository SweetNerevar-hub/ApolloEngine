#pragma once

#include "pch.h"

namespace Apollo::ECS
{
	class Component
	{
	public:
		bool active = false;
	};

	class CPosition : public Component
	{
	public:
		sf::Vector2f position;
	};

	class CShape : public Component
	{
	public:
		sf::CircleShape shape;
	};
}