//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 10:49 10 January 2019
// Finished at
// Time taken:
// Known bugs:

#include "MiniMap.h"

//
MiniMap::MiniMap(TileMap* tileMap, Player* player) :
	m_tileMap(tileMap),
	m_player(player)
	//m_powerUp(powerUp)
{
	initialise();
}

//
MiniMap::~MiniMap()
{
	delete this;
}

//
void MiniMap::initialise()
{

}

//
void MiniMap::update(sf::Time deltaTime, sf::RenderWindow& window, sf::View view)
{

	m_player->update(deltaTime, view);
}

//
void MiniMap::render(sf::RenderWindow& window, sf::View view)
{
	//
	window.setView(view);
	//
	//m_tileMap->render(window, sf::Vector2f(3.0f, 3.0f));
	//
	m_player->render(window, sf::Vector2f(3.0f, 3.0f));
	//
	//m_powerUp->render(window, sf::Vector2f(3.0f, 3.0f));
}