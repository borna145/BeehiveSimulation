// BeeHiveSimulationUtils.cpp
#include "BeeHiveSimulationUtils.h"

void updateBeePositionRelativeToBackground(sf::Sprite& BeeSprite, const sf::Sprite& backgroundSprite, const WorkerBee& beeInstance)
{
    sf::Vector2f backgroundPosition = backgroundSprite.getPosition();
    BeeSprite.setPosition(backgroundPosition.x + beeInstance.getX(), backgroundPosition.y + beeInstance.getY());
}
