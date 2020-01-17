//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 10:59 10 January 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef POWERUP_H
#define POWERUP_H

#include <iostream>
#include <cstdlib>

#include "SFML/Graphics.hpp"
#include "TileMap.h"

// PowerUp Class Object
class PowerUp
{
public:
	PowerUp();
	~PowerUp();

	void update(sf::Time deltaTime);
	void update(sf::Time deltaTime, TileMap* tilemap);
	void render(sf::RenderWindow& window);
	void render(sf::RenderWindow& window, sf::Vector2f scale);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);

	sf::Sprite getSprite();

	void setType(int type);
	int getType();

	void setActive(bool active);
	bool getActive();

	void setActiveTime(int lifeTime);

private:
	void initialise();
	void loadTexture();

	void spawnPowerUp(TileMap* tilemap);
	void powerUpLifeTime();
	void animatePowerUp();

	sf::Vector2f m_position;
	sf::Sprite m_sprite;
	sf::Texture m_textureOne, m_textureTwo;

	int m_type;
	int m_activeTime, m_animaTime, m_respawnTime; 
	int m_randX, m_randY;

	bool m_active, m_collide;
};

#endif // !POWERUP_H
