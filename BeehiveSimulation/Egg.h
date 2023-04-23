#ifndef EGG_H
#define EGG_H
#include <functional>

class Egg {
public:
    Egg(float x, float y, float timeToHatch, std::function<void()> onHatch) : posX(x), posY(y), timeToHatch(timeToHatch), onHatch(onHatch) {}

    void update(float deltaTime) {
        elapsedTime += deltaTime;
        if (elapsedTime >= timeToHatch) {
            onHatch();
            hatched = true;
        }
    }

    bool isHatched() const {
        return hatched;
    }

private:
    float posX, posY;
    float elapsedTime = 0.0f;
    float timeToHatch;
    std::function<void()> onHatch;
    bool hatched = false;
};
#endif