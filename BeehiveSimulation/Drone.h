
#ifndef DRONE_BEE_H
#define DRONE_BEE_H

#include "Bee.h"

class DroneBee : public Bee {
public:
    DroneBee(float x, float y, float hiveX, float hiveY)
        : Bee(x, y, hiveX, hiveY) {
        if (!texture.loadFromFile("drone_bee_texture.png")) {
            // Handle texture loading error
        }
        sprite.setTexture(texture);
        position = sf::Vector2f(x, y);
        sprite.setPosition(position);
        speed = 50.0f;
    }

    void update(float deltaTime) override {
        // Update DroneBee's attributes and behavior here
    }

    // Additional methods for DroneBee
};

#endif
