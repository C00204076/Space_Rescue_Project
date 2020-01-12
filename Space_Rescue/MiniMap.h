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
	MiniMap(Player* player);
	~MiniMap();

	void update(sf::Time deltaTime, sf::RenderWindow& window, sf::View view);
	void render(sf::RenderWindow& window, sf::View view);

private:
	void initialise();

	TileMap* m_tileMap;
	Player* m_player;
};

#endif // !MINIMAP_H

