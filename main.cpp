#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>
#include "gameTile.cpp"
#include "game.cpp"
#include "mapName.h"
#include "windowConfig.h"
#include "location.cpp"

int main()
{
    Game game = Game(Location(MapName::TANTAGEL_THRONE_ROOM, sf::Vector2u(4, 5), Direction::UP));

    sf::Vector2u tileSize = game.currentMap.tiles[0][0]->sprite.getTexture()->getSize();
    sf::Vector2f scaledTileSize(tileSize.x * SCALE_X, tileSize.y * SCALE_Y);
    float windowWidth = WINDOW_TILES_WIDE * scaledTileSize.x;
    float windowHeight = WINDOW_TILES_HIGH * scaledTileSize.y;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Dragon Warrior World Map");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        // Game logic and rendering code here
        if (game.currentMap.tiles[game.player->getY()][game.player->getX()]->isPortal() && game.player->hasMoved)
        {
            Portal *portal = (Portal *)game.currentMap.tiles[game.player->getY()][game.player->getX()];
            game.setPlayerLocation(portal->destination);
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                    game.movePlayerUp();
                if (event.key.code == sf::Keyboard::Down)
                    game.movePlayerDown();
                if (event.key.code == sf::Keyboard::Left)
                    game.movePlayerLeft();
                if (event.key.code == sf::Keyboard::Right)
                    game.movePlayerRight();
            }
        }

        window.clear();

        //NOTE:: draw the world map
        int startDrawnWorldX = game.player->getX() - ((WINDOW_TILES_WIDE / 2));
        int startDrawnWorldY = game.player->getY() - ((WINDOW_TILES_HIGH / 2));
        for (int i = 0; i < WINDOW_TILES_HIGH; i++)
        {
            for (int j = 0; j < WINDOW_TILES_WIDE; j++)
            {
                if (game.currentMap.tiles.size() > (startDrawnWorldY + i) && game.currentMap.tiles[startDrawnWorldY + i].size() > (startDrawnWorldX + j))
                {
                    GameTile *tile = game.currentMap.tiles[startDrawnWorldY + i][startDrawnWorldX + j];
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
        game.player->setSprite(position, step);
        window.draw(game.player->sprite);

        window.display();
    }

    return 0;
}