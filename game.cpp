#include "game.h"
#include "mapFactory.cpp"
#include "player.cpp"

Game::Game(MapName initialMap, Location initialLocation)
{
    player = new Player();
    setPlayerLocation(initialLocation);
}

bool Game::canMove(Player *player, Direction direction)
{
    int playerX = player->getX();
    int playerY = player->getY();
    if (direction == Direction::LEFT)
    {
        if (playerX - 1 >= 0)
        {
            if (currentMap.tiles[playerY][playerX - 1]->isWalkable())
                return true;
        }
    }
    else if (direction == Direction::RIGHT)
    {
        if (playerX + 1 < currentMap.tiles[playerY].size())
        {
            if (currentMap.tiles[playerY][playerX + 1]->isWalkable())
                return true;
        }
    }
    else if (direction == Direction::UP)
    {
        if (playerY - 1 >= 0)
        {
            if (currentMap.tiles[playerY - 1][playerX]->isWalkable())
                return true;
        }
    }
    else if (direction == Direction::DOWN)
    {
        if (playerY + 1 < currentMap.tiles.size())
        {
            if (currentMap.tiles[playerY + 1][playerX]->isWalkable())
                return true;
        }
    }
    return false;
}

void Game::movePlayerLeft()
{
    player->setOrientation(Direction::LEFT);
    if (canMove(player, Direction::LEFT))
        player->moveLeft();
}

void Game::movePlayerRight()
{
    player->setOrientation(Direction::RIGHT);
    if (canMove(player, Direction::RIGHT))
        player->moveRight();
}

void Game::movePlayerUp()
{
    player->setOrientation(Direction::UP);
    if (canMove(player, Direction::UP))
        player->moveUp();
}

void Game::movePlayerDown()
{
    player->setOrientation(Direction::DOWN);
    if (canMove(player, Direction::DOWN))
        player->moveDown();
}

void Game::setCurrentMap(MapName mapName)
{
    currentMap = MapFactory::getMap(mapName);
}

void Game::setPlayerLocation(Location location)
{
    setCurrentMap(location.mapName);
    player->setLocation(location);
}