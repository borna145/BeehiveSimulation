// Bear.h
#ifndef BEAR_H
#define BEAR_H

#include "Enemy.h"

class Bear : public Enemy {
public:
    Bear(float x, float y) : Enemy(x, y) {
        if (!texture.loadFromFile("bear_texture.png")) {
            // Handle texture loading error
        }
        sprite.setTexture(texture);
        position = sf::Vector2f(x, y);
        sprite.setPosition(position);
        speed = 80.0f;
    }

    void update(float deltaTime) override {
        // Update Bear's attributes and behavior here
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(sprite);
    }

private:
    float speed;
};

#endif
