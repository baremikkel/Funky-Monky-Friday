#include "Instillinger.h"
#include "MoveArrow.h"

Instillinger::Instillinger(init& init)
{
    ConfirmCircle_difficulty.setFillColor(sf::Color(7,245,241));
    ConfirmCircle_difficulty.setPosition(151.75,291.75);

    ConfirmCircle_music.setFillColor(sf::Color(7,245,241));
    ConfirmCircle_music.setPosition(600, 340);

    ConfirmCircle_controls.setFillColor(sf::Color(7,245,241));
    ConfirmCircle_controls.setPosition(851.75, 261.75);

    sf::Sprite tilbagePil;
    tilbagePil.setTexture(init.EkstraSprites[1]);
    EkstraSpritesI.push_back(tilbagePil);

    sf::Sprite tilbagePil2;
    tilbagePil2.setTexture(init.EkstraSprites[2]);
    EkstraSpritesI.push_back(tilbagePil2);

    if(!font.loadFromFile("Comic.ttf"))
    {
        cout << "fontload error" << endl;
    }
}
void Instillinger::Overskrift(sf::RenderWindow& window, int Otext, int px, MoveArrow& ma, Startscreen& ss)
{
    //Tegner Overskriften
    sf::Text h1;
    h1.setFont(font);
    h1.setString("Options");
    h1.setCharacterSize(70);
    h1.setFillColor(sf::Color(215,66,245));
    h1.setPosition(450,20);
    window.draw(h1);

    EkstraSpritesI[0].setPosition(0,0);
    window.draw(EkstraSpritesI[0]);

    sf::Vector2i mouseP = sf::Mouse::getPosition(window);
    if(mouseP.x > 0 && mouseP.x < 280 && mouseP.y > 0 && mouseP.y < 78)
    {
        EkstraSpritesI[1].setPosition(0,0);
        window.draw(EkstraSpritesI[1]);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            ss.settings = false;
        }
    }

    //Tegner Instilling overskrift
    for(int i = 0; i < Otext; i++)
    {
        sf::Text OT;
        OT.setFont(font);
        OT.setString(optionText[i]);
        OT.setCharacterSize(32);
        OT.setStyle(sf::Text::Underlined);
        OT.setFillColor(sf::Color(215,66,245));
        OT.setPosition(px,200);
        window.draw(OT);
        px+=350;
    }
    Difficulty(window,15, 150, 260, ma, ss);
    Music_volume(window, ma, ss);
    Controls(window, 15, 850, 260, ma, ss);
}
void Instillinger::DrawBox(sf::RenderWindow& window, int Size, int px, int py, MoveArrow& ma, Startscreen& ss)
{
    sf::RectangleShape box(sf::Vector2f(Size,Size));
    box.setOutlineThickness(4);
    box.setFillColor(sf::Color::Black);
    box.setOutlineColor(sf::Color::Magenta);
    box.setPosition(px,py);
    window.draw(box);
}
void Instillinger::Difficulty(sf::RenderWindow& window, int Size, int px, int py, MoveArrow& ma, Startscreen& ss)
{
    for(int i = 0; i < diffText.size(); i++)
    {
        sf::Text box_text;

        box_text.setFont(font);
        box_text.setString(diffText[i]);
        box_text.setCharacterSize(20);
        box_text.setFillColor(sf::Color::Magenta);
        box_text.setPosition(180,py-5);
        window.draw(box_text);

        DrawBox(window, 15, 150, py, ma, ss);
        py += 30;
    }
    sf::Vector2i mouseP = sf::Mouse::getPosition(window);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 145 && mouseP.x < 167 && mouseP.y > 255 && mouseP.y < 278)
    {

        ConfirmCircle_difficulty.setPosition(151.75,261.75);
        ma.distance = 1;

    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 145 && mouseP.x < 167 && mouseP.y > 288 && mouseP.y < 308)
    {

        ConfirmCircle_difficulty.setPosition(151.75,291.75);
        ma.distance = 0.5;

    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 145 && mouseP.x < 167 && mouseP.y > 315 && mouseP.y < 338)
    {

        ConfirmCircle_difficulty.setPosition(151.75,321.75);
        ma.distance = 0.3;

    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 145 && mouseP.x < 167 && mouseP.y > 345 && mouseP.y < 368)
    {

        ConfirmCircle_difficulty.setPosition(151.75,351.75);
        ma.distance = 0.2;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        ss.settings = false;
    }
    window.draw(ConfirmCircle_difficulty);

}

void Instillinger::Music_volume (sf::RenderWindow& window, MoveArrow& ma, Startscreen& ss)
{

    ma.PlaceLine(500, 200, 350, 0, 2, window);
    sf::Vector2i mouseP = sf::Mouse::getPosition(window);
    sf::Text volumeT;
    int volume = -(minimum-mouseP.x)/2;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&& mouseP.x < maximum+2 && mouseP.x > minimum-2 && mouseP.y < 370 && mouseP.y > 340)
    {
        ConfirmCircle_music.setPosition(mouseP.x, 340);

        if(-(minimum-mouseP.x)/2 > 100)
        {
            volume = 100;
        }
        if(-(minimum-mouseP.x)/2 < 0)
        {
            volume = 0;
        }
        music.setVolume(volume);
        string str = to_string(volume);
        volumeT.setFont(font);
        volumeT.setString(str);
        volumeT.setCharacterSize(20);
        volumeT.setFillColor(sf::Color::Magenta);
        volumeT.setPosition(590, 350);


    }

 window.draw(volumeT);
/*
    for(int i = 0; i < musicText.size(); i++)
    {
        sf::Text box_text;

        box_text.setFont(font);
        box_text.setString(musicText[i]);
        box_text.setCharacterSize(20);
        box_text.setFillColor(sf::Color::Magenta);
        box_text.setPosition(530,py-5);
        window.draw(box_text);

        DrawBox(window, 15, 500, py, ma, ss);
        py += 30;
    }

    sf::Vector2i mouseP = sf::Mouse::getPosition(window);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 500 && mouseP.x < 515 && mouseP.y > 255 && mouseP.y < 278)
    {

        ConfirmCircle_music.setPosition(500.75,261.75);
        music.setVolume(25.f);

    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 500 && mouseP.x < 515 && mouseP.y > 288 && mouseP.y < 308)
    {

        ConfirmCircle_music.setPosition(500.75,291.75);
        music.setVolume(50.f);

    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 500 && mouseP.x < 515 && mouseP.y > 315 && mouseP.y < 338)
    {

        ConfirmCircle_music.setPosition(500.75,321.75);
        music.setVolume(75.f);

    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 500 && mouseP.x < 515 && mouseP.y > 345 && mouseP.y < 368)
    {

        ConfirmCircle_music.setPosition(500.75,351.75);
        music.setVolume(100.f);

    }*/
    window.draw(ConfirmCircle_music);
}

void Instillinger::Controls(sf::RenderWindow& window, int Size, int px, int py, MoveArrow& ma, Startscreen& ss)
{
    for(int i = 0; i < 2; i++)
    {
        sf::Text box_text;

        box_text.setFont(font);
        box_text.setString(controlText[i]);
        box_text.setCharacterSize(20);
        box_text.setFillColor(sf::Color::Magenta);
        box_text.setPosition(880,py-5);
        window.draw(box_text);

        DrawBox(window, Size, px, py, ma, ss);
        py += 60;
    }
    sf::Vector2i mouseP = sf::Mouse::getPosition(window);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 850 && mouseP.x < 875 && mouseP.y > 255 && mouseP.y < 278)
    {
        ConfirmCircle_controls.setPosition(851.75, 261.75);
        ControlArrowK = false;
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 850 && mouseP.x < 875 && mouseP.y > 315 && mouseP.y < 338)
    {
        ConfirmCircle_controls.setPosition(851.75, 321.75);
        ControlArrowK = true;
    }
    window.draw(ConfirmCircle_controls);
}
