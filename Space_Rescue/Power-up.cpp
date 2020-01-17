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

/// <summary>
/// PowerUP default constructor
/// </summary>
PowerUp::PowerUp()
{
	initialise();
}

/// <summary>
/// PowerUp's deault destructor
/// </summary>
PowerUp::~PowerUp()
{
	delete this;
}

/// <summary>
/// Initailisor used to initialise and set the default values of the
/// PowerUp Object's vairables
/// </summary>
void PowerUp::initialise()
{
	loadTexture();
	
	m_activeTime = 250;
	m_animaTime = 0;
	m_respawnTime = 0;
	m_type = 2;
	m_randX = 0;
	m_randY = 0;
	
	m_position = sf::Vector2f(400, 500);
	
	m_sprite.setTexture(m_textureOne);
	m_sprite.setOrigin(m_sprite.getTexture()->getSize().x / 2, 
					   m_sprite.getTexture()->getSize().y / 2);
	m_sprite.setPosition(m_position);
	
	m_active = true;
}

/// <summary>
/// Method used for loading the PowerUp's textures
/// </summary>
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

/// <summary>
/// Method used to respawn the PowerUp, reposition it and change it's
// type 
/// </summary>
/// <param name="tilemap"></param>
void PowerUp::spawnPowerUp(TileMap* tilemap)
{
	m_respawnTime++;
	
	if (m_active == false && m_respawnTime > 500)
	{
		// Randomly generates the i and j values of the
		// Array of Tile Objects within the TileMap Object
		m_randX = rand() % 28 - 1;
		m_randY = rand() % 28 - 1;
		// If the randomly picked Tile Object's m_type is equal to 0...
		if (tilemap->getTiles(m_randX, m_randY)->getType() == 0)
		{
			// ...then set the PowerUp Objects position to that tile
			m_position = tilemap->getTiles(m_randX, m_randY)->getPosition();
			m_sprite.setPosition(m_position);
		}

		m_active = true;
		m_respawnTime = 0;
		m_activeTime = 250;
		m_type += 1;

		if (m_type > 2)
		{
			m_type = 1;
		}
	}
}

/// <summary>
/// Method used to despawn and animate the PowerUp Object within
/// a certain amount of time
/// </summary>
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

/// <summary>
/// Updates a set of variables used to animate and indicate when
/// the PowerUp is going to despawn/disappear from the Game World
/// </summary>
void PowerUp::animatePowerUp()
{
	m_animaTime++;
	
	if (m_animaTime < 5)
	{
		m_sprite.setColor(sf::Color::White);
	}
	
	else if (m_animaTime > 5 && m_animaTime < 10)
	{
		m_sprite.setColor(sf::Color::Transparent);
	}
	
	else if (m_animaTime > 10)
	{
		m_animaTime = 0;
	}
}

/// <summary>
/// Updates the methods and variables of the PowerUp Object
/// </summary>
void PowerUp::update(sf::Time deltaTime)
{
	//
	if (m_type == 1)
	{
		m_sprite.setTexture(m_textureOne);
	}
	else if (m_type == 2)
	{
		m_sprite.setTexture(m_textureTwo);
	}
	//
	if (m_active == true)
	{
		powerUpLifeTime();
	}
}

/// <summary>
/// Updates the methods and variables of the PowerUp Object,
/// within the MiniMap Object
/// </summary>
/// <param name="deltaTime"></param>
/// <param name="tilemap"></param>
void PowerUp::update(sf::Time deltaTime, TileMap* tilemap)
{
	
	spawnPowerUp(tilemap);
	
	if (m_type == 1)
	{
		m_sprite.setTexture(m_textureOne);
	}
	else if (m_type == 2)
	{
		m_sprite.setTexture(m_textureTwo);
	}
	
	if (m_active == true)
	{
		powerUpLifeTime();
	}
}

/// <summary>
/// Renders and draws the PowerUp Object
/// </summary>
/// <param name="window"></param>
void PowerUp::render(sf::RenderWindow& window)
{
	if (m_active == true)
	{
		window.draw(m_sprite);
	}
}

/// <summary>
/// Renders and draws the PowerUp Object and scales it within
/// the MiniMap Object
/// </summary>
/// <param name="window"></param>
/// <param name="scale"></param>
void PowerUp::render(sf::RenderWindow& window, sf::Vector2f scale)
{
	if (m_active == true)
	{
		
		m_sprite.setScale(scale);
		
		window.draw(m_sprite);
	}
}

//Set Methods
/// <summary>
/// Sets the texture type of the PowerUp Object using m_type
/// </summary>
/// <param name="type"></param>
void PowerUp::setType(int type)
{
	// If m_type is 1 set texture to the damage-resist power-up 
	if (type == 1)
	{
		m_type = 1;
		m_sprite.setTexture(m_textureOne);
	}
	// If m_type is 2 set texture to speed power-up
	else if (type == 2)
	{
		m_type = 2;
		m_sprite.setTexture(m_textureTwo);
	}
}

/// <summary>
/// Sets the value of m_active with the given arguement
/// </summary>
/// <param name="active"></param>
void PowerUp::setActive(bool active)
{
	m_active = active;
}

/// <summary>
/// Sets the value of m_position with the given arguement
/// </summary>
/// <param name="position"></param>
void PowerUp::setPosition(sf::Vector2f position)
{
	m_position = position;
	m_sprite.setPosition(position);
}

/// <summary>
/// Sets the value of m_activeTime with the given arguement
/// </summary>
/// <param name="lifeTime"></param>
void PowerUp::setActiveTime(int lifeTime)
{
	m_activeTime = lifeTime;
}
//

// Get Methods
/// <summary>
/// Return the value of m_type
/// </summary>
int PowerUp::getType()
{
	return m_type;
}

/// <summary>
/// Return the value of m_active
/// </summary>
bool PowerUp::getActive()
{
	return m_active;
}

/// <summary>
/// Return the values of m_position
/// </summary>
sf::Vector2f PowerUp::getPosition()
{
	return m_position;
}

/// <summary>
/// Return the value of m_sprite
/// </summary>
sf::Sprite PowerUp::getSprite()
{
	return m_sprite;
}
//