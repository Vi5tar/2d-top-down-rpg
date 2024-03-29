#include "garinsGrave3.h"

GarinsGrave3::GarinsGrave3()
{
    name = MapName::GARINS_GRAVE_3;
    layout = {
        {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,},
        {50,51,51,51,50,51,51,51,50,51,51,51,51,51,51,51,51,50,51,51,51,50,},
        {50,51,55,51,50,51,51,51,51,51,50,51,50,51,50,56,51,50,51,56,51,50,},
        {50,51,51,51,50,51,50,50,50,50,50,51,51,51,51,51,51,50,51,51,51,50,},
        {50,51,50,50,50,51,50,51,50,51,50,50,50,50,50,50,50,50,50,50,50,50,},
        {50,51,50,51,51,51,50,51,51,51,51,50,50,51,51,51,50,50,51,51,51,50,},
        {50,51,50,51,50,50,50,51,50,51,57,50,51,51,51,51,51,50,50,50,51,50,},
        {50,51,51,51,50,51,51,51,50,50,50,50,51,51,55,51,51,50,51,50,51,50,},
        {50,51,50,50,50,51,50,51,50,51,50,50,51,51,51,51,51,50,51,50,51,50,},
        {50,51,50,51,50,51,50,51,50,51,50,51,51,51,51,51,50,50,51,51,51,50,},
        {50,51,50,51,50,51,51,51,50,51,50,57,51,50,50,50,50,50,51,50,51,50,},
        {50,51,50,51,50,51,50,50,50,51,50,50,50,50,51,50,51,51,51,50,51,50,},
        {50,51,50,51,50,51,50,56,51,51,51,51,51,51,51,50,51,51,50,50,51,50,},
        {50,51,50,51,50,51,50,50,50,50,50,50,50,50,50,50,50,51,50,51,51,50,},
        {50,51,50,51,50,51,50,51,51,51,51,50,51,51,51,51,51,51,50,56,51,50,},
        {50,51,50,51,51,51,50,51,51,50,51,50,51,50,50,50,51,50,50,50,51,50,},
        {50,51,50,50,51,51,50,51,51,50,51,50,51,51,51,51,51,50,51,51,51,50,},
        {50,51,50,51,51,50,50,50,50,50,51,50,50,50,50,50,51,50,51,50,51,50,},
        {50,51,50,56,51,51,51,51,51,51,51,50,51,51,51,51,51,50,51,50,51,50,},
        {50,51,50,50,50,50,50,50,50,50,50,50,50,50,50,50,51,50,50,50,51,50,},
        {50,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,50,},
        {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,},
    };
    portals = {
        {{19, 2}, Location(MapName::GARINS_GRAVE_2, sf::Vector2u(13, 2), Direction::LEFT)},
        {{15, 2}, Location(MapName::GARINS_GRAVE_2, sf::Vector2u(2, 2), Direction::LEFT)},
        {{3, 18}, Location(MapName::GARINS_GRAVE_2, sf::Vector2u(2, 11), Direction::LEFT)},
        {{10, 6}, Location(MapName::GARINS_GRAVE_4, sf::Vector2u(1, 5), Direction::RIGHT)},
        {{11, 10}, Location(MapName::GARINS_GRAVE_4, sf::Vector2u(6, 5), Direction::RIGHT)},
        {{19, 14}, Location(MapName::GARINS_GRAVE_2, sf::Vector2u(13, 11), Direction::LEFT)},
        {{7, 12}, Location(MapName::GARINS_GRAVE_2, sf::Vector2u(6, 7), Direction::LEFT)}
    };
};