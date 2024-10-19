#pragma once

#include <Apollo.h>

struct Position : public Apollo::ECS::Component
{
	float x = 0.f;
	float y = 0.f;

	Position() = default;
	Position(float x, float y) : x(x), y(y) { }
};

struct Velocity : public Apollo::ECS::Component
{
	float vx = 0.f;
	float vy = 0.f;

	Velocity() = default;
	Velocity(float vx, float vy) : vx(vx), vy(vy) {}
};

struct MoveSpeed : public Apollo::ECS::Component
{
	float moveSpeed = 0.f;

	MoveSpeed() = default;
	MoveSpeed(float speed) : moveSpeed(speed) { }
};

struct Shape : public Apollo::ECS::Component
{
	sf::CircleShape shape;

	Shape() = default;
	Shape(float radius, sf::Color fillColour)
	{
		shape.setRadius(radius);
		shape.setFillColor(fillColour);
	}
};