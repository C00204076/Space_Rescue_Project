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
	int m_keyPointCount = 0;
	for (int i = 0; i < m_maxSize; i++)
	{
		for (int j = 0; j < m_maxSize; j++)
		{
			m_tiles[i][j] = new Tile(m_map[i][j], i, j);
			m_tiles[i][j]->setType(m_map[i][j]);
			if (m_tiles[i][j]->getType() == 5)
			{
				m_keyPointStorage[m_keyPointCount] = sf::Vector2i(i,j);
				m_keyPointCount++;
			}
		}
	}
	m_keyPointCount = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_keyPointIndexs[i][j] = m_keyPointStorage[m_keyPointCount];
			m_keyPointCount++;
		}
	}

}

//
void TileMap::update(sf::Time deltaTime, sf::RenderWindow& window)
{

}

void TileMap::createCostField()
{

	m_list.push_back(m_tiles[m_startPoint.x][m_startPoint.y]);

	while (m_list.size() > 0)
	{
		
		findAdjacentCells();

		if (m_northPoint != sf::Vector2i(NULL, NULL))
		{
			if (m_tiles[m_northPoint.x][m_northPoint.y]->getValue() == 0)
			{
				m_tiles[m_northPoint.x][m_northPoint.y]->setValue(m_list.front()->getValue() + 1);

				m_list.push_back(m_tiles[m_northPoint.x][m_northPoint.y]);
			}
		}

		if (m_northWestPoint != sf::Vector2i(NULL, NULL))
		{
			if (m_tiles[m_northWestPoint.x][m_northWestPoint.y]->getValue() == 0)
			{
				m_tiles[m_northWestPoint.x][m_northWestPoint.y]->setValue(m_list.front()->getValue() + 1);

				m_list.push_back(m_tiles[m_northWestPoint.x][m_northWestPoint.y]);
			}
		}

		if (m_westPoint != sf::Vector2i(NULL, NULL))
		{
			if (m_tiles[m_westPoint.x][m_westPoint.y]->getValue() == 0)
			{
				m_tiles[m_westPoint.x][m_westPoint.y]->setValue(m_list.front()->getValue() + 1);

				m_list.push_back(m_tiles[m_westPoint.x][m_westPoint.y]);
			}
		}

		if (m_southWestPoint != sf::Vector2i(NULL, NULL))
		{
			if (m_tiles[m_southWestPoint.x][m_southWestPoint.y]->getValue() == 0)
			{
				m_tiles[m_southWestPoint.x][m_southWestPoint.y]->setValue(m_list.front()->getValue() + 1);

				m_list.push_back(m_tiles[m_southWestPoint.x][m_southWestPoint.y]);
			}
		}

		if (m_southPoint != sf::Vector2i(NULL, NULL))
		{
			if (m_tiles[m_southPoint.x][m_southPoint.y]->getValue() == 0)
			{
				m_tiles[m_southPoint.x][m_southPoint.y]->setValue(m_list.front()->getValue() + 1);

				m_list.push_back(m_tiles[m_southPoint.x][m_southPoint.y]);
			}
		}

		if (m_southEastPoint != sf::Vector2i(NULL, NULL))
		{
			if (m_tiles[m_southEastPoint.x][m_southEastPoint.y]->getValue() == 0)
			{
				m_tiles[m_southEastPoint.x][m_southEastPoint.y]->setValue(m_list.front()->getValue() + 1);

				m_list.push_back(m_tiles[m_southEastPoint.x][m_southEastPoint.y]);
			}
		}

		if (m_eastPoint != sf::Vector2i(NULL, NULL))
		{
			if (m_tiles[m_eastPoint.x][m_eastPoint.y]->getValue() == 0)
			{
				m_tiles[m_eastPoint.x][m_eastPoint.y]->setValue(m_list.front()->getValue() + 1);

				m_list.push_back(m_tiles[m_eastPoint.x][m_eastPoint.y]);
			}
		}

		if (m_northEastPoint != sf::Vector2i(NULL, NULL))
		{
			if (m_tiles[m_northEastPoint.x][m_northEastPoint.y]->getValue() == 0)
			{
				m_tiles[m_northEastPoint.x][m_northEastPoint.y]->setValue(m_list.front()->getValue() + 1);

				m_list.push_back(m_tiles[m_northEastPoint.x][m_northEastPoint.y]);
			}
		}

		m_list.pop_front();
	}
}

void TileMap::resetField()
{
	for (int i = 1; i < 29; i++)
	{
		for (int j = 1; j < 29; j++)
		{
			if (m_tiles[i][j]->getValue() > 0 && m_tiles[i][j]->getValue() < 999)
			{
				m_tiles[i][j]->setValue(0);
			}
		}
	}
}

void TileMap::findAdjacentCells()
{
	if (m_list.front()->getIndex().y > 1)
	{
		m_northPoint = sf::Vector2i(m_list.front()->getIndex().x, m_list.front()->getIndex().y - 1);
	}
	else
	{
		m_northPoint = sf::Vector2i(NULL, NULL);
	}

	if (m_list.front()->getIndex().y < 28)
	{
		m_southPoint = sf::Vector2i(m_list.front()->getIndex().x, m_list.front()->getIndex().y + 1);
	}
	else
	{
		m_southPoint = sf::Vector2i(NULL, NULL);
	}

	if (m_list.front()->getIndex().x > 1)
	{
		m_westPoint = sf::Vector2i(m_list.front()->getIndex().x - 1, m_list.front()->getIndex().y);
	}
	else
	{
		m_westPoint = sf::Vector2i(NULL, NULL);
	}

	if (m_list.front()->getIndex().x < 28)
	{
		m_eastPoint = sf::Vector2i(m_list.front()->getIndex().x + 1, m_list.front()->getIndex().y);
	}
	else
	{
		m_eastPoint = sf::Vector2i(NULL, NULL);
	}

	if (m_list.front()->getIndex().x > 1 && m_list.front()->getIndex().y > 1)
	{
		m_northWestPoint = sf::Vector2i(m_list.front()->getIndex().x - 1, m_list.front()->getIndex().y - 1);
	}
	else
	{
		m_northWestPoint = sf::Vector2i(NULL, NULL);
	}

	if (m_list.front()->getIndex().x < 28 && m_list.front()->getIndex().y > 1)
	{
		m_northEastPoint = sf::Vector2i(m_list.front()->getIndex().x + 1, m_list.front()->getIndex().y - 1);
	}
	else
	{
		m_northEastPoint = sf::Vector2i(NULL, NULL);;
	}

	if (m_list.front()->getIndex().x > 1 && m_list.front()->getIndex().y < 28)
	{
		m_southWestPoint = sf::Vector2i(m_list.front()->getIndex().x - 1, m_list.front()->getIndex().y + 1);
	}
	else
	{
		m_southWestPoint = sf::Vector2i(NULL, NULL);;
	}

	if (m_list.front()->getIndex().x < 28 && m_list.front()->getIndex().y < 28)
	{
		m_southEastPoint = sf::Vector2i(m_list.front()->getIndex().x + 1, m_list.front()->getIndex().y + 1);
	}
	else
	{
		m_southEastPoint = sf::Vector2i(NULL, NULL);
	}
}

void TileMap::findLowestNeighbours(Tile* t_tile, float t_angle)
{
	sf::Vector2i m_lowestAdjacent;
	int m_lowest = 99999;
	float m_angle = t_angle * (180.0 / (22.0 / 7.0));
	if (m_angle < 0)
	{
		m_angle += 360.0;
	}

	if (t_tile->getIndex() != m_startPoint)
	{
		if ((m_angle < 22.5 || m_angle > 337.5))
		{
			m_lowestAdjacent = sf::Vector2i(t_tile->getIndex().x, t_tile->getIndex().y - 1);
			m_lowest = m_tiles[t_tile->getIndex().x][t_tile->getIndex().y - 1]->getValue();

		}
		else if (m_angle > 22.5 && m_angle < 67.5)
		{
			m_lowestAdjacent = sf::Vector2i(t_tile->getIndex().x - 1, t_tile->getIndex().y - 1);
			m_lowest = m_tiles[t_tile->getIndex().x - 1][t_tile->getIndex().y - 1]->getValue();

		}
		else if (m_angle > 67.5 && m_angle < 112.5)
		{
			m_lowestAdjacent = sf::Vector2i(t_tile->getIndex().x - 1, t_tile->getIndex().y);
			m_lowest = m_tiles[t_tile->getIndex().x - 1][t_tile->getIndex().y]->getValue();

		}
		else if (m_angle > 112.5 && m_angle < 157.5)
		{
			m_lowestAdjacent = sf::Vector2i(t_tile->getIndex().x - 1, t_tile->getIndex().y + 1);
			m_lowest = m_tiles[t_tile->getIndex().x - 1][t_tile->getIndex().y + 1]->getValue();

		}
		else if (m_angle > 157.5 && m_angle < 202.5)
		{
			m_lowestAdjacent = sf::Vector2i(t_tile->getIndex().x, t_tile->getIndex().y + 1);
			m_lowest = m_tiles[t_tile->getIndex().x][t_tile->getIndex().y + 1]->getValue();

		}
		else if (m_angle > 202.5 && m_angle < 247.5)
		{
			m_lowestAdjacent = sf::Vector2i(t_tile->getIndex().x + 1, t_tile->getIndex().y + 1);
			m_lowest = m_tiles[t_tile->getIndex().x + 1][t_tile->getIndex().y + 1]->getValue();

		}
		else if (m_angle > 247.5 && m_angle < 292.5)
		{
			m_lowestAdjacent = sf::Vector2i(t_tile->getIndex().x + 1, t_tile->getIndex().y);
			m_lowest = m_tiles[t_tile->getIndex().x + 1][t_tile->getIndex().y]->getValue();

		}
		else if (m_angle > 292.5 && m_angle < 337.5)
		{
			m_lowestAdjacent = sf::Vector2i(t_tile->getIndex().x + 1, t_tile->getIndex().y - 1);
			m_lowest = m_tiles[t_tile->getIndex().x + 1][t_tile->getIndex().y - 1]->getValue();

		}
	}
	for (int i = t_tile->getIndex().x - 1; i < t_tile->getIndex().x + 2; i++)
	{
		for (int j = t_tile->getIndex().y - 1; j < t_tile->getIndex().y + 2; j++)
		{
			if (sf::Vector2i(i, j) != t_tile->getIndex())
			{
				if (i >= 1 && i <= 28
					&&
					j >= 1 && j <= 28
					&&
					m_tiles[i][j]->getWall() == false)
				{
					if (m_tiles[i][j]->getValue() < m_lowest)
					{
						m_lowest = m_tiles[i][j]->getValue();
						m_lowestAdjacent = sf::Vector2i(i, j);
					}
				}
			}
		}
	}

	t_tile->setLowestNeighbour(m_lowestAdjacent);
}

std::list<Tile*> TileMap::createPath(sf::Vector2f t_currentPosition, sf::Vector2i t_targetIndex)
{
	m_startPoint = sf::Vector2i(round(t_currentPosition.x / 90.0), round(t_currentPosition.y / 90.0));
	m_tiles[m_startPoint.x][m_startPoint.y]->setValue(1);
	createCostField();
	for (int i = 1; i < 29; i++)
	{
		for (int j = 1; j < 29; j++)
		{
			float angle = atan2(m_tiles[i][j]->getIndex().x - m_startPoint.x, m_tiles[i][j]->getIndex().y - m_startPoint.y);
			findLowestNeighbours(m_tiles[i][j],angle);
		}
	}

	if (t_targetIndex.x == -1)
	{
		t_targetIndex = sf::Vector2i(rand() % 3, rand() % 3);
	}
	else
	{
		int direction;
		bool newPathFound = false;

		while (newPathFound == false)
		{
			direction = rand() % 4;

			if (t_targetIndex.x > 0 && direction == 0)
			{
				t_targetIndex.x -= 1;
				newPathFound = true;
			}
			else if (t_targetIndex.x < 2 && direction == 1)
			{
				t_targetIndex.x += 1;
				newPathFound = true;
			}
			else if (t_targetIndex.y > 0 && direction == 2)
			{
				t_targetIndex.y -= 1;
				newPathFound = true;
			}
			else if (t_targetIndex.y < 2 && direction == 3)
			{
				t_targetIndex.y += 1;
				newPathFound = true;
			}
		}
	}

	m_endPoint = m_keyPointIndexs[t_targetIndex.x][t_targetIndex.y];

	m_list.push_back(m_tiles[m_endPoint.x][m_endPoint.y]);

	sf::Vector2i m_nextPoint;

	while (m_list.back() != m_tiles[m_startPoint.x][m_startPoint.y])
	{
		m_nextPoint = m_list.back()->getLowestNeighbour();
		m_list.push_back(m_tiles[m_nextPoint.x][m_nextPoint.y]);
	}

	resetField();

	return m_list;
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