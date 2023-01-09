#include "GameMenu.h"

void game::GameMenu::setInitText(sf::Text& text, std::string str, float xpos, float ypos)
{
	text.setFont(font);
	text.setFillColor(menu_text_color);
	text.setString(str);
	text.setCharacterSize(size_font);
	text.setPosition(xpos, ypos);
	text.setOutlineThickness(3);
	text.setOutlineColor(border_color);
}

void game::GameMenu::setStringMenu(sf::String name[])
{
	int maxindex = name->getSize();

	for (int i = 0; i < maxindex - 1; i++) mainMenu[i].setString(name[i]);
}

void game::GameMenu::setPositionX(int posx)
{

	float nullx = 0;

	for (int i = 0; i < max_menu; i++) {

		switch (posx)
		{
		case 0:
			nullx = 0;
			break;
		case 1:
			nullx = mainMenu[i].getLocalBounds().width;
			break;
		case 2:
			nullx = nullx = mainMenu[i].getLocalBounds().width / 2;
			break;
		}

		mainMenu[i].setPosition(mainMenu[i].getPosition().x - nullx, mainMenu[i].getPosition().y);
	}

}

game::GameMenu::GameMenu(sf::RenderWindow& window, float menux, float menuy, int sizeFont, int step, int len_menu) :mywindow(window)
{
	if (len_menu < 2) len_menu = 2;
	size_font = sizeFont; // Размер шрифта

	// Загрузка шрифта
	if (!font.loadFromFile("font/troika.otf")) exit(32);

	menu_text_color = sf::Color::White;      // Цвет меню
	chose_text_color = sf::Color::Yellow;;   // Цвет выбора меню
	border_color = sf::Color::Black;;        // Цвет обводки текста
	max_menu = len_menu;                   // Количество пунктов меню
	mainMenu = new sf::Text[max_menu];     // Динамический массив пунктов меню

	for (int i = 0, ypos = menuy; i < max_menu; i++, ypos += step)
		setInitText(mainMenu[i], std::to_string(i) + " name", menux, ypos);

	mainMenuSelected = 0;
	mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);

}

void game::GameMenu::MoveUp()
{
	mainMenuSelected--;

	if (mainMenuSelected >= 0) {
		mainMenu[mainMenuSelected + 1].setFillColor(menu_text_color);
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
	}
	else
	{
		mainMenu[0].setFillColor(menu_text_color);
		mainMenuSelected = max_menu - 1;
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
	}
}

void game::GameMenu::MoveDown()
{
	mainMenuSelected++;

	if (mainMenuSelected < max_menu) {
		mainMenu[mainMenuSelected - 1].setFillColor(menu_text_color);
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
	}
	else
	{
		mainMenu[max_menu - 1].setFillColor(menu_text_color);
		mainMenuSelected = 0;
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
	}

}


void game::GameMenu::draw()
{
	for (int i = 0; i < max_menu; i++) mywindow.draw(mainMenu[i]);
}

void game::GameMenu::setColotTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor)
{
	menu_text_color = menColor;
	chose_text_color = ChoColor;
	border_color = BordColor;

	for (int i = 0; i < max_menu; i++) {
		mainMenu[i].setFillColor(menu_text_color);
		mainMenu[i].setOutlineColor(border_color);
	}
	mainMenu[mainMenuSelected].setFillColor(chose_text_color);
}