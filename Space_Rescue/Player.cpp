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
	m_bullet = new Missile(true, false);

	//
	m_hp = 3;
	m_iFrameTime = 0;
	m_animateTime = 0;
	m_maxSpeed = 8;
	m_addedSpeed = 0.0f;
	m_fireDelay = 0;
	m_position = sf::Vector2f(500, 400);
	m_powerupTime = 0;
	m_powerupAnimate = 0;
	//
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(25, 25);
	m_sprite.setPosition(m_position);
	m_sprite.setRotation(0);
	//
	m_powerupSprite.setTexture(m_powerupTexture);
	m_powerupSprite.setOrigin(25, 25);
	m_powerupSprite.setPosition(m_position);
	m_powerupSprite.setRotation(0);
	//
	m_center = m_position;
	//
	m_immune = false;
	m_speed = false;
	m_hit = false;
}

//
void Player::loadTexture()
{
	if (!m_texture.loadFromFile("../Space_Rescue/ASSETS/TEXTURES/MrBlock.png"))
	{
		std::cout << "Error! Unable to load /ASSETS/TEXTURES/MrBlock.png from game files!" << std::endl;
	}

	if (!m_powerupTexture.loadFromFile("../Space_Rescue/ASSETS/TEXTURES/Powered.png"))
	{
		std::cout << "Error! Unable to load /ASSETS/TEXTURES/Powered.png from game files!" << std::endl;
	}
}

//
void Player::move()
{
	//
	if (m_collide == false)
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
			//
			m_powerupSprite.setPosition(m_position);
			m_powerupSprite.setRotation(m_sprite.getRotation());
		}
	}

}

//
void Player::powerup()
{
	//
	if (m_speed == true)
	{
		m_powerupSprite.setColor(sf::Color(255, 255, 0, 125));
		m_addedSpeed = 0.3f;
		m_powerupTime++;
	}
	//
	else if (m_speed == false)
	{
		m_powerupSprite.setColor(sf::Color::Transparent);
		m_addedSpeed = 0.0f;
		m_powerupTime++;
	}

	//
	else if (m_immune == true)
	{
		m_powerupSprite.setColor(sf::Color(255, 0, 0, 125));
	}
	else if (m_immune == false)
	{
		m_powerupSprite.setColor(sf::Color::Transparent);
	}

	//
	if (m_powerupTime > 250)
	{
		m_powerupAnimate++;

		//
		if (m_powerupAnimate < 5)
		{
			//
			if (m_speed == true)
			{
				m_powerupSprite.setColor(sf::Color(25, 25, 0, 255));
			}
			//
			else if (m_immune == true)
			{
				m_powerupSprite.setColor(sf::Color(25, 0, 0, 255));
			}
		}
		//
		else if (m_powerupAnimate > 5 && m_powerupAnimate < 10)
		{
			m_powerupSprite.setColor(sf::Color::Transparent);
		}
		//
		else if (m_powerupAnimate > 10)
		{
			m_powerupAnimate = 0;
		}
	}

	//
	if (m_powerupTime >= 320)
	{
		m_speed = false;
		m_immune = false;
		m_powerupTime = 0;
		m_powerupAnimate = 0;
	}
}

//
void Player::iFrames()
{
	if (m_hit == true && m_hp > 0)
	{
		m_iFrameTime++;
		m_animateTime++;

		if (m_iFrameTime == 250)
		{
			m_hit = false;
			m_animateTime = 0;
			m_iFrameTime = 0;
		}

		//
		if (m_animateTime < 5)
		{
			m_sprite.setColor(sf::Color::White);
		}
		//
		else if (m_animateTime > 5 && m_animateTime < 10)
		{
			m_sprite.setColor(sf::Color::Transparent);
		}
		//
		else if (m_animateTime > 10)
		{
			m_animateTime = 0;
		}
	}
}

//
void Player::fire()
{
	//
	if (m_fireDelay > 0)
	{
		m_fireDelay--;
	}

	//
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_fireDelay <= 0)
	{
		if (m_bullet->getActive() == false)
		{
			//m_bullet = new Missile(true, false);
			m_fireDelay = 150;
			m_bullet->setPosition(m_position);
			m_bullet->setRotation(this);
			m_bullet->setActive(true);
			m_bullet->setLifeTime(200);
		}
	}
}

void Player::tileCollision(TileMap* tilemap)
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (m_position.x < tilemap->getTiles(1, 1)->getPosition().x + tilemap->getTiles(1, 1)->getRect().getSize().x &&
				m_position.x + 25 > tilemap->getTiles(1, 1)->getPosition().x&&
				m_position.y < tilemap->getTiles(1, 1)->getPosition().y + tilemap->getTiles(1, 1)->getRect().getSize().y &&
				m_position.y + 25 > tilemap->getTiles(1, 1)->getPosition().y)
			{
				m_collide = true;

			}

			else
			{
				m_collide = false;

				m_velocity.x *= -1;
				m_velocity.y *= -1;
			}
		}
	}
}

//
void Player::collision()
{
	if (m_collide == true)
	{
		/*if (m_velocity.x > 0)
		{
			m_velocity.x--;
		}
		else
		{
			m_velocity.x++;
		}

		if (m_velocity.y > 0)
		{
			m_velocity.y--;
		}
		else
		{
			m_velocity.y++;
		}*/

		/*m_position.x -= (sin(m_sprite.getRotation() * (3.14159265 / 180)) * m_velocity.y);
		m_position.y -= (-cos(m_sprite.getRotation() * (3.14159265 / 180)) * m_velocity.y);
		m_sprite.setPosition(m_position);*/

		
		
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
	iFrames();
	//
	fire();
	m_bullet->update(deltaTime);
	//
	v.setCenter(m_position.x, m_position.y);

	m_center = m_position;
}
/// <summary>
/// bullets[i]->~bullet();
/// bullets[i] = nullptr;
/// bullets.erase(bullets.begin() + i);
/// i--;
/// </summary>


//
void Player::render(sf::RenderWindow& window)
{
	m_bullet->render(window);

	window.draw(m_sprite);
	window.draw(m_powerupSprite);
}

//
void Player::render(sf::RenderWindow& window, sf::Vector2f scale)
{
	//
	m_sprite.setScale(scale);
	//
	window.draw(m_sprite);
	window.draw(&m_center,1,sf::Points);
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

//
bool Player::getCollide()
{
	return m_collide;
}
//
void Player::setCollide(bool collide)
{
	m_collide = collide;
}

//
bool Player::getHit()
{
	return m_hit;
}
//
void Player::setHit(bool hit)
{
	m_hit = hit;
}

//
int Player::getHP()
{
	return m_hp;
}
//
void Player::setHP(int hp)
{
	m_hp = hp;
}

//
void Player::setFireDelay(int fireDelay)
{
	m_fireDelay = fireDelay;
}

//
Missile* Player::getMissile()
{
	return m_bullet;
}

//
int Player::getPowerUpTime()
{
	return m_powerupTime;
}
//
void Player::setPowerUpTime(int time)
{
	m_powerupTime = time;
}