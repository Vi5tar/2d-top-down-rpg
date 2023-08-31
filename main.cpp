#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>
#include "gameTile.cpp"
#include "gameWorld.cpp"
#include "mapName.h"
#include "windowConfig.h"

int main()
{
    GameWorld gameWorld = GameWorld(MapName::WORLD);

    sf::Vector2u tileSize = gameWorld.currentMap.tiles[0][0]->sprite.getTexture()->getSize();
    sf::Vector2f scaledTileSize(tileSize.x * SCALE_X, tileSize.y * SCALE_Y);
    float windowWidth = WINDOW_TILES_WIDE * scaledTileSize.x;
    float windowHeight = WINDOW_TILES_HIGH * scaledTileSize.y;

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
        int startDrawnWorldX = gameWorld.player->getX() - ((WINDOW_TILES_WIDE / 2));
        int startDrawnWorldY = gameWorld.player->getY() - ((WINDOW_TILES_HIGH / 2));
        for (int i = 0; i < WINDOW_TILES_HIGH; i++)
        {
            for (int j = 0; j < WINDOW_TILES_WIDE; j++)
            {
                if (gameWorld.currentMap.tiles.size() > (startDrawnWorldY + i) && gameWorld.currentMap.tiles[startDrawnWorldY + i].size() > (startDrawnWorldX + j))
                {
                    GameTile *tile = gameWorld.currentMap.tiles[startDrawnWorldY + i][startDrawnWorldX + j];
                    tile->sprite.setPosition(j * scaledTileSize.x, i * scaledTileSize.y);
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
        sf::Vector2f position((WINDOW_TILES_WIDE / 2) * scaledTileSize.x, (WINDOW_TILES_HIGH / 2) * scaledTileSize.y);
        int step = (int)std::round((std::chrono::duration_cast<std::chrono::milliseconds>(startTime.time_since_epoch()).count() / 100) / 3 % 2);
        gameWorld.player->setSprite(position, step);
        window.draw(gameWorld.player->sprite);

        window.display();
    }

    return 0;
}