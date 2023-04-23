// BearHideout.h
#ifndef BEAR_HIDEOUT_H
#define BEAR_HIDEOUT_H

#include <vector>
#include "Bear.h"

class BearHideout {
public:
    BearHideout(float x, float y) : position(x, y) {}

    void spawnBear() {
        bears.emplace_back(position.x, position.y);
    }

    void update(float deltaTime) {
        for (auto& bear : bears) {
            bear.update(deltaTime);
        }
    }

    void draw(sf::RenderWindow& window) {
        for (auto& bear : bears) {
            bear.draw(window);
        }
    }

private:
    sf::Vector2f position;
    std::vector<Bear> bears;
};

#endif

