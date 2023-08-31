#include "mapFactory.h"
#include "map.cpp"

Map MapFactory::getMap(MapName mapName)
{
    switch (mapName)
    {
        case MapName::WORLD:
            return Map("dw-world-map.txt");
        case MapName::TANTAGEL:
            return Map("dw-tantagel-castle-map.txt");
    }
}