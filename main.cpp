#include <SFML/Graphics.hpp>
#include"GameMenu.h"

using namespace sf;

int main()
{
    
    RenderWindow window(VideoMode(1280, 720), L"Моя игра", Style::Fullscreen);
    window.setMouseCursorVisible(false);
    game::GameMenu mymenu(window.getSize().x, window.getSize().y);
    window.setVerticalSyncEnabled(true);

    RectangleShape background;
    background.setSize(Vector2f(1280,720));
    Texture texture_window;
    texture_window.loadFromFile("image/menu9.jpg");
    background.setTexture(&texture_window);

    RectangleShape background_play;
    background_play.setSize(Vector2f(1280, 720));
    Texture texture_play;
    texture_play.loadFromFile("image/menu4.jpg");
    background_play.setTexture(&texture_play);

    RectangleShape background_opt;
    background_opt.setSize(Vector2f(1280, 720));
    Texture texture_opt;
    texture_opt.loadFromFile("image/menu1.jpg");
    background_opt.setTexture(&texture_opt);

    RectangleShape background_ab;
    background_ab.setSize(Vector2f(1280, 720));
    Texture texture_ab;
    texture_ab.loadFromFile("image/menu2.jpg");
    background_ab.setTexture(&texture_ab);


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
                    RenderWindow Play(VideoMode(1280, 720), L"Уровень 1", Style::Fullscreen);
                    RenderWindow Options(VideoMode(1280, 720), L"Настройки", Style::Fullscreen);
                    RenderWindow About(VideoMode(1280, 720), L"О игре", Style::Fullscreen);

                    int x = mymenu.getMainMenuPressed();
                    if (x == 0)
                    {
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
                            
                        Options.close();
                        About.close();
                        Play.clear();

                        Play.draw(background_play);
                        Play.display();
                        }
                        
                    }
                    if (x == 1)
                    {
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

                            Play.close();
                            About.close();
                            Options.clear();
                            Options.draw(background_opt);
                            Options.display();
                        }

                    }
                    if (x == 2)
                    {
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

                            Play.close();
                            Options.close();
                            About.clear();
                            About.draw(background_ab);
                            About.display();
                        }

                    }
                    if (x == 3)
                    {
                        window.close();
                    }
                }
                break;
            default:
                break;
            }

        }
        
        window.clear(Color::Blue);
        window.draw(background);
        mymenu.Draw(window);        
        window.display();
    }
    return 0;
}