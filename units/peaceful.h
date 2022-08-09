#pragma once
#include "animal.h"
#include "plant.h"

/*
 * Class that describes peaceful behaviour
 */

class Peaceful : public Animal {
public:
    Peaceful();
    ~Peaceful();

    void action();
private:
    void replicate();
    void chooseDirection();
};

extern std::vector <Peaceful*> peacefuls;