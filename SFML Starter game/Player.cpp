
#include <iostream>
#include "Player.h"
#include "Game.h"


/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date may 2016
/// 
/// </summary>

Player::Player()
{
}


Player::~Player()
{
}
/// <summary>
/// @brief load & setup player sprite and roadHeight
/// </summary>
void Player::Initialise()
{
	if (!m_playerTexture.loadFromFile("ASSETS/IMAGES/mario.png"))
	{
		std::cout << "error with  mario  file";
	}
	m_playerSprite.setTexture(m_playerTexture);
	m_roadHeight = 230;
	m_playerSprite.setPosition(Game::screenWidth / 2, m_roadHeight);
}
/// <summary>
/// @brief jump up 100 pixels.
/// 
/// reacting to a key press event raise the position by 100
/// </summary>
void Player::Jump()
{
	m_playerSprite.setPosition(m_playerSprite.getPosition().x, m_playerSprite.getPosition().y - 100);	
}

/// <summary>
/// @brief apply gravity.
/// 
/// move the player position down one so long as he is above raod
/// </summary>
void Player::Fall()
{
	if (m_playerSprite.getPosition().y < m_roadHeight)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x, m_playerSprite.getPosition().y + 1);
	}
}


/// <summary>
/// @ brief move the player left.
/// 
/// move the player position one pixel to left
/// if horizontal scale is +1 (facing right) the move player 188 to flip
/// sprite but keep player head in same location and set scale
/// to minus 1
/// </summary>
void Player::Left()
{
	m_playerSprite.setPosition(m_playerSprite.getPosition().x - 1, m_playerSprite.getPosition().y);
	if (m_playerSprite.getScale().x == 1)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x + 118, m_playerSprite.getPosition().y);
	}
	m_playerSprite.setScale(-1, 1);
}

/// <summary>
/// @brief checks if game is over.
/// 
/// check if player position is off screen if so the return true
/// </summary>
/// <returns>game over or not</returns>
bool Player::Departed()
{
	if (m_playerSprite.getPosition().x < 0 || m_playerSprite.getPosition().x > Game::screenWidth)
	{
		return true;
		 
	}
	else
	{
		return false;
	}
}
void Player::resetPosition()
{
	m_playerSprite.setPosition(Game::screenWidth / 2, m_roadHeight);
}
/// <summary>
/// @ brief move the player right.
/// 
/// move the player position one pixel to right
/// if horizontal scale is -1 (facing left) the move player 188 to flip
/// sprite but keep player head in same location and set scale
/// to plus 1
/// </summary>
void Player::Right()
{
	m_playerSprite.setPosition(m_playerSprite.getPosition().x + 1, m_playerSprite.getPosition().y);
	if (m_playerSprite.getScale().x == -1)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x - 118, m_playerSprite.getPosition().y);
	}
	m_playerSprite.setScale(1, 1);
}

/// <summary>
/// @brief update world on player.
/// 
/// movement is iniated from the gameplay class
/// </summary>
/// <param name="time">update delta time</param>
void Player::Update(sf::Time time)
{
	Fall();	
}

/// <summary>
/// @brief draw player sprite.
/// </summary>
/// <param name="window">refrence to main render window</param>
void Player::Render(sf::RenderWindow& window)
{
	window.draw(m_playerSprite);
}