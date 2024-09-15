#pragma once

#include "Apollo.h"
#include "Apollo/IGame.h"

class Game : public Apollo::IGame
{
public:
	Game() = default;
	~Game() = default;

	// This is just for testing, as init's will be apart of scenes/states
	void init() override;

	void handleEvents(sf::Event event) override;
	void update() override;
	void render(sf::RenderWindow& window) override;

private:
	sf::CircleShape shape;
};