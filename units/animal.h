#pragma once
#include "unit.h"

/*
 * Class that describes animals behaviour
 */

class Animal : public Unit {
public:
    Animal();
    ~Animal();

    float speed;

    int maxHunger;
    int hunger;
    int strength;

    void move();
    virtual void bite(Unit *unit);

    float directionX = 0;
    float directionY = 0;

    bool isAlive();
};