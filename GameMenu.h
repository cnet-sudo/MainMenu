#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


namespace game {

class GameMenu
{
    int max_menu;
	int mainMenuSelected;
	sf::Font font;
	sf::Text * mainMenu;

	void setInitFont(sf::Text & text, std::string str, float xpos, float ypos);

	

public:
	GameMenu(float xpos, float ypos,int step, int len_menu);

	void draw(sf::RenderWindow & window);

	void MoveUp();

	void MoveDown();
    
	void setStringMenu(int index,sf::String name);

	void setPositionX(int index, float x1);
	
	int getMainMenuPressed() 
	{
		return mainMenuSelected;
	}
	~GameMenu()
	{
		delete[] mainMenu;
	}

};

}