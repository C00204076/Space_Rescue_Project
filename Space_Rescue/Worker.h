#ifndef WORKER
#define WORKER

#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"

class TileMap;
class Tile;
class Worker
{
	
	public:
		Worker(TileMap * t_map);
		~Worker();
		void update(sf::Time deltaTime);
		void wander();
		void movement();
		void render(sf::RenderWindow & window);

		float steer();
		float distance();
		float angle(sf::Vector2f t_position, sf::Vector2f t_targetPosition);
	private:
		sf::CircleShape m_body;

		float m_angleToTarget;
		float m_speed;
		float m_baseSpeed;
		float m_currentAngle;

		bool m_wandering = true;

		sf::Vector2f m_position;
		sf::Vector2f m_targetPosition;
		sf::Vector2f m_velocity;

		sf::Vector2i m_target;

		TileMap* m_map;
		std::list<Tile*> m_path;
		//Player* m_player;
};

#endif