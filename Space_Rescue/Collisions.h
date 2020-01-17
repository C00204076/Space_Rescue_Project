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
#include "Missile.h"
#include "Predator.h"
//
class Collisions
{
public:
	Collisions();
	~Collisions();

	void update(Player* player, Predator* predator, TileMap* tilemap, PowerUp* powerup, Missile* missile);

private:
	void playerPowerUpCollision(Player* player, PowerUp* powerup);
	void playerTileCollision(Player* player, TileMap* tilemap);
	void playerMissileCollision(Player* player, Missile* missile);
	void playerEnemyCollision(Player* player);
	void enemyMissileCollision(Predator* predator, Missile* missile);
	void enemyTileCollision();
	void playerWorkerCollision(Player* player);
	void enemyWorkerCollision();
	void workerTileCollision();
};

#endif // !COLLISIONS_H

