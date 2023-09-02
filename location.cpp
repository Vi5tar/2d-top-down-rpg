#include "location.h"

Location::Location(MapName mapName, sf::Vector2u position, Direction orientation)
{
    this->mapName = mapName;
    this->position = position;
    this->orientation = orientation;
}