#pragma once
#include <SFML/Graphics.hpp>

namespace game {

	class GameMenu
	{
		int max_menu;                // Максимальное количество пунктов меню
		int size_font;               // Размер шрифта
		int mainMenuSelected;        // Номер текущего пункта меню 
		sf::Font font;               // Шрифт меню 
		sf::Text* mainMenu;          // Динамический массив названий меню
		sf::Color menu_text_color;   // Цвет меню
		sf::Color chose_text_color;  // Цвет выбора меню
		sf::Color border_color;      // Цвет обводки текста

		// Настройка текста меню
		void setInitText(sf::Text& text, std::string str, float xpos, float ypos);

		sf::RenderWindow& mywindow;
	public:

		GameMenu(sf::RenderWindow& window, float menux, float menuy, int sizeFont = 60, int step = 80, int len_menu = 4);

		void draw();                                     // Рисуем меню

		void MoveUp();                                   // Перемещение меню вверх

		void MoveDown();                                 // Перемещение меню вниз

		void setStringMenu(sf::String name[]);  // Текст меню

		void setColotTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor);  // Цвет меню

		void setPositionX(int posx);                    // Выравнивание положения меню

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