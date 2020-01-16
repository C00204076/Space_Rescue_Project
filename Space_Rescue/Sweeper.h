#ifndef SWEEPER
#define SWEEPER
#include<SFML/Graphics.hpp>
class Sweeper
{
public:
	Sweeper();
	~Sweeper();
	void update(sf::Time deltaTime);
	void detection(sf::Vector2f t_playerPos);
	void render(sf::RenderWindow& window);
private:
	sf::CircleShape m_body;
	sf::CircleShape m_coneOfVision;

	float m_coneOfVisionLength;
	float m_angles[6];

	sf::Vector2f m_detectionPoints[6];
	sf::Vector2f m_visionOrigin;

	sf::Vector2f m_coneRelativePos;
	sf::Vector2f m_visionOriginRelative;

	sf::Vertex m_points[6];
};

#endif