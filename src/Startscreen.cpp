#include "Startscreen.h"
#include "init.h"

Startscreen::Startscreen(init& init)
{
    sf::Sprite logo;
    logo.setTexture(init.EkstraSprites[0]);
    EkstraSpritesS.push_back(logo);

    sf::Sprite monkel;
    monkel.setTexture(init.EkstraSprites[3]);
    EkstraSpritesS.push_back(monkel);

    sf::Sprite monker;
    monker.setTexture(init.EkstraSprites[4]);
    EkstraSpritesS.push_back(monker);
}

void Startscreen::Button(int x, int y, sf::RenderWindow& homescreen,int px, int py, int Button_text)
{
    EkstraSpritesS[0].setPosition(250,0);
    homescreen.draw(EkstraSpritesS[0]);
    int rn = rand() % 1500+1;
    if(timer.getElapsedTime().asMilliseconds()>= rn)
    {
        chance_monke = !chance_monke;
        timer.restart();
    }
    //EkstraSpritesS[1].setPosition(150,350);
    if(chance_monke)
    {
        EkstraSpritesS[1].setPosition(150,350);
        homescreen.draw(EkstraSpritesS[1]);
        EkstraSpritesS[2].setPosition(850,350);
        homescreen.draw(EkstraSpritesS[2]);
    }
    else
    {
        EkstraSpritesS[2].setPosition(150,350);
        homescreen.draw(EkstraSpritesS[2]);
        EkstraSpritesS[1].setPosition(850,350);
        homescreen.draw(EkstraSpritesS[1]);
    }

    sf::Font font;
    if(!font.loadFromFile("Comic.ttf"))
    {
        cout << "error" << endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setString(ButtonText[Button_text]);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color(215,66,245));
    text.setPosition(525,py+20);

    sf::RectangleShape rectangle(sf::Vector2f(x, y));
    rectangle.setFillColor(sf::Color(0,0,75));
    rectangle.setOutlineThickness(5);
    rectangle.setOutlineColor(sf::Color(215,66,245));
    rectangle.setPosition(px,py);


    sf::Vector2i mouseP = sf::Mouse::getPosition(homescreen);
    if(mouseP.x > px && mouseP.x < px+390 && mouseP.y > py && mouseP.y < py+100)
    {
        text.setFillColor(sf::Color(0,0,75));
        rectangle.setFillColor(sf::Color(215,66,245));
        rectangle.setOutlineColor(sf::Color(0,0,75));

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 425 && mouseP.x < 775 && mouseP.y > 205 && mouseP.y < 300)
        {
            startgame = true;
        }
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 425 && mouseP.x < 775 && mouseP.y > 380 && mouseP.y < 475)
        {
            settings = true;
        }
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseP.x > 425 && mouseP.x < 775 && mouseP.y > 555 && mouseP.y < 645)
        {
            homescreen.close();
        }
    }
    homescreen.draw(rectangle);
    homescreen.draw(text);
}
