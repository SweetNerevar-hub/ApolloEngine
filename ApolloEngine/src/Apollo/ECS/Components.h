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
		CPosition(float x, float y) :
			position(sf::Vector2f{x, y}) { }
	};

	class CVelocity : public Component
	{
	public:
		sf::Vector2f velocity;

		CVelocity() = default;
		CVelocity(float x, float y) :
			velocity(sf::Vector2f{x, y}) { }
	};

	class CMoveSpeed : public Component
	{
	public:
		float moveSpeed = 0.f;

		CMoveSpeed() = default;
		CMoveSpeed(float speed) :
			moveSpeed(speed) { }
	};

	class CShape : public Component
	{
	public:
		sf::CircleShape shape;

		CShape() = default;
		CShape(float radius, sf::Color fillColour)
		{
			shape.setRadius(radius);
			shape.setFillColor(fillColour);
		}
	};
}