#ifndef SPRITE_CONTAINER_H
#define SPRITE_CONTAINER_H
#include <iostream>
#include <Doodeling.h>


class Sprite_container
{
    public:
        Sprite_container();
        virtual ~Sprite_container();

    protected:

    private:
        vector<Doodeling>sprites_white;
        vector<Doodeling>sprites_color;

};

#endif // SPRITE_CONTAINER_H
