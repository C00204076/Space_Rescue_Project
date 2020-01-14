//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 16:51 14 January 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef MISSILE_H
#define MISSILE_H

#include <iostream>

#include "SFML/Graphics.hpp"

#include "Player.h"

class Missile
{
public:
	Missile(bool isPlayer, bool isNest);
	~Missile();

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow& window);

	
	void setRotation(Player* player);
	void setMissileRotation(Player* player);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);

	sf::Sprite getSprite();

	void setIsPlayer(bool isPlayer);
	bool getIsPlayer();

	void setIsNest(bool isNest);
	bool getIsNest();

	void setActive(bool active);
	bool getActive();



private:
	void initialise();
	void loadTexture();
	

	sf::Vector2f m_position, m_velocity;
	sf::Sprite m_sprite;
	sf::Texture m_textureOne, m_textureTwo;

	int m_lifeTime;

	bool m_isPlayer, m_isNest, m_active;
};

#endif // !MISSILE_H

