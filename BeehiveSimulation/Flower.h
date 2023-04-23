// Flower.h
#ifndef FLOWER_H
#define FLOWER_H

#include <SFML/Graphics.hpp>

class Flower {
public:
    Flower(float x, float y) : position(x, y) {
        if (!texture.loadFromFile("flower_texture.png")) {
            // Handle texture loading error
        }
        sprite.setTexture(texture);
        position = sf::Vector2f(x, y);
        sprite.setPosition(position);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    float collectNectar(float amount) {
        float collected = std::min(amount, nectar);
        nectar -= collected;
        return collected;
    }

private:
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;
    float nectar = 100.0f;
};

#endif

