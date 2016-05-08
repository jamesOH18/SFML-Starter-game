#include "stdafx.h"
#include "HelpPage.h"
#include "Game.h"
#include <iostream>

/// <summary>
/// \author Peter Lowe
/// \version 1.0
/// </summary>
HelpPage::HelpPage()
{
}


HelpPage::~HelpPage()
{
}

/// <summary>
/// @brief setup font and message.
/// 
/// Used to get a refrence to the font and setup the 
/// text used on the help page, a simple block of text
/// esc key will return to main menu
/// </summary>
/// <param name="font">Refrence to font loaded in main game</param>
void HelpPage::Initialise(sf::Font& font)
{
	m_font = font;	

	m_message.setFont(m_font);
	m_message.setString("Use the arrow keys to move \nMario left or right\nUp arrow will make him jump\nMove off the stage to exit\nEscape to return to Menu");
	m_message.setCharacterSize(24);
	m_message.setColor(sf::Color::White);

	sf::FloatRect textSize = m_message.getGlobalBounds();
	float xposition = Game::screenWidth / 2 - textSize.width / 2;
	m_message.setPosition(xposition, Game::screenHeight * 0.25f);
	m_exitPressed = false;
}
/// <summary>
/// @brief check for esc key.
/// 
/// Check if esc key is pressed and return to main menu
/// </summary>
/// <param name="event">event passed from process events in main loop</param>
void HelpPage::ProcessInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			m_exitPressed = true;
		}
	}
}
/// <summary>
///  @brief update exit on esc.
/// 
/// check if esc key press event occoured during process events
/// indicated by the bool m_exitPressed and if so return to main menu
/// always set vool to false;
/// </summary>
/// <param name="time">update delta time</param>
void HelpPage::Update(sf::Time time)
{
	if (m_exitPressed)
	{
		Game::currentState = GameState::MainMenu;
	}
	m_exitPressed = false;// will re-set boolean for next time user is here
}

/// <summary>
/// @brief draw the help page.
/// 
/// Draw the sf::Text object message.
/// </summary>
/// <param name="window">refrence to main render window</param>
void HelpPage::Render(sf::RenderWindow& window)
{	
	window.draw(m_message);
}