#ifndef PREDATOR
#define PREDATOR

#include <SFML/Graphics.hpp>
#include <iostream>

class Predator
{
public:
	Predator();
	~Predator();
	void update(sf::Time deltaTime);
	void detection(sf::Vector2f t_playerPos);
	void render(sf::RenderWindow& window);
private:
	sf::CircleShape m_body;
	sf::CircleShape m_coneOfVision;

	float m_coneOfVisionLength;
	float m_angles[6];

	sf::Vector2f m_detectionPoints[6];
	sf::Vector2f m_position;

	sf::Vertex m_points[6];
};
#endif