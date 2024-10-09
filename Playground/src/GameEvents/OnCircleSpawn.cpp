#include "pch.h"
#include "GameEvents.h"

void OnCircleSpawn::process()
{
	if (m_colour == sf::Color::Red)
	{
		std::cout << "Game Event Call: Red Circle Spawned!" << std::endl;
	}

	else if (m_colour == sf::Color::Blue)
	{
		std::cout << "Game Event Call: Blue Circle Spawned!" << std::endl;
	}
}