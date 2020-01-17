//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 9:52 7 January 2020
// Finished at
// Time taken:
// Known bugs:

#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Tile Class Object
class Tile
{
public:
	Tile();
	Tile(int type, int gridX, int gridY);
	~Tile();

	void render(sf::RenderWindow& window);

	int getType();
	sf::Vector2f getPosition();
	sf::Vector2f getWorldPosition();
	sf::RectangleShape getRect();

	void setColour();
	void setType(int type);
	void setValue(int value);



private:
	void initialise();
	sf::RectangleShape m_square;
	sf::Vector2f m_position;
	int m_type, m_x, m_y;
	int m_value;
};

#endif // !TILE_H

