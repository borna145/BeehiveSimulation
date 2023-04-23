#include "hive.h"

Hive::Hive(int colonyID, float x, float y)
	: colonyID(colonyID), x(x), y(y) {}

void Hive::addBee(Bee* bee) {
	bees.push_back(bee);
}

bool Hive::split() {
    // Your split logic goes here

    // Return a value based on the result of your split logic
    return true; // or false, depending on your logic
}


int Hive::getColonyID() const { return colonyID; }
float Hive::getX() const { return x; }
float Hive::getY() const { return y; }
