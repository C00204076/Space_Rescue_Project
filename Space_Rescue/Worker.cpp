#include "Worker.h"

Worker::Worker()
{
	m_position = sf::Vector2f(900, 900.0);
	m_velocity = sf::Vector2f(1.0f, 0);

	//m_center = m_coneOfVision.getPosition();
	m_body.setOrigin(sf::Vector2f(30.0f, 30.0f));
	m_body.setRadius(30);
	m_body.setPosition(m_position);
}

Worker::~Worker()
{

}

void Worker::update(sf::Time deltaTime)
{
	movement();
}

void Worker::movement()
{
	m_position += m_velocity;

	if (m_position.x > 1200 || m_position.x < 0)
	{
		m_velocity.x = m_velocity.x * -1;
	}

	m_body.setPosition(m_position);
}

void Worker::render(sf::RenderWindow& window)
{
	window.draw(m_body);
}

//float Worker::steer()
//{
//
//}
//
//float Worker::distance()
//{
//
//}
float Worker::angle(sf::Vector2f t_position, sf::Vector2f t_targetPosition)
{
	return atan2(t_targetPosition.y - t_position.y, t_targetPosition.x - t_position.x);
}