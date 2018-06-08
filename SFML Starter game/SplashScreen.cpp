
#include <iostream> 
#include "SplashScreen.h"
#include "Game.h"


/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date May2016
/// 
/// </summary>

SplashScreen::SplashScreen()
{
}


SplashScreen::~SplashScreen()
{
}


/// <summary>
/// @brief setup font and message.
/// 
/// Used to get a refrence to the font and setup the 
/// press any key message text. load a texture for full screen
/// splash image.
/// </summary>
/// <param name="font">Refrence to font loaded in main game</param>
void SplashScreen::initialise(sf::Font& font)
{
	m_font = font;
	// load texture and setup sprite
	if (!m_splashTexture.loadFromFile("ASSETS/IMAGES/wallpaper.jpg"))
	{
		std::cout << "error with  splash file";
	}
	m_splashTexture.setRepeated(true);
	m_splashSprite.setTexture(m_splashTexture);
	m_splashSprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(Game::screenWidth), static_cast<int>( Game::screenHeight)));
	m_splashSprite.setPosition(0, 0);
	
	//setup message
	m_message.setFont(m_font);
	m_message.setString(" pete was here Press any space to continue");
	m_message.setCharacterSize(12);
	m_message.setStyle(sf::Text::Bold);
	m_message.setFillColor(sf::Color::White);
	// centre message
	sf::FloatRect textSize = m_message.getGlobalBounds();
	float xposition = Game::screenWidth / 2 - textSize.width / 2;
	m_message.setPosition(xposition, Game::screenHeight * 0.75f);
	m_proceedKeyPressed = false;
}


/// <summary>
/// called from process events in maion game loop  many times per frame
/// boolean used to detect a single key down event for space bar and
/// pass on to update loop
/// </summary>
/// <param name="event">event paased from main game loop</param>
void SplashScreen::processInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			m_proceedKeyPressed = true;
		}
	}
}


/// <summary>
/// update loop called 30/60 per second processing power permitting
/// reset boolean used to signify keypress event
/// </summary>
/// <param name="time">update delta time</param>
void SplashScreen::update(sf::Time time)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		m_proceedKeyPressed = true;
	}
	if (m_proceedKeyPressed)
	{
		Game::currentState = GameState::MainMenu;
	}
	m_proceedKeyPressed = false;
}


/// <summary>
/// Draw the background texture and the press space message 
/// </summary>
/// <param name="window">refrence to manin tender window</param>
void SplashScreen::render(sf::RenderWindow& window)
{
	window.draw(m_splashSprite);
	window.draw(m_message);
}