#pragma once

#include <Apollo.h>
#include "../Components/Components.h"

class OnPlayerCollision : public Apollo::Event::GameEvent
{
public:
	void process() override;
	
	OnPlayerCollision(Apollo::ECS::Entity& other) : m_other(other) {}

private:
	Apollo::ECS::Entity& m_other;
};

class OnCircleSpawn : public Apollo::Event::GameEvent
{
public:
	void process() override;

	OnCircleSpawn(sf::Color colour) : m_colour(colour) {}

private:
	sf::Color m_colour;
};