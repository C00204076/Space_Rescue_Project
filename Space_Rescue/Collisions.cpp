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
	//delete this;
}

//
void Collisions::playerPowerUpCollision(Player* player, PowerUp* powerup)
{
	//
	if (player->getSprite().getGlobalBounds().intersects(powerup->getSprite().getGlobalBounds()))
	{
		//
		if (powerup->getType() == 1)
		{
			player->setImmune(true);
			player->setSpeed(false);
		}
		//
		else if (powerup->getType() == 2)
		{
			player->setImmune(false);
			player->setSpeed(true);
		}

		powerup->setActiveTime(0);
		powerup->setActive(0);
	}
}

//
void Collisions::playerTileCollision(Player* player, TileMap* tilemap)
{
	player->setCollide(true);
}

//
void Collisions::playerMissileCollision(Player* player, Missile* missile)
{
	//
	if (missile->getIsNest() == true && missile->getIsPlayer() == true)
	{
		if (player->getSprite().getGlobalBounds().intersects(missile->getSprite().getGlobalBounds()))
		{
			player->setHit(true);
		}
	}
}

//
void Collisions::playerEnemyCollision(Player* player)
{
	player->setHit(true);
}

//
void Collisions::enemyMissileCollision(Predator* predator, Missile* missile)
{
	if (missile->getIsPlayer() == true)
	{
		if (predator->m_body.getGlobalBounds().intersects(missile->getSprite().getGlobalBounds()))
		{
			predator->setHit(true);
		}
	}
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

//
void Collisions::update(Player* player, Predator* predator, TileMap* tilemap, PowerUp* powerup, Missile* missile)
{
	playerPowerUpCollision(player, powerup);
	//playerTileCollision(player, tilemap);
	//playerMissileCollision(player, missile);
	//playerEnemyCollision(player);
	enemyMissileCollision(predator,missile);
	//enemyTileCollision();
	//playerWorkerCollision(player);
	//enemyWorkerCollision();
	//workerTileCollision();
}