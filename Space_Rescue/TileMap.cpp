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

/// <summary>
/// TileMap default constructor
/// </summary>
/// <param name="gridSize"></param>
TileMap::TileMap(float gridSize) :
	m_maxSize(gridSize)
{
	initialise();
}

/// <summary>
/// TileMap default destructor
/// </summary>
TileMap::~TileMap()
{
	delete this;
}

/// <summary>
/// Initialisor used in initialising the Tile Objects within the 
/// TileMap Object, and set their m_type values
/// </summary>
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

/// <summary>
/// Method used to update the functions and variables of the TileMap Object
/// </summary>
/// <param name="deltaTime"></param>
/// <param name="window"></param>
void TileMap::update(sf::Time deltaTime, sf::RenderWindow& window)
{

}

/// <summary>
/// Method used to render and draw the Tile Objects of the TileMap
/// Object
/// </summary>
/// <param name="window"></param>
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

/// <summary>
/// Method used to render and draw the Tile Objects of the TileMap
/// Object; and scale it within the MiniMap Object
/// </summary>
/// <param name="window"></param>
/// <param name="scale"></param>
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

/// <summary>
/// Method used to return the and access the values of a Tile Object
/// within the m_tiles array using the given arguements
/// </summary>
/// <param name="i"></param>
/// <param name="j"></param>
Tile* TileMap::getTiles(int i, int j)
{
	return m_tiles[i][j];
}