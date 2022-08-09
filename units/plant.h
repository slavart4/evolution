#pragma once

#include "unit.h"

/*
 * Class that describes plants behaviour
 */

class Plant : public Unit {
public:
    Plant();
    ~Plant();

    void action();

    bool isAlive();
private:
    void growth();
    void replicate();
};

extern std::vector <Plant*> plants;
