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

class Player
{
public:
	Player();
	~Player();

	void update(sf::Time deltaTime, sf::View& v);
	void render(sf::RenderWindow& window);
	void render(sf::RenderWindow& window, sf::Vector2f scale);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);

	sf::Sprite getSprite();

	sf::Vector2f getVelocity();

	bool getImmune();
	void setImmune(bool immune);

	bool getSpeed();
	void setSpeed(bool speed);


private:
	void initalise();
	void loadTexture();

	void move();
	
	void powerup();


	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_position, m_velocity;


	float m_maxSpeed, m_addedSpeed;

	bool m_immune, m_speed;
};

#endif // !PLAYER_H
