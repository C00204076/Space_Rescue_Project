//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 10:59 10 January 2019
// Finished at
// Time taken:
// Known bugs:

#include "Power-up.h"

//
PowerUp::PowerUp()
{
	initialise();
}

//
PowerUp::~PowerUp()
{
	delete this;
}

//
void PowerUp::initialise()
{
	loadTexture();
}

// 
void PowerUp::loadTexture()
{
	//
	if (!m_textureOne.loadFromFile("../Space_Rescue/ASSETS/TEXTURES/Invulnerability.png"))
	{
		std::cout << "Error! Unable to load /ASSETS/TEXTURES/Invulnerability.png from game files!" << std::endl;
	}

	//
	if (!m_textureTwo.loadFromFile("../Space_Rescue/ASSETS/TEXTURES/Speed.png"))
	{
		std::cout << "Error! Unable to load /ASSETS/TEXTURES/Speed.png from game files!" << std::endl;
	}
}

//
void PowerUp::update(sf::Time deltaTime)
{
	if (m_active == true)
	{

	}
}

//
void PowerUp::render(sf::RenderWindow& window)
{
	if (m_active == true)
	{
		window.draw(m_sprite);
	}
}

//Set Methods
//
void PowerUp::setType(int type)
{
	//
	if (type == 1)
	{
		m_type = 1;
		m_sprite.setTexture(m_textureOne);
	}
	//
	else if (type == 2)
	{
		m_type = 2;
		m_sprite.setTexture(m_textureTwo);
	}
}

//
void PowerUp::setActive(bool active)
{
	m_active = active;
}
//

// Get Methods
//
int PowerUp::getType()
{
	return m_type;
}

//
bool PowerUp::getActive()
{
	return m_active;
}
//