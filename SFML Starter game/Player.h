#ifndef PLAYER_H
#define PLAYER_H


#include <SFML\Graphics.hpp>
/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date may 2016
/// 
/// @brief simple class for player.
/// 
/// stores player sprite and position with
/// methods for movement and gameover
/// </summary>
class Player
{
public:
	Player();
	~Player();
	void Initialise();
	void Render(sf::RenderWindow&);	
	void Update(sf::Time);
	void Jump();
	void Fall();
	void Left();
	void Right();
	bool Departed();
	void resetPosition();
protected:
	/// Texture for palyer mario on cart
	sf::Texture m_playerTexture;
	/// sprite used to represent player
	sf::Sprite m_playerSprite;
	/// position on background where player should stop falling
	float m_roadHeight;

};
#endif // !PLAYER_H

