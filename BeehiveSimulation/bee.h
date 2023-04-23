#ifndef BEE_H
#define BEE_H

#include <SFML/Graphics.hpp>

class Bee {
public:
    Bee(float x, float y, float hiveX, float hiveY);
    float getX() const;
    float getY() const;
    void updatePosition(float deltaTime, float targetX, float targetY);
    void markFlower(float flowerX, float flowerY);
    void markEnemyStructure(float structureX, float structureY);
    void returnToHive();
    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    sf::Vector2f getInitialPosition() const;

private:
    sf::Vector2f initialPosition;

protected:
    float x;
    float y;
    float hiveX;
    float hiveY;
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;
    sf::Vector2f position;
};

#endif
