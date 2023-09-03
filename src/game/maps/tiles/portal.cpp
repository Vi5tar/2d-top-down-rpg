#include "portal.h"

Portal::Portal(std::string texturePath, bool walkable, Location destination) : GameTile(texturePath, walkable)
{
    this->destination = destination;
}

bool Portal::isPortal()
{
    return true;
}