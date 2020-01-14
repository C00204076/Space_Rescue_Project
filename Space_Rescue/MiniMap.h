//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 10:49 10 January 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef MINIMAP_H
#define MINIMAP_H

#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"

#include "TileMap.h"
#include "Player.h"
#include "Power-up.h"

//
class MiniMap
{
public:
	// Added new arguments to constructor to add more
	// objects of minimap
	MiniMap(TileMap* tileMap, Player* player, PowerUp* powerUp);
	~MiniMap();

	void update(sf::Time deltaTime, sf::RenderWindow& window, sf::View view);
	void render(sf::RenderWindow& window, sf::View view);

private:
	void initialise();

	// Create more Object variable to hold constructor
	// arguements
	TileMap* m_tileMap;
	Player* m_player;
	PowerUp* m_powerUp;
};

#endif // !MINIMAP_H

