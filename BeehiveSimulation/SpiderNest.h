
// SpiderNest.h
#ifndef SPIDER_NEST_H
#define SPIDER_NEST_H

#include <vector>
#include "Spider.h"

class SpiderNest {
public:
    SpiderNest(float x, float y) : position(x, y) {}

    void spawnSpider() {
        spiders.emplace_back(position.x, position.y);
    }

    void update(float deltaTime) {
        for (auto& spider : spiders) {
            spider.update(deltaTime);
        }
    }

    void draw(sf::RenderWindow& window) {
        for (auto& spider : spiders) {
            spider.draw(window);
        }
    }

private:
    sf::Vector2f position;
    std::vector<Spider> spiders;
};

#endif
