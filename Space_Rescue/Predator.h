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
	sf::RectangleShape m_rect;

	float m_coneOfVisionLength;
	float m_angle;
	sf::Vector2f m_visionOrigin;

	sf::Vector2f m_coneRelativePos;
	sf::Vector2f m_visionOriginRelative;

	sf::Vertex m_center;
};
#endif