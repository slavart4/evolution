#include "logic.h"

/**
 * Function that gets distance between two points
 * @param {float} X position of first object
 * @param {float} Y position of first object
 * @param {float} X position of second object
 * @param {float} Y position of second object
 * @returns {float} Distance between two objects
 */
float getDistance(float x1, float y1, float x2, float y2) {
    return sqrtf((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

/**
 * Function that checks if two game objects has collision
 * @param {float} current X position
 * @param {float} current Y position
 * @param {float} direction X position
 * @param {float} direction Y position
 * @param {float} unit`s speed
 * @returns {structure} structure with positionX and positionY
 */
position getRangeCoordinate(float curX, float curY, float dirX, float dirY, int speed) {
    position result = {
            0,
            0
    };

    float distance = getDistance(curX, curY, dirX, dirY);
    if(distance > 0) {
        float correlation = distance / speed;
        result.positionX = (dirX - curX)/correlation + curX;
        result.positionY = (dirY - curY)/correlation + curY;
    }

    return result;
}

/**
 * Function that checks if two game objects has collision
 * @param {sf::RectangleShape&} rectA
 * @param {sf::RectangleShape&} rectB
 * @returns {bool} If two game objects has collision
 */
bool checkCollision(const sf::RectangleShape& rectA, const sf::RectangleShape& rectB)
{
    return rectB.getGlobalBounds().intersects(rectA.getGlobalBounds());
}


/**
 * Function that gives number by normal distribution
 * @returns {float} Number by normal distribution
 */
float normalDistribution(float range) {
    std::default_random_engine generator;
    std::normal_distribution<float> distribution(0.0,range);
    return distribution(generator);
}