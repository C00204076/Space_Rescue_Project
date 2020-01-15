//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 10:39 14 January 2019
// Finished at
// Time taken:
// Known bugs:

#include "Collisions.h"

//
Collisions::Collisions()
{

}

//
Collisions::~Collisions()
{
	delete this;
}

//
void Collisions::playerPowerUpCollision(Player* player, PowerUp* powerup)
{
	//
	if (powerup->getType() == 1)
	{
		player->setImmune(true);
		player->setSpeed(false);
	}
	//
	else if(powerup->getType() == 2)
	{
		player->setImmune(false);
		player->setSpeed(true);
	}

	powerup->setActiveTime(0);
	powerup->setActive(0);
}

//
void Collisions::playerTileCollision(Player* player, TileMap* tilemap)
{
	player->setCollide(true);
}

//
void Collisions::playerMissileCollision(Player* player, Missile* missile)
{
	player->setHit(true);
}

//
void Collisions::playerEnemyCollision(Player* player)
{
	player->setHit(true);
}

//
void Collisions::enemyMissileCollision()
{

}

//
void Collisions::enemyTileCollision()
{

}

//
void Collisions::playerWorkerCollision(Player* player)
{

}

//
void Collisions::enemyWorkerCollision()
{

}

//
void Collisions::workerTileCollision()
{

}