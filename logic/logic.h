#pragma once

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <random>

struct position {
    float positionX;
    float positionY;
};
extern position getRangeCoordinate(float curX, float curY, float dirX, float dirY, int speed);

extern float getDistance(float x1, float y1, float x2, float y2);
extern bool checkCollision(const sf::RectangleShape& rectA, const sf::RectangleShape& rectB);

extern float normalDistribution(float range);