#include <SFML/Graphics.hpp>
#include "../player/direction.h"
#include "mapName.h"

#ifndef LOCATION_H
#define LOCATION_H

class Location
{
public:
    MapName mapName;
    sf::Vector2u position;
    Direction orientation;
    Location(MapName, sf::Vector2u, Direction);
    //HACK: This gets rid of a "No default constructor exists for class Location" error but I'm not sure if there are unwanted side effects.
    Location() = default;
};

#endif