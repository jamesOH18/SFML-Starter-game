#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <SFML\Graphics.hpp>
#include "Player.h"

/// <summary>
/// @brief main game logic.
/// 
/// process input and passes on to player, check for game over and 
/// set gamestate back to main menu
/// </summary>
class GamePlay
{
public:
	GamePlay();
	~GamePlay();	
	void initialise();
	void render(sf::RenderWindow&);
	void processInput(sf::Event);
	void update(sf::Time);

protected:
	/// texture of landscape used as background
	sf::Texture m_backgroundTexture;
	/// sprite used to render background texture
	sf::Sprite m_backgroundSprite;
	/// instance of player
	Player m_player;	
	/// boolean used to pass jump key from processevents to update loop
	bool m_jumpKeyPressed;
};

#endif // !GAMEPLAY_H
