#include "Engine.h"

int main()
{
	// The IGame interface creates a new instance of a game class,
	// shoving it into the arguments of the engine construction.
	// And so gives the engine the instance of the actual game to call functions to
	Apollo::Engine* engine = new Apollo::Engine(Apollo::createGame());
	engine->run();

	delete engine;

	return 0;
}