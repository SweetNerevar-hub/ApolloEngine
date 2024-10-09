#pragma once

#include <Apollo.h>

class OnPlayerCollision : public Apollo::Event::GameEvent
{
public:
	OnPlayerCollision(Apollo::ECS::Entity& other) : 
		m_other(other) {}

	void process() override;

private:
	Apollo::ECS::Entity& m_other;
};

class OnCircleSpawn : public Apollo::Event::GameEvent
{
public:
	OnCircleSpawn(sf::Color colour) : 
		m_colour(colour) {}

	void process() override;

private:
	sf::Color m_colour;
};