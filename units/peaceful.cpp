#include "peaceful.h"
#include "hunter.h"
std::vector <Peaceful*> peacefuls;

Peaceful::Peaceful() {
    std::cout << "New peaceful unit" << std::endl;

    this->fullHp =      Settings::peacefulHp + normalDistribution(Settings::peacefulHp);
    this->hp =          Settings::peacefulHp + normalDistribution(Settings::peacefulHp);
    this->size =        Settings::peacefulSize + normalDistribution(Settings::peacefulSize);
    this->speed =       Settings::peacefulSpeed + normalDistribution(Settings::peacefulSpeed);
    this->maxHunger =   Settings::peacefulMaxHunger + normalDistribution(Settings::peacefulMaxHunger);
    this->maxAge =      Settings::peacefulMaxAge + normalDistribution(Settings::peacefulMaxAge);
    this->strength =    Settings::peacefulStrength + normalDistribution(Settings::peacefulStrength);
    this->view =        Settings::peacefulView + normalDistribution(Settings::peacefulView);
    this->growthSpeed = Settings::peacefulGrowthSpeed + normalDistribution(Settings::peacefulGrowthSpeed);
    this->hunger =      1;
    this->age =         0;
    this->color =       Settings::peacefulColor;
    this->type =        "peaceful";
}

Peaceful::~Peaceful() {
 std::cout << "Delete peaceful" << std::endl;
}

void Peaceful::action() {
    this->chooseDirection();
    this->move();
    this->replicate();
    this->age++;
    this->hunger++;
}

//Private functions
void Peaceful::replicate() {
    if((this->fullHp == this->hp) && (this->hunger <= 0)) {
        std::cout << "\npeaceful replicates\n" << std::endl;
        auto newPeaceful = new Peaceful();
        newPeaceful->coordinateX = this->coordinateX + 40;
        newPeaceful->coordinateY = this->coordinateY + 40;
        newPeaceful->unitShape.setPosition(newPeaceful->coordinateX,newPeaceful->coordinateY);
        newPeaceful->unitShape.setSize(sf::Vector2f(newPeaceful->size,newPeaceful->size));
        newPeaceful->unitShape.setOutlineColor(sf::Color::Black);
        newPeaceful->unitShape.setOutlineThickness(1.f);
        newPeaceful->unitShape.setFillColor(sf::Color::Blue);
        peacefuls.push_back(newPeaceful);
    }
}

void Peaceful::chooseDirection() {
    for(auto hunter : hunters) {
        if(getDistance(this->coordinateX, this->coordinateY, hunter->coordinateX, hunter->coordinateY) <= this->view) {
            if(this->coordinateX < hunter->coordinateX) {
                this->directionX = hunter->coordinateX - 100;
            } else {
                this->directionX = hunter->coordinateX + 100;
            }

            if(this->coordinateY < hunter->coordinateY) {
                this->directionY = hunter->coordinateY - 100;
            } else {
                this->directionY = hunter->coordinateY + 100;
            }

            return;
        }
    }
    if (this->hunger > 0) {
        for(auto plant : plants) {
            float distance = getDistance(this->coordinateX, this->coordinateY, plant->coordinateX, plant->coordinateY);
            if(distance <= this->view) {
                this->directionX = plant->coordinateX;
                this->directionY = plant->coordinateY;
                bite(plant);
                return;
            }
        }
    }

    this->directionX = 0;
    this->directionY = 0;
}