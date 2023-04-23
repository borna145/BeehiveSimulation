#ifndef HIVE_H
#define HIVE_H

#include <vector>
#include "bee.h"

class Hive {
public:
	Hive(int colonyID, float x, float y);

	void addBee(Bee* bee);
	Hive* split(float newX, float newY);

	int getColonyID() const;
	float getX() const;
	float getY() const;

private:
	int colonyID;
	float x, y;
	std::vector<Bee*> bees;
	bool split();
};

#endif // HIVE_H
