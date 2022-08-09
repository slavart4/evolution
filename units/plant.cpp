#include "plant.h"

std::vector <Plant*> plants;

Plant::Plant() {
    ///TODO: add mutation
    this->fullHp =      Settings::plantHp;
    this->hp =          Settings::plantHp;
    this->size =        Settings::plantSize;
    this->maxAge =      Settings::plantMaxAge;
    this->growthSpeed = Settings::plantGrowthSpeed;
    this->color =       Settings::plantColor;
    this->age =         0;
    this->type =        "plant";
}

Plant::~Plant() {

}

void Plant::action() {
    this->age++;
    this->replicate();
}

void Plant::growth() {
    ///TODO: increase hp, size and age at the end of a game day
}

void Plant::replicate() {
    if((this->age % 300 == 0) && (this->hp == this->fullHp)) {
        float newCoordinateX;
        float newCoordinateY;
        if((rand() % 2) == 0) {
            newCoordinateX = this->coordinateX + this->size;
            if((0 <= newCoordinateX) && (newCoordinateX <= 1600 - this->size)) {
                this->coordinateX = newCoordinateX;
            } else {
                this->coordinateX = this->coordinateX - this->size;
            }
        } else {
            newCoordinateX = this->coordinateX - this->size;
            if((0 <= newCoordinateX) && (newCoordinateX <= 1600 - this->size)) {
                this->coordinateX = newCoordinateX;
            } else {
                this->coordinateX = this->coordinateX + this->size;
            }
        }

        if((rand() % 2) == 0) {
            newCoordinateY = this->coordinateY + this->size;
            if((0 <= newCoordinateY) && (newCoordinateY <= 1600 - this->size)) {
                this->coordinateY = newCoordinateY;
            } else {
                this->coordinateY = this->coordinateY - this->size;
            }
        } else {
            newCoordinateY = this->coordinateY - this->size;
            if((0 <= newCoordinateY) && (newCoordinateY <= 1600 - this->size)) {
                this->coordinateY = newCoordinateY;
            } else {
                this->coordinateY = this->coordinateY + this->size;
            }
        }

        auto* newPlant = new Plant();
        newPlant->unitShape.setPosition(newCoordinateX,newCoordinateY);
        newPlant->unitShape.setSize(sf::Vector2f(newPlant->size,newPlant->size));
        newPlant->unitShape.setOutlineColor(sf::Color::Black);
        newPlant->unitShape.setOutlineThickness(1.f);
        newPlant->unitShape.setFillColor(sf::Color::Green);
        plants.push_back(newPlant);
    }
}

bool Plant::isAlive() {
    if (this->age >= this->maxAge) {
        return false;
    }
    if (this->hp <= 0) {
        return false;
    }
    return true;
}