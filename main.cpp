#include <SFML/Graphics.hpp>
#include"GameMenu.h"

using namespace sf;
// функция настройки текста
void InitText(Text & mtext,float xpos, float ypos,String str, int size_font=60, Color menu_text_color=Color::White,int bord=0, Color border_color = Color::Black)
{
    mtext.setCharacterSize(size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(menu_text_color);
    mtext.setOutlineThickness(bord);
    mtext.setOutlineColor(border_color);

}
// Игра
void GamеStart()
{
    RenderWindow Play(VideoMode(1280, 720), L"Уровень 1", Style::Fullscreen);

    RectangleShape background_play(Vector2f(1280, 720));
    Texture texture_play;
    if (!texture_play.loadFromFile("image/menu4.jpg")) exit(1);
   
    background_play.setTexture(&texture_play);

    while (Play.isOpen())
    {
        Event event_play;
        while (Play.pollEvent(event_play))
        {
            if (event_play.type == Event::Closed) Play.close();
            if (event_play.type == Event::KeyPressed)
            {
                if (event_play.key.code == Keyboard::Escape) Play.close();
            }
        }
        Play.clear();
        Play.draw(background_play);
        Play.display();
    }
}
// Настройки игры
void Options() 
{
    RenderWindow Options(VideoMode(1280, 720), L"Настройки", Style::Fullscreen);

    RectangleShape background_opt(Vector2f(1280, 720));
    Texture texture_opt;
    if (!texture_opt.loadFromFile("image/menu1.jpg")) exit(2);
    
    background_opt.setTexture(&texture_opt);
    while (Options.isOpen())
    {
        Event event_opt;
        while (Options.pollEvent(event_opt))
        {
            if (event_opt.type == Event::Closed) Options.close();
            if (event_opt.type == Event::KeyPressed)
            {
                if (event_opt.key.code == Keyboard::Escape) Options.close();
            }
        }
        Options.clear();
        Options.draw(background_opt);
        Options.display();
    }

}
// Описание игры
void About_Game() 
{
    RenderWindow About(VideoMode(1280, 720), L"О игре", Style::Fullscreen);

    RectangleShape background_ab(Vector2f(1280, 720));
    Texture texture_ab;
    if (!texture_ab.loadFromFile("image/menu2.jpg")) exit(3);
    
    background_ab.setTexture(&texture_ab);

    while (About.isOpen())
    {
        Event event_play;
        while (About.pollEvent(event_play))
        {
            if (event_play.type == Event::Closed) About.close();
            if (event_play.type == Event::KeyPressed)
            {
                if (event_play.key.code == Keyboard::Escape) About.close();
            }
        }
        About.clear();
        About.draw(background_ab);
        About.display();
    }
}

int main()
{
    
    RenderWindow window(VideoMode(1280, 720), L"Моя игра", Style::Fullscreen);
    window.setMouseCursorVisible(false);
    // Координаты выравнивания текста
    float center[4]{ 0,-70,-10,-15 };
    // Название пунктов меню
    String name_menu[4]{ L"Старт",L"Настройки", L"О игре",L"Выход" };
    // Объект меню
    game::GameMenu mymenu(550, 250);
    // Установка цвета отображения меню
    mymenu.setColotTextMenu(Color(237, 147, 0), Color::Red, Color::Black);

    for (int i = 0; i < 4; i++) { 
        mymenu.setPositionX(i, center[i]);
        mymenu.setStringMenu(i, name_menu[i]); }

    
    RectangleShape background(Vector2f(1280, 720));
    Texture texture_window;
    if (!texture_window.loadFromFile("image/menu9.jpg")) return 4;
    background.setTexture(&texture_window);

    Text Titul;
    Font font;
    if (!font.loadFromFile("font/troika.otf")) return 5;
   
    Titul.setFont(font);
    InitText(Titul,320,50,L"Апокалипсис",100, Color(237,147,0),3);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close(); break;
            case Event::KeyReleased:
                if (event.key.code == Keyboard::Up) { mymenu.MoveUp(); break; }
                if (event.key.code == Keyboard::Down) { mymenu.MoveDown(); break;}
                if (event.key.code == Keyboard::Return)
                {                  
                    switch (mymenu.getMainMenuPressed())
                    {
                    case 0:GamеStart(); break;
                    case 1:Options(); break;
                    case 2:About_Game(); break;
                    case 3:window.close(); break;
                   
                    }  
                } break;
            }
        }
        
       
        window.clear(Color::Blue);
        window.draw(background);
        window.draw(Titul);
        mymenu.draw(window);        
        window.display();
    }
    return 0;
}