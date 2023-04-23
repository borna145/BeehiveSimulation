// BeeHiveSimulationUtils.h
#pragma once
#ifndef BEEHIVESIMULATIONUTILS_H
#define BEEHIVESIMULATIONUTILS_H

#include <SFML/Graphics.hpp>
#include "WorkerBee.h"

void updateBeePositionRelativeToBackground(sf::Sprite& BeeSprite, const sf::Sprite& backgroundSprite, const WorkerBee& beeInstance);

#endif // BEEHIVESIMULATIONUTILS_H
