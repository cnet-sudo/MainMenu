#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


namespace game {

class GameMenu
{
    int max_menu;                // Максимальное количество пунктов меню
	int size_font;               // Размер шрифта
	int mainMenuSelected;        // Выбраное меню
	sf::Font font;               // Шрифт меню 
	sf::Text * mainMenu;         // Динамический массив названий меню
	sf::Color menu_text_color;   // Цвет меню
	sf::Color chose_text_color;  // Цвет выбора меню
	sf::Color border_color;      // Цвет обводки текста

	// Настройка шрифта меню
	void setInitFont(sf::Text & text, std::string str, float xpos, float ypos);

public:
	
	GameMenu(float menux, float menuy, int sizeFont = 60, int step = 80, int len_menu = 4);
	// Рисуем меню
	void draw(sf::RenderWindow & window);

	void MoveUp();               // Перемещение меню вверх

	void MoveDown();             // Перемещение меню вниз
    
	void setStringMenu(int index,sf::String name);  // Текст меню

	void setColotTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor);  // Цвет меню

	void setPositionX(int index, float x1);         // Отцентров отдельных пунктов меню
	
	int getMainMenuPressed()                        // Возвращае номер выбраного элемента
	{
		return mainMenuSelected;
	}
	~GameMenu()
	{
		delete[] mainMenu;
	}

};

}