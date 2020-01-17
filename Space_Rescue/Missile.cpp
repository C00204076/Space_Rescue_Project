//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 17:03 14 January 2019
// Finished at
// Time taken:
// Known bugs:

#include "Missile.h"

/// <summary>
/// 
/// </summary>
/// <param name="isPlayer"></param>
/// <param name="isNest"></param>
Missile::Missile(bool isPlayer, bool isNest) :
	m_isPlayer(isPlayer),
	m_isNest(isNest)
{
	initialise();
}

/// <summary>
/// 
/// </summary>
Missile::~Missile()
{
	//delete this;
}

/// <summary>
/// 
/// </summary>
void Missile::initialise()
{
	loadTexture();
	//
	if (m_isPlayer == true)
	{
		m_sprite.setTexture(m_textureOne);
	}
	//
	else if (m_isNest == true)
	{
		m_sprite.setTexture(m_textureTwo);
	}
	//
	m_sprite.setOrigin(m_sprite.getTexture()->getSize().x / 2, 
					   m_sprite.getTexture()->getSize().y / 2);
	m_sprite.setPosition(m_position);
	m_sprite.setRotation(0);
	//
	m_velocity = sf::Vector2f(30.0f, 30.0f);
	//
	m_lifeTime = 200;
	//
	m_active = false;
}

/// <summary>
/// 
/// </summary>
void Missile::loadTexture()
{
	//
	if (!m_textureOne.loadFromFile("../Space_Rescue/ASSETS/TEXTURES/PlayerMissile.png"))
	{
		std::cout << "Error! Unable to load /ASSETS/TEXTURES/Invulnerability.png from game files!" << std::endl;
	}

	//
	if (!m_textureTwo.loadFromFile("../Space_Rescue/ASSETS/TEXTURES/NestMissile.png"))
	{
		std::cout << "Error! Unable to load /ASSETS/TEXTURES/Speed.png from game files!" << std::endl;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="deltaTime"></param>
void Missile::update(sf::Time deltaTime)
{
	//
	if (m_active == true)
	{		
		m_lifeTime--;

		m_position.x += (sin(m_sprite.getRotation() * (3.14159265 / 180)) * m_velocity.y);
		m_position.y += (-cos(m_sprite.getRotation() * (3.14159265 / 180)) * m_velocity.y);
		m_sprite.setPosition(m_position);

		if (m_lifeTime < 0)
		{
			m_active = false;
		}

	}
}

/// <summary>
/// 
/// </summary>
/// <param name="window"></param>
void Missile::render(sf::RenderWindow& window)
{
	//
	if (m_active == true)
	{
		window.draw(m_sprite);
	}
}

/// <summary>
/// Set rotation of Missile, when it is fired from the Player
/// <summary>
/// <param name="player"></param>
void Missile::setRotation(Player* player)
{
	if (m_active == false)
	{
		m_sprite.setRotation(player->getSprite().getRotation());
	}
}

/// <summary>
/// Set rotation of Missile, when it is fired at the Player
/// <summary>
/// <param name="player"></param>
void Missile::setMissileRotation(Player* player)
{
	if (m_active == false)
	{
		float adjacent = m_position.x - player->getSprite().getPosition().x;
		float opposite = player->getSprite().getPosition().y - m_position.y;

		if (opposite == 0)
		{
			opposite++;
		}
		if (adjacent == 0)
		{
			adjacent++;
		}


		float angle = atan(adjacent / opposite) * 180 / 3.142;

		if (opposite > 0)
		{
			angle += 180;
		}

		m_sprite.setRotation(angle);
	}
}


/// <summary>
/// 
/// </summary>
sf::Vector2f Missile::getPosition()
{
	return m_position;
}
/// <summary>
/// 
/// </summary>
/// <param name="position"></param>
void Missile::setPosition(sf::Vector2f position)
{
	m_position = position;
	m_sprite.setPosition(position);
}

/// <summary>
/// 
/// </summary>
sf::Sprite Missile::getSprite()
{
	return m_sprite;
}

/// <summary>
/// 
/// </summary>
/// <param name="isPlayer"></param>
void Missile::setIsPlayer(bool isPlayer)
{
	m_isPlayer = isPlayer;
}
/// <summary>
/// 
/// </summary>
bool Missile::getIsPlayer()
{
	return m_isPlayer;
}

/// <summary>
/// 
/// </summary>
/// <param name="isNest"></param>
void Missile::setIsNest(bool isNest)
{
	m_isNest = isNest;
}
/// <summary>
/// 
/// </summary>
bool Missile::getIsNest()
{
	return m_isNest;
}

/// <summary>
/// 
/// </summary>
/// <param name="active"></param>
void Missile::setActive(bool active)
{
	m_active = active;
}
/// <summary>
/// 
/// </summary>
bool Missile::getActive()
{
	return m_active;
}

/// <summary>
/// 
/// </summary>
/// <param name="lifeTime"></param>
void Missile::setLifeTime(int lifeTime)
{
	m_lifeTime = lifeTime;
}