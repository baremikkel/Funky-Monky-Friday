#ifndef INIT_H
#define INIT_H
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class init
{
    public:
        init();
        virtual ~init();

    vector<sf::Texture> textures_white;
    vector<sf::Texture> textures_color;
    vector<sf::Texture> EkstraSprites;
    protected:

    private:

};

#endif // INIT_H
