#pragma once
#include <SFML/Graphics.hpp>

namespace game {

	class GameMenu
	{
		float menu_X;                                     // Координаты меню по X
		float menu_Y;				                      // Координаты меню по Y
		int menu_Step;                                    // Растояние между пунктами меню
		int max_menu;                                     // Максимальное количество пунктов меню
		int size_font;                                    // Размер шрифта
		int mainMenuSelected;                             // Номер текущего пункта меню 
		sf::Font font;                                    // Шрифт меню 
		sf::Text* mainMenu;                               // Динамический массив названий меню

		sf::Color menu_text_color = sf::Color::White;      // Цвет меню
		sf::Color chose_text_color = sf::Color::Yellow;    // Цвет выбора меню
		sf::Color border_color = sf::Color::Black;         // Цвет обводки текста

		// Настройка текста меню
		void setInitText(sf::Text& text, sf::String str, float xpos, float ypos);

		sf::RenderWindow& mywindow;
	public:

		GameMenu(sf::RenderWindow& window, float menux, float menuy, sf::String name[], int sizeFont = 60, int step = 80);

		void draw();                                     // Рисуем меню

		void MoveUp();                                   // Перемещение меню вверх

		void MoveDown();                                 // Перемещение меню вниз

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