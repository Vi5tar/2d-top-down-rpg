#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>
#include "gameTile.cpp"
#include "gameWorld.cpp"
#include "mapName.h"

int main()
{
    GameWorld gameWorld = GameWorld(MapName::WORLD);

    int windowTileWidth = 25;
    int windowTileHeight = 25;
    int tileWidth = 48;
    int tileHeight = 48;
    float windowWidth = windowTileWidth * tileWidth;
    float windowHeight = windowTileHeight * tileHeight;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Dragon Warrior World Map");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        // Game logic and rendering code here
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                    gameWorld.movePlayerUp();
                if (event.key.code == sf::Keyboard::Down)
                    gameWorld.movePlayerDown();
                if (event.key.code == sf::Keyboard::Left)
                    gameWorld.movePlayerLeft();
                if (event.key.code == sf::Keyboard::Right)
                    gameWorld.movePlayerRight();
                if (event.key.code == sf::Keyboard::T)
                    gameWorld.setCurrentMap(MapName::TANTAGEL);
                if (event.key.code == sf::Keyboard::W)
                    gameWorld.setCurrentMap(MapName::WORLD);
            }
        }

        window.clear();

        //NOTE:: draw the world map
        int startDrawnWorldX = gameWorld.player->getX() - ((windowTileWidth / 2));
        int startDrawnWorldY = gameWorld.player->getY() - ((windowTileHeight / 2));
        for (int i = 0; i < windowTileHeight; i++)
        {
            for (int j = 0; j < windowTileWidth; j++)
            {
                if (gameWorld.currentMap.tiles.size() > (startDrawnWorldY + i) && gameWorld.currentMap.tiles[startDrawnWorldY + i].size() > (startDrawnWorldX + j))
                {
                    GameTile *tile = gameWorld.currentMap.tiles[startDrawnWorldY + i][startDrawnWorldX + j];
                    tile->sprite.setPosition(j * tileWidth, i * tileHeight);
                    window.draw(tile->sprite);
                } else {
                    // NOTE: this was causing massive cpu usage when outside the map boundaries were visible in the window
                    // GameTile *tile = GameTile::getTile(21);
                    // tile->sprite.setPosition(j * tileWidth, i * tileHeight);
                    // window.draw(tile->sprite);
                }
            }
        }

        //NOTE:: draw the player
        sf::Vector2f position((windowTileWidth / 2) * tileWidth, (windowTileHeight / 2) * tileHeight);
        int step = (int)std::round((std::chrono::duration_cast<std::chrono::milliseconds>(startTime.time_since_epoch()).count() / 100) / 3 % 2);
        gameWorld.player->setSprite(position, step);
        window.draw(gameWorld.player->sprite);

        window.display();
    }

    return 0;
}