#pragma once

#include "animal.h"

/*
 * Class that describes hunters behaviour
 */

class Hunter : public Animal {
public:
    Hunter();
    ~Hunter();

    void action();
private:
    void chooseDirection();
    void replicate();
};

extern std::vector <Hunter*> hunters;