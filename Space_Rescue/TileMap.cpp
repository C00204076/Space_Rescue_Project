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
			m_tiles[i][j] = new Tile(m_map[i][j], i, j);
			m_tiles[i][j]->setType(m_map[i][j]);
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

//
void TileMap::render(sf::RenderWindow& window, sf::Vector2f scale)
{

	for (int i = 0; i < m_maxSize; i++)
	{
		for (int j = 0; j < m_maxSize; j++)
		{
			if (m_tiles[i][j]->getType() != 0)
			{
				m_tiles[i][j]->getRect().setScale(scale);
				m_tiles[i][j]->render(window);
			}
		}
	}

}