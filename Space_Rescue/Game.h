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
#include "Collisions.h"

class TileMap;
class Player;
class Predator;
class Worker;
class MiniMap;
class PowerUp;

// Game Class Object
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
	void clean();

	sf::View m_playerView, m_miniMapView;

	sf::RenderWindow m_window;
	bool is_running;

	TileMap* m_tileMap;
	TileMap* m_miniTile;

	Player* m_player;

	Predator* m_predator;

	Worker* m_worker;

	Player* m_miniPlayer;

	PowerUp* m_powerUp;
	PowerUp* m_miniPower;

	MiniMap* m_miniMap;

	Collisions m_collision;
};

#include "TileMap.h"
#include "Player.h"
#include "Predator.h"
#include "Worker.h"
#include "MiniMap.h"
#include "Power-up.h"

#endif // !GAME_H
