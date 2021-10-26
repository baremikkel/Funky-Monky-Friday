#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <Instillinger.h>
#include <MoveArrow.h>
#include <Startscreen.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <init.h>


using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(1200, 800), "Funky Monke Friday");
    init textures;
    MoveArrow arrow(textures);
    Startscreen start(textures);
    Instillinger options(textures);
    arrow.SetPositions();


    if (!options.music.openFromFile("Music.ogg"))
    {
        cout << "error" << endl;
    }
    options.music.setVolume(50.f);
    bool musicisplaying = false;


    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        if(start.startgame)
        {
            if(!musicisplaying)
            {
                options.music.play();
                musicisplaying = true;
            }
            if(options.ControlArrowK)
            {
                arrow.Keys = {sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Right};
            }
            else
            {
                arrow.Keys = {sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::D};
            }

            arrow.PlaceLine(150, 525, 140, 0, 2, window);
            arrow.PlaceLine(150, 525, 40, 0, 2, window);
            arrow.DrawWhites(window);
            arrow.SpawnArrow();
            arrow.Movearrow(window);

        }
        else if(start.settings)
        {
            options.Overskrift(window, 3, 150, arrow,start);
        }
        else{

            int py = 220;
            for(int i = 0; i < 3; i++)
            {
                start.Button(350,100,window,425,py,i);
                py +=175;

            }
        }
        window.display();
    }
    return 0;
}
