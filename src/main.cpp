#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>
#include "game/maps/tiles/gameTile.cpp"
#include "game/maps/tiles/portal.h"
#include "game/game.cpp"
#include "game/maps/mapName.h"
#include "windowConfig.h"
#include "game/maps/location.cpp"

int main()
{
    bool devMode = false;

    Game game = Game(Location(MapName::TANTAGEL_THRONE_ROOM, sf::Vector2u(4, 5), Direction::UP));
    if (devMode)
        game.loadState();

    sf::Vector2u tileSize = game.currentMap.tiles.begin()->second->sprite.getTexture()->getSize();
    sf::Vector2f scaledTileSize(tileSize.x * SCALE_X, tileSize.y * SCALE_Y);
    float windowWidth = WINDOW_TILES_WIDE * scaledTileSize.x;
    float windowHeight = WINDOW_TILES_HIGH * scaledTileSize.y;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Dragon Warrior World Map");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        // Game logic and rendering code here
        if (game.currentMap.tiles[{game.player->getX(), game.player->getY()}]->isPortal() && game.player->hasMoved)
        {
            Portal *portal = (Portal *)game.currentMap.tiles[{game.player->getX(), game.player->getY()}];
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
                
                if (event.key.code == sf::Keyboard::S && devMode)
                    game.saveState();
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
                if (game.currentMap.tiles.find({startDrawnWorldX + j, startDrawnWorldY + i}) != game.currentMap.tiles.end() && game.currentMap.layout.size() > (startDrawnWorldY + i) && game.currentMap.layout[startDrawnWorldY + i].size() > (startDrawnWorldX + j))
                {
                    GameTile *tile = game.currentMap.tiles[{startDrawnWorldX + j, startDrawnWorldY + i}];
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

        if (devMode)
        {
            //NOTE:: draw the player's coordinates
            sf::Font font;
            font.loadFromFile(FONT_DIRECTORY + "/ensign-flandry-font/EnsignFlandry-3zda8.ttf");
            sf::Text text2;
            text2.setFont(font);
            text2.setString(std::to_string(game.player->getX()) + ", " + std::to_string(game.player->getY()));
            text2.setFillColor(sf::Color::White);
            window.draw(text2);
        }

        window.display();
    }

    return 0;
}