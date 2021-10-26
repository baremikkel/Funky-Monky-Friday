#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <init.h>



using namespace std;

class Startscreen
{
public:
    Startscreen(init& init);
    void Button(int x, int y, sf::RenderWindow& homescreen, int px, int py, int Button_text);
    vector<string> ButtonText = {"Start","Options","Exit"};
    bool startgame = false;
    bool settings = false;
    bool chance_monke = false;
    vector<sf::Sprite> EkstraSpritesS                                                   ;
private:
    sf::Clock timer;
};

#endif // STARTSCREEN_H
