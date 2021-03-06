#ifndef SWEEPER
#define SWEEPER
#include<SFML/Graphics.hpp>
#include <iostream>
class Sweeper
{
public:
	Sweeper();
	~Sweeper();
	void update(sf::Time deltaTime, sf::Vector2f t_playerPos, sf::Vector2f t_playerVel);
	void detection(sf::Vector2f t_playerPos);
	void pursue(sf::Vector2f t_playerPos, sf::Vector2f t_playerUnitVel);
	void movement();
	void render(sf::RenderWindow& window);

	float steer();
	float distance();
	float angle(sf::Vector2f t_position, sf::Vector2f t_targetPosition);
private:
	sf::CircleShape m_body;
	sf::CircleShape m_coneOfVision;

	float m_coneOfVisionLength;
	float m_angles[6];

	float m_angleToTarget;
	float m_speed;
	float m_baseSpeed;
	float m_currentAngle;

	bool m_detect;

	sf::Vector2f m_detectionPoints[6];
	sf::Vector2f m_position;
	sf::Vector2f m_targetPosition;
	sf::Vector2f m_velocity;

	sf::Vertex m_points[6];
};

#endif