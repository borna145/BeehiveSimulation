#ifndef WORKER_BEE_H
#define WORKER_BEE_H

#include "Bee.h"

class WorkerBee : public Bee {
public:
    WorkerBee(float x, float y, float hiveX, float hiveY)
        : Bee(x, y, hiveX, hiveY) {
        if (!texture.loadFromFile("worker_bee_texture.png")) {
            // Handle texture loading error
        }
        sprite.setTexture(texture);
        position = sf::Vector2f(x, y);
        sprite.setPosition(position);
        speed = 50.0f;
    }
        void update(float deltaTime) override {
            age += deltaTime;

            if (age < nurseBeeAge) {
                // Perform nurse bee tasks
            }
            else if (age < foragerBeeAge) {
                // Perform forager bee tasks
            }
            else {
                // Perform other tasks
            }
        }

    private:
        float age = 0.0f;
        float nurseBeeAge = 3.0f; // Example value, adjust based on source info
        float foragerBeeAge = 10.0f; // Example value, adjust based on source info
    };



#endif
