

#include "GamePlay.h"
#include "Game.h"
#include <iostream>



GamePlay::GamePlay()
{
}
 

GamePlay::~GamePlay()
{
}

/// <summary>
/// @brief load texture and initialise player.
/// 
/// load and set scale on texture then initialise player
/// </summary>
void GamePlay::Initialise()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/background.jpg"))
	{
		std::cout << "error with  background file";
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);
	float scalex = Game::screenWidth / m_backgroundTexture.getSize().x;
	float scaley = Game::screenHeight / m_backgroundTexture.getSize().y;
	m_backgroundSprite.setScale(scalex, scaley);
	m_backgroundSprite.setPosition(0, 0);
		
	m_player.initialise();
	
}
/// <summary>
/// @brief check for for event prior to update.
/// 
/// check for up arrow key press before main loop calls update
/// </summary>
/// <param name="event">sf event from os</param>
void GamePlay::ProcessInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up)
		{
			m_jumpKeyPressed = true;
		}
	}
}
/// <summary>
/// @brief main gameplay loop.
/// 
/// check for player input and call player methods
/// then update player and check if game over
/// </summary>
/// <param name="time">update delta time</param>
void GamePlay::Update(sf::Time time)
{
	if (m_jumpKeyPressed)
	{
		m_player.jump();
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_player.left();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_player.right();
	}
	if (m_player.departed())	
	{		
		Game::currentState = GameState::MainMenu;
		m_player.resetPosition();
	}
	m_player.update(time);
	m_jumpKeyPressed = false;
}
/// <summary>
/// @brief render the game scene.
/// 
/// draw the background then the player
/// 
/// </summary>
/// <param name="window">refrence to main render window</param>
void GamePlay::Render(sf::RenderWindow& window)
{
	window.draw(m_backgroundSprite);
	m_player.render(window);
}