#ifndef INSTILLINGER_H
#define INSTILLINGER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <MoveArrow.h>
#include <Startscreen.h>
#include <init.h>

using namespace std;

class Instillinger
{
    public:
        Instillinger(init& init);
        void Overskrift(sf::RenderWindow& window, int Otext, int px, MoveArrow& ma, Startscreen& ss);
        void Difficulty(sf::RenderWindow& window, int Size, int px, int py, MoveArrow& ma, Startscreen& ss);
        void DrawBox(sf::RenderWindow& window, int Size, int px, int py, MoveArrow& ma, Startscreen& ss);
        void Music_volume(sf::RenderWindow& window, MoveArrow& ma, Startscreen& ss);
        void Controls(sf::RenderWindow& window, int Size, int px, int py, MoveArrow& ma, Startscreen& ss);
        vector<string> optionText = {"Difficulty:", "Music Volume:", "Controls:"};
        vector<string> diffText = {"Easy","Medium","Hard","E X T R E M E"};
        vector<string> musicText = {"25%","50%","75%","100%"};
        vector<string> controlText = {"WASD Keys","Arrow Keys"};
        vector<sf::Sprite> EkstraSpritesI;
        sf::CircleShape ConfirmCircle_difficulty{5};
        sf::CircleShape ConfirmCircle_music{10};
        sf::CircleShape ConfirmCircle_controls{5};
        sf::Font font;
        bool ControlArrowK = false;

        // MUSIK
        int minimum = 500;
        int maximum = 700;
        int circleposition = (500/100)*50;

        sf::Music music;

    protected:

    private:
};

#endif // INSTILLINGER_H
