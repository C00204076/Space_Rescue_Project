//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 9:52 7 January 2020
// Finished at
// Time taken:
// Known bugs:

#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"

//
class TileMap
{
public:
	TileMap(float gridSize);
	~TileMap();

	void update(sf::Time deltaTime, sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
	void render(sf::RenderWindow& window, sf::Vector2f scale);

	void setValues();

private:
	void initialise();

	float m_maxSize;
	Tile* m_tiles[50][50];

};

#endif // !TILEMAP_H
