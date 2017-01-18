
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include <SFML/Graphics.hpp>
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>
#include "Game.h"
#include "Licence.h"
#include "SplashScreen.h"
/*
Written by Peter Lowe May 2015
Total Project Time ~ 10 hours*/


int main()
{ 
	Game game; 
	game.run(); 
}

float Game::screenWidth = 600;
float Game::screenHeight = 400;
GameState Game::currentState = GameState::Licence;
 
/// <summary>
/// @brief main game constructor creating the render window with settings
/// </summary>
Game::Game() : m_Window(sf::VideoMode(static_cast<int>(Game::screenWidth), static_cast<int>(Game::screenHeight)), "SMFL Game",sf::Style::Default)
{			
	LoadContent();
	m_Window.setKeyRepeatEnabled(false);
}
/// <summary>
/// @brief load the font and initialise everything else.
/// 
/// after loading the font pass a refrence to font resourse to other class iniatilisers
/// </summary>
void Game::LoadContent()
{
	int m_gold;
	if (!m_arialFont.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}
	m_licenceScreen.initialise(m_arialFont);
	m_splashScreen.Initialise(m_arialFont);
	m_mainMenu.Initialise(m_arialFont);
	m_mainGame.Initialise();
	m_helpPage.Initialise(m_arialFont);
	
	m_gold = 0;
#ifdef STARTRICH
	m_gold = 1000;
#endif // STARTRICH


#ifdef TEST_FPS
	updateFrameCount = 0;
	drawFrameCount = 0;
	secondTime = sf::Time::Zero;
	updateFps.setFont(m_arialFont);
	updateFps.setPosition(20, 300);		
	updateFps.setCharacterSize(24);
	updateFps.setColor(sf::Color::White);
	drawFps.setFont(m_arialFont);
	drawFps.setPosition(20, 350);
	drawFps.setCharacterSize(24);
	drawFps.setColor(sf::Color::White);
#endif // TEST_FPS
}

/// <summary>
/// @brief main game loop.
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_Window.isOpen())
	{
		ProcessEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{		
			timeSinceLastUpdate -= timePerFrame;

			ProcessEvents();
			Update(timePerFrame);		
#ifdef TEST_FPS
			secondTime += timePerFrame;
			updateFrameCount++;
			if (secondTime.asSeconds() > 1)
			{
				char bufferDps[256];
				char bufferUps[256];
				sprintf_s(bufferUps, "%d UPS", updateFrameCount-1);
				updateFps.setString(bufferUps);
				sprintf_s(bufferDps, "%d DPS", drawFrameCount);
				drawFps.setString(bufferDps);
				updateFrameCount = 0;
				drawFrameCount = 0;
				secondTime = sf::Time::Zero;
			}
#endif // TEST_FPS
		}
		Render();
#ifdef TEST_FPS
		drawFrameCount++;
#endif // TEST_FPS
	}
}
/// <summary>
/// @brief call the appropiate processEvents method ofr currentstate
/// </summary>
void Game::ProcessEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_Window.close();
		}
		switch (currentState)
		{
		case GameState::Licence:
			break;
		case GameState::Splash:
			m_splashScreen.ProcessInput(event);
			break;
		case GameState::MainMenu:			
			break;
		case GameState::Help:
			m_helpPage.ProcessInput(event);
			break;
		case GameState::Game:
			m_mainGame.ProcessInput(event);
			break;
		default:
			break;
		}
	}
}
/// <summary>
/// @brief call the update method corresponding to the current game state
/// </summary>
/// <param name="time">update delta time</param>
void Game::Update(sf::Time time)
{
	switch (currentState)
	{
	case GameState::Licence:
		m_licenceScreen.update(time);
		break;
	case GameState::Splash:
		m_splashScreen.Update(time);
		break;
	case GameState::MainMenu:
		m_mainMenu.Update(time, m_Window);
		break;
	case GameState::Help:
		m_helpPage.Update(time);
		break;
	case GameState::Game:
		m_mainGame.Update(time);
		break;
	default:
		break;
	}
}

/// <summary>
/// @brief call the renderer for the current game state
/// </summary>
void Game::Render()
{
	m_Window.clear();
	switch (currentState)
	{	
	case GameState::Licence:
		m_licenceScreen.render(m_Window);
		break;
	case GameState::Splash:
		m_splashScreen.Render(m_Window);			
		break;
	case GameState::MainMenu:
		m_mainMenu.Render(m_Window);
		break;
	case GameState::Help:
		m_helpPage.Render(m_Window);
		break;
	case GameState::Game:
		m_mainGame.Render(m_Window);
		break;
	default:
		break;
	}	
#ifdef TEST_FPS
	m_Window.draw(updateFps);
	m_Window.draw(drawFps);
#endif // TEST_FPS
	m_Window.display();
}