#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

namespace Settings {
    extern int hunterHp;
    extern int hunterSize;
    extern int hunterSpeed;
    extern int hunterMaxHunger;
    extern int hunterMaxAge;
    extern int hunterStrength;
    extern int hunterView;
    extern int hunterGrowthSpeed;
    extern std::string hunterColor;

    extern int peacefulHp;
    extern int peacefulSize;
    extern int peacefulSpeed;
    extern int peacefulMaxHunger;
    extern int peacefulMaxAge;
    extern int peacefulStrength;
    extern int peacefulView;
    extern int peacefulGrowthSpeed;
    extern std::string peacefulColor;

    extern int plantHp;
    extern int plantSize;
    extern int plantMaxAge;
    extern int plantGrowthSpeed;
    extern std::string plantColor;

    void fillUnitSettings();
}
