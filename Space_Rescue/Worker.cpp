#include "Worker.h"

Worker::Worker(TileMap* t_map):
	m_map(t_map)
{
	m_position = m_map->getTile(14,14);
	m_velocity = sf::Vector2f(1.0f, 0);

	//m_center = m_coneOfVision.getPosition();
	m_body.setOrigin(sf::Vector2f(30.0f, 30.0f));
	m_body.setRadius(30);
	m_body.setPosition(m_position);
	m_body.setFillColor(sf::Color::Yellow);

	m_target = sf::Vector2i(-1, -1);
	m_speed = 1;
	m_path = m_map->createPath(m_position, m_target, true);
}

Worker::~Worker()
{

}

void Worker::update(sf::Time deltaTime)
{
	wander();
	movement();
}

void Worker::movement()
{
	m_position += m_velocity;
	m_body.setPosition(m_position);
}

void Worker::wander()
{
	if (m_path.empty() == false)
	{
		m_targetPosition = sf::Vector2f(m_path.back()->getPosition().x + 45, m_path.back()->getPosition().y + 45);
		m_angleToTarget = angle(m_position, m_targetPosition);

		//m_coneOfVision.setRotation(m_angleToTarget * (180.0 / (22.0 / 7.0)) - 90);
		m_velocity = sf::Vector2f((cosf(m_angleToTarget)) * m_speed, (sinf(m_angleToTarget)) * m_speed);

		if (distance() < 5 && m_path.size() != 1)
		{
			m_path = m_map->createPath(m_path.back()->getPosition(), m_target, false);
		}
		else if (distance() < 10 && m_path.size() == 1)
		{
			m_path.clear();
		}
	}
	else
	{
		m_path = m_map->createPath(m_position, m_target, true);
	}
}

void Worker::render(sf::RenderWindow& window)
{
	window.draw(m_body);
}

float Worker::steer()
{
	float m_currentAngleDegree = m_currentAngle * (180.0 / (22.0 / 7.0));
	float m_angleToTargetDegree = angle(m_path.back()->getPosition(),m_position) * 180.0 / (22.0 / 7,0);

	float m_increment = 1;
//The below situations are intended to steer the alien towards its target angle. Only works correctly for wander
//std::cout << m_currentAngleDegree << " " << m_angleToTargetDegree << std::endl;
	if (m_currentAngleDegree > m_angleToTargetDegree - 10 && m_currentAngleDegree < m_angleToTargetDegree + 10)
	{
		std::cout << "Found" << std::endl;
		m_currentAngleDegree = m_angleToTargetDegree;
	}
	else if (m_angleToTargetDegree - m_currentAngleDegree < m_currentAngleDegree - (m_angleToTargetDegree))
	{
		m_currentAngleDegree -= m_increment;
		if (m_currentAngleDegree > 180)
		{
			m_currentAngleDegree -= 360;
		}
	}
	else if (m_angleToTargetDegree - m_currentAngleDegree > m_currentAngleDegree - (m_angleToTargetDegree))
	{
		m_currentAngleDegree += m_increment;
		if (m_currentAngleDegree < -180)
		{
			m_currentAngleDegree += 360;
		}
	}

	return (m_currentAngleDegree * ((22.0 / 7.0) / 180.0));
}

float Worker::distance()
{
	float distance = sqrt(pow((m_position.x - m_targetPosition.x), 2) + pow((m_position.y - m_targetPosition.y), 2));
	return distance;
}
float Worker::angle(sf::Vector2f t_position, sf::Vector2f t_targetPosition)
{
	return atan2(t_targetPosition.y - t_position.y, t_targetPosition.x - t_position.x);
}