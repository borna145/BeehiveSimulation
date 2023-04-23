// Spider.h
#ifndef SPIDER_H
#define SPIDER_H

#include <SFML/Graphics.hpp>

class Spider {
public:
    Spider(float x, float y) : position(x, y) {
        if (!texture.loadFromFile("spider_texture.png")) {
            // Handle texture loading error
        }
        sprite.setTexture(texture);
        position = sf::Vector2f(x, y);
        sprite.setPosition(position);
    }

    void update(float deltaTime) {
        // Implement spider behavior
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

private:
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
