// bee.cpp

#include "bee.h"
#include <iostream>
#include <cmath>






Bee::Bee(float x, float y, float hiveX, float hiveY) 
	: x(x), y(y), hiveX(hiveX), hiveY(hiveY), speed(0.0f), position(x, y) {}




float Bee::getX() const {
	return x;
}

float Bee::getY() const {
	return y;
}

void Bee::updatePosition(float deltaTime, float targetX, float targetY) {
	float lerpFactor = speed * deltaTime;
	x = x + (targetX - x) * lerpFactor;
	y = y + (targetY - y) * lerpFactor;
}



sf::Vector2f Bee::getInitialPosition() const {
	return initialPosition;
}

// Other member function definitions



void Bee::markFlower(float flowerX, float flowerY) {
	std::cout << "Marked flower at (" << flowerX << ", " << flowerY << ")\n";
}

void Bee::markEnemyStructure(float structureX, float structureY) {
	std::cout << "Marked enemy structure at (" << structureX << ", " << structureY << ")\n";
}

void Bee::returnToHive() {
	x = hiveX;
	y = hiveY;
}
