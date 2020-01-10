//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 9:52 7 January 2020
// Finished at
// Time taken:
// Known bugs:

#include "TileMap.h"

//
TileMap::TileMap(float gridSize) :
	m_maxSize(gridSize)
{
	initialise();
}

//
TileMap::~TileMap()
{
	delete this;
}

//
void TileMap::initialise()
{
	for (int i = 0; i < m_maxSize; i++)
	{
		for (int j = 0; j < m_maxSize; j++)
		{
			m_tiles[i][j] = new Tile(0, i, j);
		}
	}

}

//
void TileMap::update(sf::Time deltaTime, sf::RenderWindow& window)
{

}



//
void TileMap::render(sf::RenderWindow& window)
{

	for (int i = 0; i < m_maxSize; i++)
	{
		for (int j = 0; j < m_maxSize; j++)
		{
			m_tiles[i][j]->render(window);
		}
	}

}