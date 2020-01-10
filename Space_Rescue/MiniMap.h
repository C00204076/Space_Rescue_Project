//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 10:49 10 January 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef MINIMAP_H
#define MINIMAP_H

#include <iostream>

#include "SFML/Graphics.hpp"

#include "TileMap.h"
#include "Player.h"
#include "Power-up.h"

//
class MiniMap
{
public:
	MiniMap();
	~MiniMap();

	void initialise();

	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow window);

private:

};

#endif // !MINIMAP_H

