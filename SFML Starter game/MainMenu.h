#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML\Graphics.hpp>

/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date may 2016
/// 
///  class to handle simple menu interaction
/// </summary>
class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void update(sf::Time, sf::Window&);

protected:
	
	/// Number of buttons on our menu
	static const int m_optionCount = 3;
	/// green button background
	sf::Texture m_buttonTexture; 
	/// array of sprites used to display buttons
	sf::Sprite m_buttonSprites[m_optionCount];
	/// local refrence to font used by whole game
	sf::Font m_font;
	/// array of text objects for text on buttons
	sf::Text m_buttonTexts[m_optionCount];	
	
	/// top left of area usde for menu
	float m_topOffset;
	/// top left of area usde for menu
	float m_leftOffset;
	/// gap in pixels between tops of buttons
	float m_verticalSpacing;
	/// width in pixels of all buttons
	float m_buttonWidth;
	/// height of button in pixels must be less than vertical spacing
	float m_buttonHeight;
};

#endif // !MAINMENU_H