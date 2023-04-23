#ifndef QUEEN_BEE_H
#define QUEEN_BEE_H

#include <vector>
#include <functional>
#include "Bee.h"
#include "Egg.h"

class QueenBee : public Bee {
public:
    QueenBee(float x, float y, float hiveX, float hiveY)
        : Bee(x, y, hiveX, hiveY) {
        if (!texture.loadFromFile("queen_bee_texture.png")) {
            std::cout << "Couldn't load queen bee textures expect errors\n";
        }
        sprite.setTexture(texture);
        position = sf::Vector2f(x, y);
        sprite.setPosition(position);
        speed = 50.0f;
    }

    void update(float deltaTime) override {
        layEggs(deltaTime);
        updateEggs(deltaTime);
    }

private:
    std::vector<Egg> eggs;
    float eggLayingRate = 2000.0f / 86400.0f; // 2000 eggs per day
    float eggHatchingTime = 16.0f * 86400.0f / 60.0f; // 16 days, scaled to your time system
    float eggTimer = 0.0f;

    void layEggs(float deltaTime) {
        eggTimer += deltaTime;
        if (eggTimer >= 1.0f / eggLayingRate) {
            eggs.emplace_back(position.x, position.y, eggHatchingTime, [this]() {
                // Create a new bee when the egg hatches
                // You can use a random number generator to determine the type of bee (worker or drone)
                });
            eggTimer = 0.0f;
        }
    }

    void updateEggs(float deltaTime) {
        for (auto& egg : eggs) {
            egg.update(deltaTime);
        }
        // Remove hatched eggs
        eggs.erase(std::remove_if(eggs.begin(), eggs.end(),
            [](const Egg& egg) { return egg.isHatched(); }),
            eggs.end());
    }
};

#endif
