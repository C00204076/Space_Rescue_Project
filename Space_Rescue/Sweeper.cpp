#include "Sweeper.h"

Sweeper::Sweeper()
{
	m_coneOfVision.setOrigin(sf::Vector2f(100.0, 0));
	m_coneOfVision.setPointCount(3);
	m_coneOfVision.setRadius(100);
	m_coneOfVision.setPosition(sf::Vector2f(100, 100));
	m_visionOrigin = m_coneOfVision.getPosition();
	m_visionOrigin.x += 100;


	m_coneOfVisionLength = sqrt(
		pow(m_coneOfVision.getPoint(0).x - m_coneOfVision.getPoint(1).x, 2) +
		pow(m_coneOfVision.getPoint(0).y - m_coneOfVision.getPoint(1).y, 2));

	m_coneRelativePos;
	m_visionOriginRelative;
}

Sweeper::~Sweeper()
{

}

void Sweeper::update(sf::Time deltaTime)
{
	m_coneOfVision.rotate(0.5);

	if (m_coneOfVision.getRotation() > 360)
	{
		m_coneOfVision.setRotation(0);
	}
	else if (m_coneOfVision.getRotation() < 0)
	{
		m_coneOfVision.setRotation(360);
	}
	//std::cout << m_coneOfVision.getRotation() << std::endl;
}

void Sweeper::detection(sf::Vector2f t_playerPos)
{
	//std::cout << sqrt(pow(m_visionOrigin.x - t_playerPos.x, 2) + pow(m_visionOrigin.y - t_playerPos.y, 2)) << std::endl;
	//std::cout << sqrt(pow(m_coneOfVision.getPoint(0).x - m_coneOfVision.getPoint(1).x, 2) + pow(m_coneOfVision.getPoint(0).y - m_coneOfVision.getPoint(1).y, 2)) << std::endl;
	bool detect = false;
	if ((sqrt(pow(m_coneOfVision.getPosition().x - t_playerPos.x, 2) + pow(m_coneOfVision.getPosition().y - t_playerPos.y, 2))) - 25 < m_coneOfVisionLength)
	{
		m_detectionPoints[0] = t_playerPos;
		m_angles[0] = atan2(t_playerPos.x - m_coneOfVision.getPosition().x, t_playerPos.y - m_coneOfVision.getPosition().y) * (180.0 / (22.0 / 7.0)) * -1;
		m_points[0] = m_detectionPoints[0];

		for (int i = 1; i < 6; i++)
		{
			m_detectionPoints[i] = t_playerPos +
				sf::Vector2f(-
					25 * cos(atan2(t_playerPos.x - m_coneOfVision.getPosition().x, t_playerPos.y - m_coneOfVision.getPosition().y) - (45 * (i - 1)) * ((22.0 / 7.0) / 180.0))
					, 25 * sin(atan2(t_playerPos.x - m_coneOfVision.getPosition().x, t_playerPos.y - m_coneOfVision.getPosition().y) - (45 * (i - 1)) * ((22.0 / 7.0) / 180.0)));

			m_angles[i] = atan2(m_detectionPoints[i].x - m_coneOfVision.getPosition().x, m_detectionPoints[i].y - m_coneOfVision.getPosition().y) * (180.0 / (22.0 / 7.0)) * -1;
			m_points[i] = m_detectionPoints[i];
		}

		//std::cout << m_angle << std::endl;

		float leftSide = -30.0f + m_coneOfVision.getRotation();
		if (leftSide > 180)
		{
			leftSide -= 360.0;
		}

		float rightSide = 30.0f + m_coneOfVision.getRotation();

		if (rightSide > 180)
		{
			rightSide -= 360.0;
		}

		for (int i = 0; i < 6; i++)
		{
			if ((m_angles[i] > leftSide && m_angles[i] < rightSide)
				||
				(leftSide > 120 && m_angles[i] > 120) && (m_angles[i] > leftSide && m_angles[i] - 360 < rightSide)
				||
				(rightSide < -120 && m_angles[i] < -120) && (m_angles[i] + 360 > leftSide && m_angles[i] < rightSide))
			{
				detect = true;
			}
		}
	}

	if (detect == true)
	{
		m_coneOfVision.setFillColor(sf::Color::Red);
	}
	else
	{
		m_coneOfVision.setFillColor(sf::Color::Green);
	}
}

void Sweeper::render(sf::RenderWindow& window)
{
	//window.draw(m_rect);
	window.draw(m_coneOfVision);
	for (int i = 0; i < 6; i++)
	{
		window.draw(&m_points[i], 1, sf::Points);
	}
}