#ifndef MOVEARROW_H
#define MOVEARROW_H
#include <SFML/Graphics.hpp>
#include <init.h>
#include <vector>
#include <iostream>


using namespace std;

class MoveArrow
{
    public:
        MoveArrow(init& init);
       int DrawWhites(sf::RenderWindow& window);
       int DrawColor(sf::RenderWindow& window);
       int SetPositions();
       int Movearrow(sf::RenderWindow& window);
       void PlaceLine(int x, int xx, int y, int yy, int thicc, sf::RenderWindow& window);
       void PointSystem(sf::RenderWindow& window);
       int SpawnArrow();
       void TextDisplay(sf::RenderWindow& window);
       void SetText(sf::RenderWindow& window, int Csize, int px, int py, float display);
       vector<sf::Sprite> sprites_white;
       vector<sf::Sprite> sprites_color;
       vector<sf::Sprite> moving_sprites;
       sf::Texture texture;
       int points = 10;
       int lives = 3;
       float speed = 500;
       float distance = 0.6;
       bool ControlArrowK = false;
       sf::Font font;
       sf::Font font2;

       array<sf::Keyboard::Key,4> Keys {sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Right};
       array<bool,4> Keys_pressed {0,0,0,0};
       array<int, 4> xPosition{150,300,450,600};

    private:
        sf::Clock timer;
        sf::Clock Spawn_timer;
};

#endif // MOVEARROW_H
