#include "door.h"

Door::Door(std::string texturePath, bool open) : GameTile(texturePath, open)
{
    this->open = open;
}