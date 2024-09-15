#pragma once

namespace Apollo 
{
	class IGame
	{
	public:
		~IGame() = default;

		// This is just for testing
		// init's will be apart of scenes/states and not the main game class
		virtual void init() = 0;

		virtual void handleEvents(sf::Event event) = 0;
		virtual void update() = 0;
		virtual void render(sf::RenderWindow& window) = 0;
	};

	IGame* createGame();
}