#include <SFML/Graphics.hpp>
#include"GameMenu.h"
#include<SFML/Audio.hpp>
#include "Animator.h"
#include<windows.h>

using namespace sf;

// функция настройки текста
void InitText(Text& mtext, float xpos, float ypos, String str, int size_font = 60, Color menu_text_color = Color::White, int bord = 0, Color border_color = Color::Black);

// Игровой процесс
void GamеStart();

// Настройки игры
void Options();

// Описание игры
void About_Game();



int main()
{
    // Создаём окно windows
    RenderWindow window;
    window.create(VideoMode::getDesktopMode(), L"Моя игра", Style::Fullscreen);

    // Делаем окно windows прозрачным
    SetWindowLong(window.getSystemHandle(), GWL_EXSTYLE, GetWindowLong(window.getSystemHandle(), GWL_EXSTYLE) | WS_EX_LAYERED);
    SetLayeredWindowAttributes(window.getSystemHandle(), 0, 10, LWA_COLORKEY);
    
    window.setMouseCursorVisible(false); //отключаем видимость курсора
    
    // Размер экрана
    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;
    
    //Заставка загрузки
    Texture texthome;
    texthome.loadFromFile("Image/z1.png");
    RectangleShape homecls(Vector2f(640, 280));
    homecls.setTexture(&texthome);
    homecls.setPosition(Vector2f(width/4+50, height/3));
    window.draw(homecls);
    window.display();
    
    // Звуковые эффекты
    
      
    SoundBuffer buffer, buf_return;

    if (!buffer.loadFromFile("audio/audiomenu2.wav")) return 22;
    if (!buf_return.loadFromFile("audio/audiomenu5.wav")) return 22;
    Sound sound, sound_return;
    sound.setBuffer(buffer);
    sound_return.setBuffer(buf_return);

    Music music;
    if (!music.openFromFile("audio/horror.ogg")) return 25;
    music.setLoop(true);
    music.setVolume(50);
    music.play();

    Music musicF;
    if (!musicF.openFromFile("audio/faer.ogg")) return 28;
    musicF.setLoop(true);
    musicF.setVolume(50);
    musicF.play();


    // Координаты выравнивания текста
    float center[4]{ 0,-120,-20,-30 };
    // Название пунктов меню
    String name_menu[4]{ L"Старт",L"Настройки", L"О игре",L"Выход" };
    
    // Объект меню
    game::GameMenu mymenu(800, 350, 100, 120);
    // Установка цвета отображения меню
    mymenu.setColotTextMenu(Color(237, 147, 0), Color::Red, Color::Black);
    // Переименовываем пункты меню
    for (int i = 0; i < 4; i++) {
        mymenu.setPositionX(i, center[i]);
        mymenu.setStringMenu(i, name_menu[i]);
    }

    // Плавное появление из черного
    Texture texture_back;
    if (!texture_back.loadFromFile("image/t.jpg")) return 51;
    Sprite backgroundBlack;
    backgroundBlack.setColor(sf::Color(255, 255, 255, 255));
    backgroundBlack.setTexture(texture_back);
    backgroundBlack.setTextureRect(IntRect(0, 0, width, height));
    float alpha = 255;


    // Устанавливаем фон экрана меню
    RectangleShape background(Vector2f(width, height));

    Texture texture_window;
    if (!texture_window.loadFromFile("image/menu9.jpg")) return 4;
    background.setTexture(&texture_window);

    // Шрифт для названия экрана
    Font font;
    if (!font.loadFromFile("font/troika.otf")) return 5;
    // Текст с названием экрана
    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 480, 50, L"Апокалипсис", 150, Color(237, 147, 0), 3);

    
    // Анимация костра
    Vector2i spriteSize(300, 313);

    Sprite sprite;
    sprite.setPosition(440, 780);
    Animator animator(sprite);

    auto& idleAnimation = animator.CreateAnimation("Idle", "image/f.png", seconds(1), true);

    idleAnimation.AddFrames(Vector2i(0, 0), spriteSize, 5, 4);


    Clock clock;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed) window.close();

            if (event.type == Event::KeyReleased)
            {
                // События выбра пунктов меню
                if (event.key.code == Keyboard::Up) { sound.play(); mymenu.MoveUp(); }       // вверх
                if (event.key.code == Keyboard::Down) { sound.play(); mymenu.MoveDown(); }  // вниз
                if (event.key.code == Keyboard::Return)                                     // ввод
                {
                    music.pause(); musicF.pause();
                    sound_return.play();
                    // Переходим на выбранный пункт меню
                    switch (mymenu.getMainMenuPressed())
                    {
                    case 0:GamеStart(); break;
                    case 1:Options(); break;
                    case 2:About_Game();  break;
                    case 3:window.close(); break;
                    }
                    music.play(); musicF.play();
                }
            }
        }

        // Обновление анимации
        Time deltaTime = clock.restart();
        animator.Update(deltaTime);

        // Плавное осветление экрана меню
        if (alpha > 0)
        {
            alpha -= 0.05;
            backgroundBlack.setColor(Color(255, 255, 255, alpha));
        }

        // Область отрисовки объектов      
        window.clear();
        window.draw(background);
        window.draw(Titul);
        mymenu.draw(window);
        window.draw(sprite);
        window.draw(backgroundBlack);
        window.display();
    }
    return 0;
}

// функция настройки текста
void InitText(Text& mtext, float xpos, float ypos, String str, int size_font, Color menu_text_color, int bord, Color border_color )
{
    mtext.setCharacterSize(size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(menu_text_color);
    mtext.setOutlineThickness(bord);
    mtext.setOutlineColor(border_color);

}

// Игровой процесс
void GamеStart()
{
    RenderWindow Play(VideoMode::getDesktopMode(), L"Уровень 1", Style::Fullscreen);


    RectangleShape background_play(Vector2f(1920, 1080));

    Texture texture_play;
    if (!texture_play.loadFromFile("image/menu4.jpg")) exit(1);
    background_play.setTexture(&texture_play);

    while (Play.isOpen())
    {
        Event event_play;
        while (Play.pollEvent(event_play))
        {
            if (event_play.type == Event::KeyPressed)
            {
                if (event_play.key.code == Keyboard::Escape) { Play.close(); }
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
    RenderWindow Options(VideoMode::getDesktopMode(), L"Настройки", Style::Fullscreen);

    RectangleShape background_opt(Vector2f(1920, 1080));
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
    RenderWindow About(VideoMode::getDesktopMode(), L"О игре", Style::Fullscreen);

    RectangleShape background_ab(Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
    Texture texture_ab;
    if (!texture_ab.loadFromFile("image/menu2.jpg")) exit(3);
    background_ab.setTexture(&texture_ab);

    // Шрифт для названия экрана
    Font font;
    if (!font.loadFromFile("font/troika.otf")) exit(6);
    // Текст с названием экрана
    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 500, 50, L"Описание игры", 120, Color(237, 147, 0), 3);

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
        About.draw(Titul);
        About.display();
    }
}