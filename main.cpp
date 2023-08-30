#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>
#include "gameTile.cpp"
#include "gameWorld.cpp"

int main()
{
    GameWorld gameWorld = GameWorld();

    const double targetFPS = 60.0;
    const double targetFrameTime = 1.0 / targetFPS;

    int windowTileWidth = 25;
    int windowTileHeight = 25;
    int tileWidth = 48;
    int tileHeight = 48;
    float windowWidth = windowTileWidth * tileWidth;
    float windowHeight = windowTileHeight * tileHeight;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Dragon Warrior World Map");

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
                if (gameWorld.worldMap.size() > (startDrawnWorldY + i) && gameWorld.worldMap[startDrawnWorldY + i].size() > (startDrawnWorldX + j))
                {
                    GameTile *tile = gameWorld.worldMap[startDrawnWorldY + i][startDrawnWorldX + j];
                    tile->sprite.setPosition(j * tileWidth, i * tileHeight);
                    window.draw(tile->sprite);
                } else {
                    GameTile *tile = GameTile::getTile(21);
                    tile->sprite.setPosition(j * tileWidth, i * tileHeight);
                    window.draw(tile->sprite);
                }
            }
        }

        //NOTE:: draw the player
        sf::Vector2f position((windowTileWidth / 2) * tileWidth, (windowTileHeight / 2) * tileHeight);
        int step = (int)std::round((std::chrono::duration_cast<std::chrono::milliseconds>(startTime.time_since_epoch()).count() / 100) / 3 % 2);
        gameWorld.player->setSprite(position, step);
        window.draw(gameWorld.player->sprite);

        window.display();

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> frameDuration = endTime - startTime;

        // Calculate the time to sleep to achieve the target frame time
        double sleepTime = targetFrameTime - frameDuration.count();
        if (sleepTime > 0)
        {
            std::this_thread::sleep_for(std::chrono::duration<double>(sleepTime));
        }
    }

    return 0;
}