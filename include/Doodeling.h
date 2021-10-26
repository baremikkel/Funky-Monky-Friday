/*#ifndef DOODELING_H
#define DOODELING_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Doodeling : public sf::Drawable, public sf::Transformable
{
public:
    Doodeling(std::string filename);
    ~Doodeling();

protected:

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the entity's transform -- combine it with the one that was passed by the caller
        states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

        // apply the texture
        states.texture = &texture;

        // you may also override states.shader or states.blendMode if you want

        // draw the vertex array
        target.draw(sprite, states);
    }
    sf::Sprite sprite;
    sf::Texture texture;


};

#endif // DOODELING_H
´*/


#ifndef DOODELING_H
#define DOODELING_H
#include <SFML/Graphics.hpp>
#include <string>
#include <init.h>

using namespace std;

class Doodeling : public sf::Sprite
{
public:
    Doodeling();
    ~Doodeling();

protected:

private:


};

#endif // DOODELING_H
