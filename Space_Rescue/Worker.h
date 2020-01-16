#ifndef WORKER
#define WORKER

#include "SFML/Graphics.hpp"
class Worker
{
public:
	Worker();
	~Worker();
	void update(sf::Time deltaTime);
	void movement();
	void render(sf::RenderWindow& window);

	//float steer();
	//float distance();
	float angle(sf::Vector2f t_position, sf::Vector2f t_targetPosition);
private:
	sf::CircleShape m_body;

	//float m_angleToTarget;
	//float m_speed;
	//float m_baseSpeed;
	//float m_currentAngle;


	sf::Vector2f m_position;
	sf::Vector2f m_velocity;

};

#endif