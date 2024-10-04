#pragma once

#include "pch.h"
#include <Apollo/Entry.h>
#include <Apollo.h>

class Game : public Apollo::IGame
{
public:
	Game() = default;

	// This is just for testing, as init's will be apart of scenes/states
	void init() override;

	void handleEvents(sf::Event& event) override;
	void update() override;
	void render(sf::RenderWindow& window) override;

private:
	std::vector<Apollo::ECS::CShape> m_circles;

	void createCircle();
};