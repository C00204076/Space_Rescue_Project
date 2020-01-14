//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 10:39 14 January 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <iostream>

#include "SFML/Graphics.hpp"

#include "TileMap.h"
#include "Player.h"
#include "Power-up.h"

//
class Collisions
{
public:
	Collisions();
	~Collisions();

	void playerPowerUpCollision(Player* player, PowerUp* powerup);
	void playerTileCollision(Player* player, TileMap* tilemap);

private:

};

#endif // !COLLISIONS_H

