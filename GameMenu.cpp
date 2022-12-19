#include "GameMenu.h"

void game::GameMenu::setInitFont(sf::Text& text, std::string str, float ypos)
{
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString(str);
	text.setCharacterSize(60);
	text.setPosition(540, ypos);
	text.setOutlineThickness(3);
	text.setOutlineColor(sf::Color::Black);
}

game::GameMenu::GameMenu(float width, float height)
{
	if (!font.loadFromFile("font/troika.otf"))
	{
		std::cout << "No font is here";
	}

	for (int i = 0, ypos=150; i < max_menu; i++, ypos+=100)
		setInitFont(mainMenu[i], str[i], ypos);
	
	mainMenuSelected = -1;
}

void game::GameMenu::MoveUp()
{
	if (mainMenuSelected - 1 >= 0){
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);
	    mainMenuSelected--;
		if (mainMenuSelected == -1) mainMenuSelected = 2;
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
	}
}

void game::GameMenu::MoveDown()
{
	if (mainMenuSelected + 1 <= max_menu)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);
		mainMenuSelected++;
		if (mainMenuSelected == 4) mainMenuSelected = 0;
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);

	}
}

game::GameMenu::~GameMenu() 
{


}

void game::GameMenu::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < max_menu; i++) window.draw(mainMenu[i]);

}