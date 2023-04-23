
// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(float x, float y) : position(x, y) {}

    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

protected:
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
