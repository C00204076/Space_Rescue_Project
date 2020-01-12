//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 12:30 7 January 2019
// Finished at
// Time taken:
// Known bugs:

#include "Player.h"

//
Player::Player()
{
	initalise();
}

//
Player::~Player()
{
	delete this;
}

//
void Player::initalise()
{
	loadTexture();

	//
	m_maxSpeed = 16;
	m_addedSpeed = 0.0f;
	m_position = sf::Vector2f(500, 400);
	//
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(25, 25);
	m_sprite.setPosition(m_position);
	m_sprite.setRotation(0);

	//
	m_immune = false;
	m_speed = false;
}

//
void Player::loadTexture()
{
	if (!m_texture.loadFromFile("../Space_Rescue/ASSETS/TEXTURES/MrBlock.png"))
	{
		std::cout << "Error! Unable to load /ASSETS/TEXTURES/MrBlock.png from game files!" << std::endl;
	}
}

//
void Player::move()
{
	//
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_sprite.rotate(-2.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_sprite.rotate(2.0f);
	}

	//
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		//
		if (m_velocity.y < m_maxSpeed)
		{
			m_velocity.x += 0.1f + m_addedSpeed;
			m_velocity.y += 0.1f + m_addedSpeed;
		}
	}
	//
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//
		if (m_velocity.y > 0.0f)
		{
			m_velocity.x -= 0.1f + m_addedSpeed;
			m_velocity.y -= 0.1f + m_addedSpeed;
		}
	}


	if (m_maxSpeed > 0.0f)
	{
		m_position.x += (sin(m_sprite.getRotation() * (3.14159265 / 180)) * m_velocity.y);
		m_position.y += (-cos(m_sprite.getRotation() * (3.14159265 / 180)) * m_velocity.y);
		m_sprite.setPosition(m_position);
	}
}

//
void Player::powerup()
{
	//
	if (m_speed == true)
	{
		m_addedSpeed = 0.3f;
	}
	//
	else if (m_speed == false)
	{
		m_addedSpeed = 0.0f;
	}

	//
	if (m_immune == true)
	{

	}
	else if (m_immune == false)
	{

	}
}

//
void Player::update(sf::Time deltaTime, sf::View &v)
{
	//
	move();
	//
	powerup();
	//
	v.setCenter(m_position.x, m_position.y);
}

//
void Player::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

//
void Player::render(sf::RenderWindow& window, sf::Vector2f scale)
{
	//
	m_sprite.setScale(scale);
	//
	window.draw(m_sprite);
}

//
sf::Vector2f Player::getPosition()
{
	return m_position;
}
//
void Player::setPosition(sf::Vector2f position)
{
	m_position = position;
	m_sprite.setPosition(position);
}

//
sf::Sprite Player::getSprite()
{
	return m_sprite;
}

//
sf::Vector2f Player::getVelocity()
{
	return m_velocity;
}

//
bool Player::getImmune()
{
	return m_immune;
}
//
void Player::setImmune(bool immune)
{
	m_immune = immune;
}

//
bool Player::getSpeed()
{
	return m_speed;
}
//
void Player::setSpeed(bool speed)
{
	m_speed = speed;
}