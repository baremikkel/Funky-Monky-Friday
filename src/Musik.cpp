#include "Musik.h"

Musik::Musik()
{

}
Musik::~Musik()
{
    //dtor
}

Musik::StartMusik()
{
    if (!music.openFromFile("Music.ogg"))
    {
        // error...
    }

    music.setVolume(50.f);
    music.play();

}
