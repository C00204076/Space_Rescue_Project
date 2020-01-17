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

		player->setPowerUpTime(0);
		powerup->setActiveTime(0);
		powerup->setActive(0);
	}
}

//
void Collisions::playerTileCollision(Player* player, TileMap* tilemap)
{
	/*sprite.getPosition().x < sprite2.getPosition().x + shape2.width &&
	  sprite.getPosition().x + shape1.width > sprite2.getPosition().x &&
	  sprite.getPosition().y < sprite2.getPosition().y + shape2.height &&
	  shape1.height + sprite.getPosition().y > sprite2.getPosition().y*/
	/*for (int i = 0; i < 30; i++)
	{

		for (int j = 0; j < 30; j++)
		{
			if (player->getPosition().x < tilemap->getTiles(1, 1)->getPosition().x + tilemap->getTiles(1, 1)->getRect().getSize().x &&
				player->getPosition().x + 25 > tilemap->getTiles(1, 1)->getPosition().x&&
				player->getPosition().y < tilemap->getTiles(1, 1)->getPosition().y + tilemap->getTiles(1, 1)->getRect().getSize().y &&
				player->getPosition().y + 25 > tilemap->getTiles(1, 1)->getPosition().y)
			{
				if (tilemap->getTiles[i][j]->getType() == 9)
				{
					player->setCollide(true);
				}

			}
		}
	}*/
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

//
void Collisions::update(Player* player, TileMap* tilemap, PowerUp* powerup, Missile* missile)
{
	playerPowerUpCollision(player, powerup);
	//playerTileCollision(player, tilemap);
	//playerMissileCollision(player, missile);
	//playerEnemyCollision(player);
	//enemyMissileCollision();
	//enemyTileCollision();
	//playerWorkerCollision(player);
	//enemyWorkerCollision();
	//workerTileCollision();
}