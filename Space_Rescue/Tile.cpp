//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 9:52 7 January 2020
// Finished at
// Time taken:
// Known bugs:

#include "Tile.h"

//
Tile::Tile()
{
	//initialise();
}

//
Tile::Tile(int type, int gridX, int gridY) :
	m_type(type),
	m_x(gridX),
	m_y(gridY)
{
	initialise();
}

//
Tile::~Tile()
{
	delete this;
}

//
void Tile::initialise()
{
	m_value = 1;

	m_square.setSize(sf::Vector2f(90, 90));
	setColour();
	m_square.setOutlineColor(sf::Color::Black);
	m_square.setPosition(m_x * 90, m_y * 90);

	m_position.x = m_x * 90;
	m_position.y = m_y * 90;

	m_type = 1;
}


//
void Tile::render(sf::RenderWindow& window)
{
	window.draw(m_square);

}

//
int Tile::getType()
{
	return m_type;
}

//
sf::Vector2f Tile::getPosition()
{
	return m_position;
}

//
sf::Vector2f Tile::getWorldPosition()
{
	return sf::Vector2f(m_position.x * 29, m_position.y * 29);
}

//
sf::RectangleShape Tile::getRect()
{
	return m_square;
}

//
void Tile::setColour()
{
	//
	if (m_type < 0)
	{
		m_type = 0;
	}
	//
	else if (m_type > 9)
	{
		m_type = 9;
	}

	//
	if (m_type == 0)
	{
		m_square.setFillColor(sf::Color(250, 250, 250, 125));
	}
	//
	else if (m_type == 1)
	{
		m_square.setFillColor(sf::Color::Green);

	}
	//
	else if (m_type == 2)
	{
		m_square.setFillColor(sf::Color::Red);
		m_value = 0;
	}
	//
	else if (m_type == 3)
	{
		m_square.setFillColor(sf::Color::Black);
		m_value = 999;
	}
	//
	else if (m_type == 4)
	{
		m_square.setFillColor(sf::Color::Yellow);
	}

	//
	else if (m_type == 9)
	{
		m_square.setFillColor(sf::Color(250, 250, 250, 80));
	}
}

//
void Tile::setType(int type)
{
	m_type = type;
	setColour();
}

//
void Tile::setValue(int value)
{
	m_value = value;
}