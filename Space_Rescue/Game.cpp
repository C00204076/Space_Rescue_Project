//
// C00
// Paul Nolan
// C00204076
// Brandon Seah-Dempsey
// Started at 11:11 7 January 2019
// Finished at
// Time taken:
// Known bugs:


#include "Game.h"

/// <summary>
/// Game's default constructor
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1500, 900, 32}, "Space Rescue" },
	is_running{ true }
{
	initialise();
}

/// <summary>
/// Game's default destructor
/// </summary>
Game::~Game()
{
	//delete this;
}

/// <summary>
/// Initialisator of default starting values of Game's main variables
/// </summary>
void Game::initialise()
{
	srand(time(nullptr));
	//
	// Sets the Center, Size and Zoom of the Viewport that follows the Player Object
	m_playerView.setCenter(m_window.getSize().x / 2, m_window.getSize().y);
	m_playerView.setSize(1500, 900);
	m_playerView.zoom(1.0f);
	// Sets Viewport of the game's mini-map
	m_miniMapView.reset(sf::FloatRect(0, 0, m_window.getSize().x / 2, m_window.getSize().y / 2));
	m_miniMapView.setViewport(sf::FloatRect(1.2f - (1.0f * m_miniMapView.getSize().x) / m_window.getSize().x - 0.04f, // RectLeft
											0.3f - (1.0f * m_miniMapView.getSize().y) / m_window.getSize().y - 0.02f, // RectTop
											(1.0f * m_miniMapView.getSize().x) / m_window.getSize().x, // RectWidth
											(1.0f * m_miniMapView.getSize().y) / m_window.getSize().y)); // RectHeight
	m_miniMapView.zoom(25.0f);
	// Initialises allof the Game Objects used in the game
	m_tileMap = new TileMap((float)30.0f);
	m_miniTile = new TileMap((float)30.0f);

	m_player = new Player();

	m_predator = new Predator(m_tileMap);

	for (int i = 0; i < 4; i++)
	{
		m_worker[i] = new Worker(m_tileMap);
	}

	m_miniPlayer = new Player();

	m_powerUp = new PowerUp();
	m_miniPower = new PowerUp();

	m_miniMap = new MiniMap(m_miniTile, m_miniPlayer, m_miniPower);

	m_collision = Collisions();
}

/// <summary>
/// Method used to call and run the game's update and renders function 
/// within a certain frame rate
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			processEvents();
			update(timeSinceLastUpdate);
			timeSinceLastUpdate -= timePerFrame;
			//timeSinceLastUpdate = sf::Time::Zero;
		}

		render();
		//clean();
	}
}

/// <summary>
/// Method using in processing the game's main events
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type)
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				is_running = false;
			}
		}

		if (sf::Event::KeyPressed == event.type) //user pressed a key
		{

		}
		if (sf::Event::MouseButtonPressed == event.type || sf::Event::MouseButtonReleased == event.type) //user pressed a key
		{

		}

		processGameEvents(event);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="event"></param>
void Game::processGameEvents(sf::Event& event)
{
	//Check if the event is a mouse release event

	switch (event.type)
	{
	case sf::Event::KeyPressed:
		//m_keyhandler.updateKey(event.key.code, true);
		break;
	case sf::Event::KeyReleased:
		//m_keyhandler.updateKey(event.key.code, false);
		break;
	default:
		break;
	}
}

/// <summary>
/// 
/// </summary>
void Game::processInput()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		default:
			break;
		}

	}
}

/// <summary>
/// Method used in calling the update functions of all game Objects
/// used within the game
/// </summary>
/// <param name="deltaTime"></param>
void Game::update(sf::Time deltaTime)
{
	if (!is_running)
	{
		m_window.close();
	}
	//
	m_miniMap->update(deltaTime, m_window, m_miniMapView);
	//
	m_tileMap->update(deltaTime, m_window);
	//
	m_player->update(deltaTime, m_playerView);
	m_player->tileCollision(m_tileMap);
	//
	m_predator->update(deltaTime, m_player->getPosition(),m_player->getVelocity());
	m_predator->detection(m_player->getPosition());

	for (int i = 0; i < 4; i++)
	{
		m_worker[i]->update(deltaTime);
	}
	//
	m_powerUp->update(deltaTime, m_tileMap);
	m_miniPower->setPosition(m_powerUp->getPosition());
	m_miniPower->setActive(m_powerUp->getActive());
	m_miniPower->setType(m_powerUp->getType());
	//
	m_collision.update(m_player, m_predator,m_tileMap, m_powerUp, m_player->getMissile());
}

/// <summary>
/// Method used to render and draw the textures and sprites of
/// all the game's Objects
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black); //Set background to black
	// Renders the game's Tile Map/Game World
	m_tileMap->render(m_window);
	// Renders the Player Game Object
	m_player->render(m_window);

	m_predator->render(m_window);

	for (int i = 0; i < 4; i++)
	{
		m_worker[i]->render(m_window);
	}

	// Renders the Power-Up object
	m_powerUp->render(m_window);
	// Renders the game's mini-map Viewport
	m_miniMap->render(m_window, m_miniMapView);
	// Set's the game ViewPort to follow the Player Object
	m_window.setView(m_playerView);
	m_window.display();
}

//
void Game::clean()
{
	m_tileMap->~TileMap();
}