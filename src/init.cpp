#include "init.h"

init::init()
{
    sf::Texture left;
    left.loadFromFile("Sprites/Left.png");
    textures_white.push_back(left);

    sf::Texture up;
    up.loadFromFile("Sprites/Up.png");
    textures_white.push_back(up);

    sf::Texture down;
    down.loadFromFile("Sprites/Down.png");
    textures_white.push_back(down);

    sf::Texture right;
    right.loadFromFile("Sprites/Right.png");
    textures_white.push_back(right);


    sf::Texture leftc;
    leftc.loadFromFile("Sprites/Leftc.png");
    textures_color.push_back(leftc);

    sf::Texture upc;
    upc.loadFromFile("Sprites/Upc.png");
    textures_color.push_back(upc);

    sf::Texture downc;
    downc.loadFromFile("Sprites/Downc.png");
    textures_color.push_back(downc);

    sf::Texture rightc;
    rightc.loadFromFile("Sprites/Rightc.png");
    textures_color.push_back(rightc);

    //----------------------------------------------------

    sf::Texture logo;
    logo.loadFromFile("Sprites/Logo.png");
    EkstraSprites.push_back(logo);

    //----------------------------------------------------

    sf::Texture TilbagePil;
    TilbagePil.loadFromFile("Sprites/Tilbage_pil.png");
    EkstraSprites.push_back(TilbagePil);

    sf::Texture TilbagePil2;
    TilbagePil2.loadFromFile("Sprites/Tilbage_pilLightup.png");
    EkstraSprites.push_back(TilbagePil2);


    sf::Texture monkel;
    monkel.loadFromFile("Sprites/Monke2.png");
    EkstraSprites.push_back(monkel);

    sf::Texture monker;
    monker.loadFromFile("Sprites/Monke.png");
    EkstraSprites.push_back(monker);

}

init::~init()
{
    //dtor
}
