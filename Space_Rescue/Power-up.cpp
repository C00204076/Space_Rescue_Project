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
	//
	m_activeTime = 250;
	m_animaTime = 0;
	m_respawnTime = 0;
	m_type = 1;
	//
	m_position = sf::Vector2f(400, 500);
	//
	m_sprite.setTexture(m_textureOne);
	m_sprite.setOrigin(m_sprite.getTexture()->getSize().x / 2, 
					   m_sprite.getTexture()->getSize().y / 2);
	m_sprite.setPosition(m_position);
	//
	m_active = true;
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
void PowerUp::spawnPowerUp()
{
	//
	m_respawnTime++;
	//
	if (m_active == false && m_respawnTime > 500)
	{
		m_active = true;
		m_respawnTime = 0;
		m_activeTime = 250;
	}
}

//
void PowerUp::powerUpLifeTime()
{
	//
	m_activeTime--;

	//
	if (m_activeTime < 0)
	{
		m_active = false;
	}
	//
	else if (m_activeTime < 100)
	{
		animatePowerUp();
	}
}

//
void PowerUp::animatePowerUp()
{
	//
	m_animaTime++;

	//
	if (m_animaTime < 5)
	{
		m_sprite.setColor(sf::Color::White);
	}
	//
	else if (m_animaTime > 5 && m_animaTime < 10)
	{
		m_sprite.setColor(sf::Color::Transparent);
	}
	//
	else if (m_animaTime > 10)
	{
		m_animaTime = 0;
	}
}

//
void PowerUp::update(sf::Time deltaTime)
{
	//
	spawnPowerUp();
	//
	if (m_active == true)
	{
		powerUpLifeTime();
	}
}

//
void PowerUp::render(sf::RenderWindow& window)
{
	//
	if (m_active == true)
	{
		window.draw(m_sprite);
	}
}

//
void PowerUp::render(sf::RenderWindow& window, sf::Vector2f scale)
{
	//
	if (m_active == true)
	{
		//
		m_sprite.setScale(scale);
		//
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
void PowerUp::setPosition(sf::Vector2f position)
{
	m_position = position;
	m_sprite.setPosition(position);
}

//
void PowerUp::setActiveTime(int lifeTime)
{
	m_activeTime = lifeTime;
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
sf::Vector2f PowerUp::getPosition()
{
	return m_position;
}
//