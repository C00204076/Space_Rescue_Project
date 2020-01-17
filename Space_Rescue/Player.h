//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 11:11 7 January 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "SFML/Graphics.hpp"
#include "TileMap.h"

class Missile;

class Player
{
public:
	Player();
	~Player();

	void update(sf::Time deltaTime, sf::View& v);
	void render(sf::RenderWindow& window);
	void render(sf::RenderWindow& window, sf::Vector2f scale);

	void tileCollision(TileMap* tilemap);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);

	sf::Sprite getSprite();

	sf::Vector2f getVelocity();

	bool getImmune();
	void setImmune(bool immune);

	bool getSpeed();
	void setSpeed(bool speed);

	bool getCollide();
	void setCollide(bool collide);

	bool getHit();
	void setHit(bool hit);

	int getHP();
	void setHP(int hp);

	void setFireDelay(int fireDelay);

	Missile* getMissile();

	int getPowerUpTime();
	void setPowerUpTime(int time);

private:
	void initalise();
	void loadTexture();

	void move();
	
	void powerup();
	void iFrames();
	

	void fire();

	void collision();

	sf::Sprite m_sprite, m_powerupSprite;
	sf::Texture m_texture, m_powerupTexture;
	sf::Vector2f m_position, m_velocity;

	sf::Vertex m_center;
	sf::CircleShape m_circle;

	float m_maxSpeed, m_addedSpeed;
	int m_hp, m_iFrameTime, m_animateTime, m_fireDelay, m_powerupTime, m_powerupAnimate;

	bool m_immune, m_speed, m_hit, m_collide;

	Missile* m_bullet;
};

#include "Missile.h"

#endif // !PLAYER_H
