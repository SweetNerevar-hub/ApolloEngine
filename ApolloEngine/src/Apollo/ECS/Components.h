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

		CPosition() = default;
	};

	class CVelocity : public Component
	{
	public:
		sf::Vector2f velocity;

		CVelocity() = default;
	};

	class CMoveSpeed : public Component
	{
	public:
		float moveSpeed;

		CMoveSpeed() = default;
	};

	class CShape : public Component
	{
	public:
		sf::CircleShape shape;

		CShape() = default;
	};
}