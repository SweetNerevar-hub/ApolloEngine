#pragma once

#include <Apollo.h>
#include <Apollo/Entry.h>

#include "Systems/Systems.h"
#include "Components/Components.h"

#include "GameEvents/GameEvents.h"

using namespace Apollo;
using namespace Apollo::ECS;
using namespace Apollo::Utils;
using namespace Apollo::Event;

class Game : public Apollo::IGame
{
public:
	Game(size_t entityArraySize) : IGame(entityArraySize) {}

	void init() override;
	void handleInput(sf::Event& event) override;
	void update() override;
	void render(sf::RenderWindow& window) override;

private:
	bool m_usePrefab = false;
	bool t = false;

	void createCircle(int amount);
	sf::Color getRandomColour();
};