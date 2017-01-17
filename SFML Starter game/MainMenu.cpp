
#include <iostream> 
#include "MainMenu.h"
#include "Game.h"


/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date May2016
/// 
/// </summary>

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}


/// <summary>
/// @brief setup font and message.
/// 
/// Used to get a refrence to the font and  
/// load texture and setup sprite and text
/// for each button and positions on screen
/// </summary>
/// <param name="font">Refrence to font loaded in main game</param>
void MainMenu::Initialise(sf::Font& font)
{
	m_topOffset = 50;	
	m_verticalSpacing = 100;
	m_buttonWidth = 200;
	m_leftOffset = (Game::screenWidth - m_buttonWidth)/2;
	m_buttonHeight = 50;
	int textDropOffset = 10;
	sf::String m_menuTexts[] = { "Play", "Help", "Exit" };

	m_font = font;
	if (!m_buttonTexture.loadFromFile("ASSETS/IMAGES/button.png"))
	{
		std::cout << "error with button file";
	}
	for (int i = 0; i < m_optionCount; i++)
	{
		m_buttonSprites[i].setTexture(m_buttonTexture);
		m_buttonSprites[i].setPosition(m_leftOffset, m_verticalSpacing * i + m_topOffset);
		sf::Vector2u textureSize = m_buttonTexture.getSize();
		m_buttonSprites[i].setScale(m_buttonWidth/textureSize.x, m_buttonHeight/textureSize.y);

		m_buttonTexts[i].setFont(m_font);
		m_buttonTexts[i].setString(m_menuTexts[i]);
		m_buttonTexts[i].setColor(sf::Color::White);
		m_buttonTexts[i].setCharacterSize(24);
		sf::FloatRect textSize = m_buttonTexts[i].getGlobalBounds();
		float textOffset = (m_buttonWidth - textSize.width) / 2;
		m_buttonTexts[i].setPosition(m_leftOffset + textOffset, m_verticalSpacing * i + m_topOffset + textDropOffset);
	}	
}


/// <summary>
/// check current status of the mouse for intersection with
/// location of buttons using locations and offsets rather than rectangles
/// for intersection
/// 
/// Mouse button down will be true at this location on the next screen / gamestate
/// might cause a problem if so use event polling loop to detect mouse button down event
/// </summary>
/// <param name="time">update delta time</param>
/// <param name="window">refrence to main render window</param>
void MainMenu::Update(sf::Time time, sf::Window& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2i mouseLocation;
		mouseLocation = sf::Mouse::getPosition(window);
		if (mouseLocation.x > m_leftOffset && mouseLocation.x < m_leftOffset + m_buttonWidth )
		{
			if (mouseLocation.y > m_topOffset && mouseLocation.y && mouseLocation.y <  m_topOffset + m_buttonHeight)
			{
				Game::currentState = GameState::Game;
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing && mouseLocation.y <  m_topOffset + m_verticalSpacing + m_buttonHeight)
			{
				Game::currentState = GameState::Help;
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing * 2 && mouseLocation.y <  m_topOffset + m_verticalSpacing * 2 + m_buttonHeight)
			{
				window.close();
			}									
		}
	}
}

/// <summary>
///  draw menu text over buttons
/// </summary>
/// <param name="window">refrence to main render window</param>
void MainMenu::Render(sf::RenderWindow& window)
{
	for (int i = 0; i < m_optionCount; i++)
	{
		window.draw(m_buttonSprites[i]);
		window.draw(m_buttonTexts[i]);
	}
}