#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <map>

#include "random"
#include "../settings/settings.h"
#include "../logic/logic.h"

class Unit {
public:
    Unit();
    ~Unit();

    // identify
    int id;

    // stats
    int fullHp;
    int hp;
    int size;
    int age;
    int maxAge;
    int growthSpeed;
    int view;
    std::string color;
    std::string type;

    //coordinates
    float coordinateX;
    float coordinateY;

    sf::RectangleShape unitShape;
    sf::CircleShape unitView;

    virtual void action();
};