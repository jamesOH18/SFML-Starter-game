#ifndef GAME_H
#define GAME_H
// Use the vs debug / release mode effect of defineing _DEBUG to turn on/off
// features  used only in degub mode
#ifdef _DEBUG
#define TEST_FPS
#endif // _DEBUG

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
 

#include "Licence.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "GamePlay.h"
#include "HelpPage.h"

/// <summary>
/// /brief enum used to determine gamestate
/// </summary>
enum class
	GameState
{
	None,
	Licence,
	Splash,
	MainMenu,
	Help,
	Game
};

/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date may 2016
/// @brief main game class conatins main and run game loop.
/// </summary>
class Game
{
public:
	Game();
	void run();
	
	//	static properties accessed by all classes
	/// width of the screen in pixels (stored as float? for parameter conversion)
	static float screenWidth;
	/// screen width in pixels
	static float screenHeight;
	/// current game state
	static GameState currentState;

protected:
	void	processEvents();
	void	update(sf::Time);
	void	render();
	void	loadContent();
	
	/// /// variable
	sf::Font m_arialFont; 
	/// variable
	sf::RenderWindow m_Window;
#ifdef TEST_FPS
	sf::Text updateFps;
	sf::Text drawFps;
	sf::Time secondTime;
	int updateFrameCount;
	int drawFrameCount;

#endif // TEST_FPS
	
	//instances of classes used to handle the different behaviours needed in the complete game
	/// instance used to run licence screen
	Licence	m_licenceScreen;
	/// instance used to run splash screen
	SplashScreen m_splashScreen;
	/// instance used to run main menu
	MainMenu m_mainMenu;
	/// instance used for main gameplay
	GamePlay m_mainGame;
	/// instance used to display help page
	HelpPage m_helpPage;				
};
#endif // !GAME_H