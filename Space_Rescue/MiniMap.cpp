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

/// <summary>
/// MiniMap default constructor
/// </summary>
/// <param name="tileMap"></param>
/// <param name="player"></param>
/// <param name="powerUp"></param>
MiniMap::MiniMap(TileMap* tileMap, Player* player, PowerUp* powerUp) :
	m_tileMap(tileMap),
	m_player(player),
	m_powerUp(powerUp)
{
	initialise();
}

/// <summary>
/// MiniMap default destructor
/// </summary>
MiniMap::~MiniMap()
{
	delete this;
}

/// <summary>
/// Intialisor used for setting the default values of the MiniMap's
/// variables
/// </summary>
void MiniMap::initialise()
{

}

/// <summary>
/// Updates the Game Objects Player and PowerUp with the MiniMap
/// </summary>
/// <param name="deltaTime"></param>
/// <param name="window"></param>
/// <param name="view"></param>
void MiniMap::update(sf::Time deltaTime, sf::RenderWindow& window, sf::View view)
{
	m_player->update(deltaTime, view);
	m_powerUp->update(deltaTime);
}

/// <summary>
/// Renders and draws the TileMap, Player and PowerUp Objects 
/// within the MiniMap Object
/// </summary>
/// <param name="window"></param>
/// <param name="view"></param>
void MiniMap::render(sf::RenderWindow& window, sf::View view)
{
	// Sets the Viewport of the MiniMap
	window.setView(view);
	
	m_tileMap->render(window, sf::Vector2f(3.0f, 3.0f));
	
	m_player->render(window, sf::Vector2f(3.0f, 3.0f));
	
	m_powerUp->render(window, sf::Vector2f(3.0f, 3.0f));
}