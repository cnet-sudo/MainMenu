#include <SFML/Graphics.hpp>
#include"GameMenu.h"

using namespace sf;

void GamåStart()
{
    RenderWindow Play(VideoMode(1280, 720), L"Óðîâåíü 1", Style::Fullscreen);

    RectangleShape background_play(Vector2f(1280, 720));
    Texture texture_play;
    texture_play.loadFromFile("image/menu4.jpg");
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

void Options() 
{
    RenderWindow Options(VideoMode(1280, 720), L"Íàñòðîéêè", Style::Fullscreen);

    RectangleShape background_opt(Vector2f(1280, 720));
    Texture texture_opt;
    texture_opt.loadFromFile("image/menu1.jpg");
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

void About_Game() 
{
    RenderWindow About(VideoMode(1280, 720), L"Î èãðå", Style::Fullscreen);

    RectangleShape background_ab(Vector2f(1280, 720));
    Texture texture_ab;
    texture_ab.loadFromFile("image/menu2.jpg");
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
    
    RenderWindow window(VideoMode(1280, 720), L"Ìîÿ èãðà", Style::Fullscreen);
    window.setMouseCursorVisible(false);
   
    game::GameMenu mymenu(500, 150);
    
    RectangleShape background(Vector2f(1280, 720));
    Texture texture_window;
    texture_window.loadFromFile("image/menu9.jpg");
    background.setTexture(&texture_window);

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
                    case 0:GamåStart(); break;
                    case 1:Options(); break;
                    case 2:About_Game(); break;
                    case 3:window.close(); break;
                   
                    }  
                } break;
            }
        }
        
        window.clear(Color::Blue);
        window.draw(background);
        mymenu.Draw(window);        
        window.display();
    }
    return 0;
}