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

#include "SFML/Graphics.hpp"

//
class PowerUp
{
public:
	PowerUp();
	~PowerUp();

	void initialise();

	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow window);

private:
	sf::Sprite m_sprite;
	sf::Texture m_textureOne, m_textureTwo;

	int m_type;
};

#endif // !POWERUP_H
