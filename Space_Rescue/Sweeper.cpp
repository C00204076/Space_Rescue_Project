#include "Sweeper.h"

Sweeper::Sweeper(TileMap* t_map) :
	m_map(t_map)
{
	m_position = sf::Vector2f(200, 100.0);

	m_coneOfVision.setOrigin(sf::Vector2f(100.0, 000.0));
	m_coneOfVision.setPointCount(3);
	m_coneOfVision.setRadius(100);
	m_coneOfVision.setPosition(m_position);

	//m_center = m_coneOfVision.getPosition();
	m_body.setOrigin(sf::Vector2f(30.0f, 30.0f));
	m_body.setRadius(30);
	m_body.setPosition(m_position);
	m_body.setFillColor(sf::Color::Green);

	m_currentAngle = 0;

	m_speed = 1;
	m_baseSpeed = 1;
	m_detect = false;

	m_coneOfVisionLength = sqrt(
		pow(m_coneOfVision.getPoint(0).x - m_coneOfVision.getPoint(1).x, 2) +
		pow(m_coneOfVision.getPoint(0).y - m_coneOfVision.getPoint(1).y, 2));

	m_target = sf::Vector2i(-1, -1);

	m_path = m_map->createPath(m_position, m_target, true);
}

Sweeper::~Sweeper()
{

}

void Sweeper::update(sf::Time deltaTime, sf::Vector2f t_playerPos, sf::Vector2f t_playerVel)
{
	//m_position.x += 1.0f;
	if (m_detect)
	{
		pursue(t_playerPos, t_playerVel);
	}
	else
	{
		wander();
	}
	movement();

	m_currentAngle = steer();
	m_coneOfVision.setRotation(m_currentAngle * (180.0 / (22.0 / 7.0)));
	m_coneOfVision.setPosition(m_position);
	m_body.setPosition(m_position);
}

void Sweeper::movement()
{
	m_position += m_velocity;
}

void Sweeper::detection(sf::Vector2f t_playerPos)
{
	if ((sqrt(pow(m_coneOfVision.getPosition().x - t_playerPos.x, 2) + pow(m_coneOfVision.getPosition().y - t_playerPos.y, 2))) - 25 < m_coneOfVisionLength)
	{
		m_detectionPoints[0] = t_playerPos;
		m_angles[0] = angle(t_playerPos, m_coneOfVision.getPosition()) * (180.0 / (22.0 / 7.0));

		//angle(t_playerPos, m_coneOfVision.getPosition());
		m_points[0] = m_detectionPoints[0];
		m_angleToTarget = m_angles[0];

		for (int i = 1; i < 6; i++)
		{
			m_detectionPoints[i] = t_playerPos +
				sf::Vector2f(
					25 * cos(angle(t_playerPos, m_coneOfVision.getPosition()) + (45 * (i - 1) - 90) * ((22.0 / 7.0) / 180.0))
					, 25 * sin(angle(t_playerPos, m_coneOfVision.getPosition()) + (45 * (i - 1) - 90) * ((22.0 / 7.0) / 180.0)));

			m_angles[i] = angle(m_detectionPoints[i], m_coneOfVision.getPosition()) * (180.0 / (22.0 / 7.0));
			m_points[i] = m_detectionPoints[i];
		}

		//std::cout << m_angles[0] << std::endl;

		float leftSide = -30.0f + m_coneOfVision.getRotation() - 90;
		if (leftSide > 180)
		{
			leftSide -= 360.0;
		}

		float rightSide = 30.0f + m_coneOfVision.getRotation() - 90;
		if (rightSide > 180)
		{
			rightSide -= 360.0;
		}

		//std::cout << "Left Side: "<< leftSide << " Right Side: " << rightSide << std::endl;

		for (int i = 0; i < 6; i++)
		{
			if ((m_angles[i] > leftSide&& m_angles[i] < rightSide)
				||
				(leftSide > 120 && m_angles[i] > 120) && (m_angles[i] > leftSide&& m_angles[i] - 360 < rightSide)
				||
				(rightSide < -120 && m_angles[i] < -120) && (m_angles[i] + 360 > leftSide&& m_angles[i] < rightSide))
			{
				m_detect = true;
			}
		}
	}

	if (m_detect == true)
	{
		m_coneOfVision.setFillColor(sf::Color::Red);
	}
	else
	{
		m_coneOfVision.setFillColor(sf::Color::Green);
	}
}

void Sweeper::pursue(sf::Vector2f t_playerPos, sf::Vector2f t_playerUnitVel)
{
	m_targetPosition = t_playerPos + sf::Vector2f(t_playerUnitVel.x * 20, t_playerUnitVel.y * 20);
	if (distance() < 10)
	{
		m_speed = m_baseSpeed;
		m_velocity = sf::Vector2f(0, 0);
	}
	else if (distance() > 1000)
	{
		m_detect = false;

		if (m_path.empty() == false)
		{
			m_path.clear();
		}
		m_path = m_map->createPath(m_position, m_target, true);
	}
	else
	{
		m_angleToTarget = angle(m_position, m_targetPosition);
		//m_eSprite.setRotation(m_angleToTarget * (180.0 / (22.0 / 7.0)));
		//m_coneOfVision.setRotation(m_angleToTarget * (180.0 / (22.0 / 7.0)) - 90);
		m_velocity = sf::Vector2f((cosf(m_angleToTarget)) * m_speed, (sinf(m_angleToTarget)) * m_speed);
	}

}

void Sweeper::wander()
{
	if (m_path.empty() == false)
	{
		m_targetPosition = sf::Vector2f(m_path.back()->getPosition().x + 45, m_path.back()->getPosition().y + 45);
		m_angleToTarget = angle(m_position, m_targetPosition);
		std::cout << m_angleToTarget << std::endl;
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

float Sweeper::steer()
{
	float m_currentAngleDegree = m_currentAngle * (180.0 / (22.0 / 7.0));
	float m_angleToTargetDegree = m_angles[0] + 90;

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

float Sweeper::distance()
{
	float distance = sqrt(pow((m_position.x - m_targetPosition.x), 2) + pow((m_position.y - m_targetPosition.y), 2));
	return distance;
}

float Sweeper::angle(sf::Vector2f t_position, sf::Vector2f t_targetPosition)
{
	return atan2(t_targetPosition.y - t_position.y, t_targetPosition.x - t_position.x);
}

void Sweeper::render(sf::RenderWindow& window)
{
	//window.draw(m_rect);
	window.draw(m_body);
}