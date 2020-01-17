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

/// <summary>
/// Collisions default constructor
/// </summary>
Collisions::Collisions()
{

}

/// <summary>
/// Collsions default constructor
/// </summary>
Collisions::~Collisions()
{
	//delete this;
}

/// <summary>
/// Detects the collsion between the Player and PowerUp Objects
/// </summary>
/// <param name="player"></param>
/// <param name="powerup"></param>
void Collisions::playerPowerUpCollision(Player* player, PowerUp* powerup)
{
	// Uses simple intersection, using the GobalBounds of both Object as 
	// nothing overly complex is needed
	if (player->getSprite().getGlobalBounds().intersects(powerup->getSprite().getGlobalBounds()))
	{
		// If the PowerUp's m_type is 1, i.e damage-resist powerup
		if (powerup->getType() == 1)
		{
			player->setImmune(true);
			player->setSpeed(false);
		}
		// If the PowerU's m_type is 2, i.e speed boost powerup
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

/// <summary>
/// Collisions between Player and Tile Objects
/// </summary>
/// <param name="player"></param>
/// <param name="tilemap"></param>
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

/// <summary>
/// Collisions between Player and Nest Missile Objects
/// </summary>
/// <param name="player"></param>
/// <param name="missile"></param>
void Collisions::playerMissileCollision(Player* player, Missile* missile)
{
	// Checks to set if Missile Object is set to NEst and not Player 
	// before collision
	if (missile->getIsNest() == true && missile->getIsPlayer() == true)
	{
		if (player->getSprite().getGlobalBounds().intersects(missile->getSprite().getGlobalBounds()))
		{
			player->setHit(true);
		}
	}
}

/// <summary>
/// Collisions between Player and Predator Objects
/// </summary>
/// <param name="player"></param>
void Collisions::playerEnemyCollision(Player* player)
{
	player->setHit(true);
}

/// <summary>
/// Collisions betweenPredator and Missile Objects
/// </summary>
void Collisions::enemyMissileCollision()
{

}

/// <summary>
/// Collisions between Predator and Tile Objects
/// </summary>
void Collisions::enemyTileCollision()
{

}

/// <summary>
/// Collisions between Player and Worker Objects
/// </summary>
/// <param name="player"></param>
void Collisions::playerWorkerCollision(Player* player)
{

}

/// <summary>
/// Collisions between Worker and Predator Objects
/// </summary>
void Collisions::enemyWorkerCollision()
{

}

/// <summary>
/// Collisions between Worker and Tile Objects
/// </summary>
void Collisions::workerTileCollision()
{

}

/// <summary>
/// Method used to update all collision methods using the Game's
/// GameObjects as arguements
/// </summary>
/// <param name="player"></param>
/// <param name="tilemap"></param>
/// <param name="powerup"></param>
/// <param name="missile"></param>
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