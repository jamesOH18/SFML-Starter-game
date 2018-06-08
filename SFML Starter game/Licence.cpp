
#include "Licence.h"
#include "Game.h"


Licence::Licence()
{
}


Licence::~Licence()
{
}

/// <summary>
/// @brief setup font and message.
/// 
/// Used to get a refrence to the font and setup the 
/// text used on the licence page, a single line of text
/// will proceed to splash page after 2 seconds
/// </summary>
/// <param name="font">Refrence to font loaded in main game</param>
void Licence::initialise(sf::Font& font)
{

	m_font = font;
	m_message.setFont(m_font);
	m_message.setString("Hand Made by Peter");
	m_message.setCharacterSize(24);
	m_message.setFillColor(sf::Color::White);

	sf::FloatRect textSize = m_message.getGlobalBounds();
	float xPosition = Game::screenWidth / 2 - textSize.width / 2;
	m_message.setPosition(xPosition, 120.0f);
	m_cumulativeTime = sf::seconds(0);

}

/// <summary>
/// @brief update loop wait 2 seconds.
/// 
/// Add the delta time to cumulative total 
/// when greater than 2 second proceed to splash screen
/// </summary>
/// <param name="time">update delta time</param>
void Licence::update(sf::Time time)
{
	m_cumulativeTime += time;
	if (m_cumulativeTime.asSeconds() > 0.8)
	{
		Game::currentState = GameState::Splash;
	}
}
/// <summary>
/// @brief draw thw licence text.
/// </summary>
/// <param name="window">refrence to main render window</param>
void Licence::render(sf::RenderWindow& window)
{
	window.draw(m_message);
}
