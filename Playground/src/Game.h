#pragma once

#include <Apollo.h>
#include <Apollo/Entry.h>

#include "Systems/SCollision.h"
#include "Systems/SMovement.h"

class Game : public Apollo::IGame
{
public:
	void init() override;
	void handleEvents(sf::Event& event) override;
	void update() override;
	void render(sf::RenderWindow& window) override;

	

private:
	void createCircle(int amount);
	sf::Color getRandomColour();
};