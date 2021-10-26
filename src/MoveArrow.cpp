#include "MoveArrow.h"
#include <SFML/Graphics.hpp>
#include <Doodeling.h>
#include <vector>
#include <iostream>

MoveArrow::MoveArrow(init& init)
{
    sf::Sprite left;
    left.setTexture(init.textures_white[0]);
    sprites_white.push_back(left);

    sf::Sprite up;
    up.setTexture(init.textures_white[1]);
    sprites_white.push_back(up);

    sf::Sprite down;
    down.setTexture(init.textures_white[2]);
    sprites_white.push_back(down);

    sf::Sprite right;
    right.setTexture(init.textures_white[3]);
    sprites_white.push_back(right);

    sf::Sprite leftc;
    leftc.setTexture(init.textures_color[0]);
    sprites_color.push_back(leftc);

    sf::Sprite upc;
    upc.setTexture(init.textures_color[1]);
    sprites_color.push_back(upc);

    sf::Sprite downc;
    downc.setTexture(init.textures_color[2]);
    sprites_color.push_back(downc);

    sf::Sprite rightc;
    rightc.setTexture(init.textures_color[3]);
    sprites_color.push_back(rightc);

    if(!font.loadFromFile("Comic.ttf"))
    {
        cout << "fontload error" << endl;
    }
    if(!font2.loadFromFile("SourceSansPro-Black.ttf"))
    {
        cout << "font2 loaderror\n";
    }
}

int MoveArrow::DrawWhites(sf::RenderWindow& window)
{
    for(int i = 0; i < sprites_white.size(); i++)
    {
        window.draw(sprites_white[i]);
    }
}

int MoveArrow::DrawColor(sf::RenderWindow& window)
{
    //moving_sprites.push_back(sprites_color[rn]);
    for(int i = 0; i < moving_sprites.size(); i++)
    {
        window.draw(moving_sprites[i]);
    }
}
int MoveArrow::SetPositions()
{
    int x = 150;
    for(int i = 0; i < sprites_white.size(); i++)
    {
        sprites_color[i].setPosition(x,850);
        sprites_white[i].setPosition(x,50);
        x = x + 150;
    }
}
int MoveArrow::SpawnArrow()
{
    int rn = rand() % sprites_color.size();
    if(moving_sprites.size() == 0)
    {
        moving_sprites.push_back(sprites_color[rn]);
        Spawn_timer.restart();
    }
    //Afhængig af tiden
    sf::Time elapsed_time = Spawn_timer.getElapsedTime();
    if(elapsed_time.asSeconds() > distance)
    {
        moving_sprites.push_back(sprites_color[rn]);
        Spawn_timer.restart();
    }
}
int MoveArrow::Movearrow(sf::RenderWindow& window)
{
    SpawnArrow();
    DrawColor(window);
    sf::Time dt = timer.restart();
    for(int i = 0; i < moving_sprites.size(); i++)
    {
        moving_sprites[i].move(0,-speed*dt.asSeconds());
        PointSystem(window);
    }
}

void MoveArrow::PlaceLine(int x, int xx, int y, int yy, int thicc, sf::RenderWindow& window)
{
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(x,y)),
        sf::Vertex(sf::Vector2f(x+xx,y+yy))
    };
    window.draw(line, thicc, sf::Lines);
}
void MoveArrow::PointSystem(sf::RenderWindow& window)
{
    sf::Vector2f pSprite = moving_sprites[0].getPosition();
    if(pSprite.y < 130 && pSprite.y > 0)
    {
        for(int i = 0; i < 4; i++)
        {
            if(sf::Keyboard::isKeyPressed(Keys[i]) && pSprite.x == xPosition[i])
            {
                points += 10;
                moving_sprites.erase(moving_sprites.begin());
                Keys_pressed[i] = true;
                speed+=1.25;
            }
        }
    }
    else if(pSprite.y < -10)
    {
        moving_sprites.erase(moving_sprites.begin());
        cout << "missed\n";
        points -= 10;
        speed-=2.5;
    }
    TextDisplay(window);
}
void MoveArrow::SetText(sf::RenderWindow& window, int Csize, int px, int py, float display)
{
    string str = to_string(display);
    sf::Text text;
    text.setFont(font2);
    text.setString(str);
    text.setCharacterSize(Csize);
    text.setFillColor(sf::Color::White);
    text.setPosition(px,py);
    window.draw(text);
}
void MoveArrow::TextDisplay(sf::RenderWindow& window)
{
    SetText(window, 32, 800, 50, points);
    SetText(window, 16, 30, 50, speed);

}

