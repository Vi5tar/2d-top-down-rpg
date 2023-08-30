#include "gameWorld.h"
#include "gameTile.h"
#include "player.cpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

GameWorld::GameWorld()
{
    player = new Player();
    buildWorldMap();
}

bool GameWorld::canMove(Player *player, Direction direction)
{
    int playerX = player->getX();
    int playerY = player->getY();
    if (direction == Direction::LEFT)
    {
        if (playerX - 1 >= 0)
        {
            if (worldMap[playerY][playerX - 1]->isWalkable())
                return true;
        }
    }
    else if (direction == Direction::RIGHT)
    {
        if (playerX + 1 < worldMap[playerY].size())
        {
            if (worldMap[playerY][playerX + 1]->isWalkable())
                return true;
        }
    }
    else if (direction == Direction::UP)
    {
        if (playerY - 1 >= 0)
        {
            if (worldMap[playerY - 1][playerX]->isWalkable())
                return true;
        }
    }
    else if (direction == Direction::DOWN)
    {
        if (playerY + 1 < worldMap.size())
        {
            if (worldMap[playerY + 1][playerX]->isWalkable())
                return true;
        }
    }
    return false;
}

void GameWorld::movePlayerLeft()
{
    player->setOrientation(Direction::LEFT);
    if (canMove(player, Direction::LEFT))
        player->moveLeft();
}

void GameWorld::movePlayerRight()
{
    player->setOrientation(Direction::RIGHT);
    if (canMove(player, Direction::RIGHT))
        player->moveRight();
}

void GameWorld::movePlayerUp()
{
    player->setOrientation(Direction::UP);
    if (canMove(player, Direction::UP))
        player->moveUp();
}

void GameWorld::movePlayerDown()
{
    player->setOrientation(Direction::DOWN);
    if (canMove(player, Direction::DOWN))
        player->moveDown();
}

void GameWorld::buildWorldMap()
{
    std::ifstream world("dw-world-map.txt");
    for(std::string line; getline(world, line);)
    {
        std::stringstream ss(line);
        std::vector<GameTile *> row;
        for (int i; ss >> i;) {
            GameTile *tile = GameTile::getTile(i);
            row.push_back(tile);
            if (ss.peek() == ' ')
                ss.ignore();
        }
        worldMap.push_back(row);
    }
}
