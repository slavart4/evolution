#include "animal.h"

Animal::Animal() {
}

Animal::~Animal() {
}

void Animal::move() {
    if((this->directionX == 0) && (this->directionY == 0)) {
        if((rand() % 2) == 0) {
            float newCoordinateX = this->coordinateX + this->speed;
            if((0 <= newCoordinateX) && (newCoordinateX <= 1600 - this->size)) {
                this->coordinateX = newCoordinateX;
            }
        } else {
            float newCoordinateX = this->coordinateX - this->speed;
            if((0 <= newCoordinateX) && (newCoordinateX <= 1600 - this->size)) {
                this->coordinateX = newCoordinateX;
            }
        }

        if((rand() % 2) == 0) {
            float newCoordinateY = this->coordinateY + this->speed;
            if((0 <= newCoordinateY) && (newCoordinateY <= 1024 - this->size)) {
                this->coordinateY = newCoordinateY;
            }
        } else {
            float newCoordinateY = this->coordinateY - this->speed;
            if((0 <= newCoordinateY) && (newCoordinateY <= 1024 - this->size)) {
                this->coordinateY = newCoordinateY;
            }
        }
    } else {
        auto nextStep = getRangeCoordinate(this->coordinateX, this->coordinateY, this->directionX, this->directionY, this->speed);
        float newCoordinateX = nextStep.positionX;
        float newCoordinateY = nextStep.positionY;
        if((0 <= newCoordinateX) && (newCoordinateX <= 1600 - this->size)) {
            this->coordinateX = newCoordinateX;
        }
        if((0 <= newCoordinateY) && (newCoordinateY <= 1024 - this->size)) {
            this->coordinateY = newCoordinateY;
        }
    }
}

bool Animal::isAlive() {
    if (this->age >= this->maxAge) {
        return false;
    }
    if (this->hp <= 0) {
        return false;
    }
    if (this->hunger >= this->maxHunger) {
        return false;
    }
    return true;
}

void Animal::bite(Unit *unit) {
    if (checkCollision(this->unitShape, unit->unitShape)) {
        this->hunger -= this->strength;
        unit->hp -= this->strength;
    }
}
