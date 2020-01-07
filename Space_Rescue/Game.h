//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 9:45 7 January 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class TileMap;

//
class Game
{
public:
	Game();
	~Game();

	void run();

private:
	void initialise();
	void processEvents(); //Process all game events
	void processGameEvents(sf::Event&);
	void processInput();
	void update(sf::Time deltaTime);
	void render();

	sf::RenderWindow m_window;
	bool is_running;

	TileMap* m_tileMap;
};

#include "TileMap.h"

#endif // !GAME_H
