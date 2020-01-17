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

/// <summary>
/// Tile's base constructor
/// </summary>
Tile::Tile()
{
	//initialise();
}

/// <summary>
/// Tile default constructor
/// </summary>
/// <param name="type"></param>
/// <param name="gridX"></param>
/// <param name="gridY"></param>
Tile::Tile(int type, int gridX, int gridY) :
	m_type(type),
	m_x(gridX),
	m_y(gridY)
{
	initialise();
}

/// <summary>
/// Tile's default desstructor
/// </summary>
Tile::~Tile()
{
	delete this;
}

/// <summary>
/// Initialisor of the Tile Object's default variable values
/// </summary>
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


/// <summary>
/// Method used to render and draw the Tile Object
/// </summary>
/// <param name="window"></param>
void Tile::render(sf::RenderWindow& window)
{
	window.draw(m_square);

}

/// <summary>
/// Method used to return the value m_type
/// </summary>
int Tile::getType()
{
	return m_type;
}

/// <summary>
/// Method used to return the value of m_position
/// </summary>
sf::Vector2f Tile::getPosition()
{
	return m_position;
}

/// <summary>
/// Method used to return the values of m_position multiplied by 29,
/// giving it's World Position
/// </summary>
sf::Vector2f Tile::getWorldPosition()
{
	return sf::Vector2f(m_position.x * 29, m_position.y * 29);
}

/// <summary>
/// Method used to return the value of m_square
/// </summary>
sf::RectangleShape Tile::getRect()
{
	return m_square;
}

/// <summary>
/// Method used to set the colour and value of the Tile Object 
/// based on the value of m_type
/// </summary>
void Tile::setColour()
{
	// If m_type is less than 0, it is set back to 0
	if (m_type < 0)
	{
		m_type = 0;
	}
	// If m_type is greater than 9, it is set back to 9
	else if (m_type > 9)
	{
		m_type = 9;
	}

	// If m_type is 0, set colour to a Faded Grayish-White
	if (m_type == 0)
	{
		m_square.setFillColor(sf::Color(250, 250, 250, 125));
	}
	// If m_type is 1, set colour to a Green
	else if (m_type == 1)
	{
		m_square.setFillColor(sf::Color::Green);

	}
	// If m_type is 2, set colour to a Red
	else if (m_type == 2)
	{
		m_square.setFillColor(sf::Color::Red);
		m_value = 0;
	}
	// If m_type is 3, set colour to a Black and it's value to 999
	else if (m_type == 3)
	{
		m_square.setFillColor(sf::Color::Black);
		m_value = 999;
	}
	// If m_type is 4, set colour to a Yellow
	else if (m_type == 4)
	{
		m_square.setFillColor(sf::Color::Yellow);
	}

	// If m_type is 1, set colour to a Dark Gray
	else if (m_type == 9)
	{
		m_square.setFillColor(sf::Color(250, 250, 250, 80));
	}
}

/// <summary>
/// Method used to set the value of m_type using the given arguement
/// </summary>
/// <param name="type"></param>
void Tile::setType(int type)
{
	m_type = type;
	setColour();
}

/// <summary>
///  Method used to set the value of m_value using the given arguement
/// </summary>
/// <param name="value"></param>
void Tile::setValue(int value)
{
	m_value = value;
}