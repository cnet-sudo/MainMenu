#include "GameMenu.h"

void game::GameMenu::setInitFont(sf::Text& text, std::string str, float xpos,float ypos)
{
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString(str);
	text.setCharacterSize(60);
	text.setPosition(xpos, ypos);
	text.setOutlineThickness(3);
	text.setOutlineColor(sf::Color::Black);
}

game::GameMenu::GameMenu(float menux, float menuy)
{
	if (!font.loadFromFile("font/troika.otf"))
	{
		std::cout << "No font is here";
	}
	float menu_x;

	for (int i = 0, ypos= menuy; i < max_menu; i++, ypos+=100)
		setInitFont(mainMenu[i], str[i], menux, ypos);
	
	mainMenuSelected = 0;
	mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);

}

void game::GameMenu::MoveUp()
{
    mainMenuSelected--;

	if (mainMenuSelected >= 0) {
		mainMenu[mainMenuSelected + 1].setFillColor(sf::Color::White);
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
	}
	else
	{
		mainMenu[0].setFillColor(sf::Color::White);
		mainMenuSelected = max_menu - 1;
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
	}
}

void game::GameMenu::MoveDown()
{
	mainMenuSelected++;

	if (mainMenuSelected < max_menu) {
		mainMenu[mainMenuSelected - 1].setFillColor(sf::Color::White);
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
	}
	else
	{
		mainMenu[3].setFillColor(sf::Color::White);
		mainMenuSelected = 0;
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
	}
	
}


void game::GameMenu::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < max_menu; i++) window.draw(mainMenu[i]);
}