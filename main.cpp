#include <SFML/Graphics.hpp>
#include"GameMenu.h"
#include<SFML/Audio.hpp>
#include "Animator.h"
#include<Windows.h>

using namespace sf;

struct TextFormat
{
    int size_font = 60;
    Color menu_text_color = Color::White;
    float bord = 0.0f;
    Color border_color = Color::Black;
};

// ??????? ????????? ??????
void InitText(Text& mtext, float xpos, float ypos, const String & str,TextFormat Ftext);

// ??????? ???????
void Gam?Start();

// ????????? ????
void Options();

// ???????? ????
void About_Game();



int main()
{
    AssetManager manager;
    // ??????? ???? windows
    RenderWindow window;
    window.create(VideoMode::getDesktopMode(), L"??? ????", Style::Fullscreen);

    // ?????? ???? windows ??????????
    SetWindowLong(window.getSystemHandle(), GWL_EXSTYLE, GetWindowLong(window.getSystemHandle(), GWL_EXSTYLE) | WS_EX_LAYERED);
    SetLayeredWindowAttributes(window.getSystemHandle(), 0, 0, LWA_COLORKEY);

    window.setMouseCursorVisible(false); //????????? ????????? ???????

    // ?????? ??????
    auto width = static_cast<float>(VideoMode::getDesktopMode().width);
    auto height = static_cast<float>(VideoMode::getDesktopMode().height);

    //???????? ????????
    Texture texthome;
    texthome.loadFromFile("Image/z1.png");
    RectangleShape homecls(Vector2f(640, 280));
    homecls.setTexture(&texthome);
    homecls.setPosition(Vector2f(width / 2 - homecls.getLocalBounds().width/2, height / 2- homecls.getLocalBounds().height/2));
    window.draw(homecls);
    window.display();

    // ???????? ???????
    SoundBuffer buffer;
    SoundBuffer buf_return;

    if (!buffer.loadFromFile("audio/audiomenu2.wav")) return 22;
    if (!buf_return.loadFromFile("audio/audiomenu5.wav")) return 22;
    Sound sound;
    Sound sound_return;
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


    // ???????? ??????? ????
    std::vector<String> name_menu{ L"?????",L"?????????", L"? ????",L"?????" };

    // ?????? ????
    game::GameMenu mymenu(window, 950, 350, 100, 120,name_menu);
    // ????????? ????? ??????????? ????
    mymenu.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black);
    mymenu.AlignMenu(2);

    // ??????? ????????? ?? ???????
    Texture texture_back;
    if (!texture_back.loadFromFile("image/t.jpg")) return 51;
    Sprite backgroundBlack;
    backgroundBlack.setColor(sf::Color(255, 255, 255, 255));
    backgroundBlack.setTexture(texture_back);
    backgroundBlack.setTextureRect(IntRect(0, 0, static_cast<int>(width), static_cast<int>(height)));
    float alpha = 255;


    // ????????????? ??? ?????? ????
    RectangleShape background(Vector2f(width, height));

    Texture texture_window;
    if (!texture_window.loadFromFile("image/menu9.jpg")) return 4;
    background.setTexture(&texture_window);

    // ????? ??? ???????? ??????
    Font font;
    if (!font.loadFromFile("font/troika.otf")) return 5;
    // ????? ? ????????? ??????
    Text Titul;
    Titul.setFont(font);
    TextFormat Ftext;
    Ftext.size_font = 150;
    Ftext.menu_text_color = Color(237, 147, 0);
    Ftext.bord = 3;
    InitText(Titul, 480, 50, L"???????????", Ftext);


    // ???????? ??????
    Vector2i spriteSize(300, 313);

    Sprite sprite;
    sprite.setPosition(440, 780);
    Animator animator(sprite);

    auto& idleAnimation = animator.CreateAnimation("Idle", "image/f.png", seconds(1), true);

    idleAnimation.AddFrames(Vector2i(0, 0), spriteSize, 5, 4);


    Clock clock;
    SetLayeredWindowAttributes(window.getSystemHandle(), 100, 0, LWA_COLORKEY);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::KeyReleased)
            {
                // ??????? ????? ??????? ????
                if (event.key.code == Keyboard::Up) { sound.play(); mymenu.MoveUp(); }       // ?????
                if (event.key.code == Keyboard::Down) { sound.play(); mymenu.MoveDown(); }  // ????
                if (event.key.code == Keyboard::Return)                                     // ????
                {
                    music.pause(); musicF.pause();
                    sound_return.play();
                    // ????????? ?? ????????? ????? ????
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0:Gam?Start();  break;
                    case 1:Options();     break;
                    case 2:About_Game();  break;
                    case 3:window.close(); break;
                    default:break;
                    }
                    music.play(); musicF.play();
                }
            }
        }

        // ?????????? ????????
        Time deltaTime = clock.restart();
        animator.Update(deltaTime);

        // ??????? ?????????? ?????? ????
        if (alpha > 0)
        {
            alpha -= 0.05f;
            backgroundBlack.setColor(Color(255, 255, 255, static_cast<unsigned char>(alpha)));
        }

        // ??????? ????????? ????????      
        window.clear();
        window.draw(background);
        window.draw(Titul);
        mymenu.draw();
        window.draw(sprite);
        window.draw(backgroundBlack);
        window.display();
    }
    return 0;
}

// ??????? ????????? ??????
void InitText(Text& mtext, float xpos, float ypos, const String & str, TextFormat Ftext)
{
    mtext.setCharacterSize(Ftext.size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(Ftext.menu_text_color);
    mtext.setOutlineThickness(Ftext.bord);
    mtext.setOutlineColor(Ftext.border_color);

}

// ??????? ???????
void Gam?Start()
{
    RenderWindow Play(VideoMode::getDesktopMode(), L"??????? 1", Style::Fullscreen);


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

// ????????? ????
void Options()
{
    RenderWindow Options(VideoMode::getDesktopMode(), L"?????????", Style::Fullscreen);

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

// ???????? ????
void About_Game()
{
    RenderWindow About(VideoMode::getDesktopMode(), L"? ????", Style::Fullscreen);

    RectangleShape background_ab(Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
    Texture texture_ab;
    if (!texture_ab.loadFromFile("image/menu2.jpg")) exit(3);
    background_ab.setTexture(&texture_ab);

    // ????? ??? ???????? ??????
    Font font;
    if (!font.loadFromFile("font/troika.otf")) exit(6);
    // ????? ? ????????? ??????
    Text Titul;
    Titul.setFont(font);
    TextFormat Ftext;
    Ftext.size_font = 120;
    Ftext.menu_text_color = Color(237, 147, 0);
    Ftext.bord = 3;
    InitText(Titul, 500, 50, L"???????? ????", Ftext);

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