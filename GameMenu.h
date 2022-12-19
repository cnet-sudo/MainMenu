#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


namespace game {

class GameMenu
{
	static const int max_menu=4;
	int mainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[max_menu];

	void setInitFont(sf::Text & text, std::string str, float xpos, float ypos);

	std::string str[4]{ "Play","Options","About","Exit" };

public:
	GameMenu(float xpos, float ypos);

	void Draw(sf::RenderWindow & window);

	void MoveUp();

	void MoveDown();

	int getMainMenuPressed() 
	{
		return mainMenuSelected;
	}

};

}