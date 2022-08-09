#include "hunter.h"
#include "peaceful.h"
std::vector <Hunter*> hunters;

Hunter::Hunter() {
    this->hp =          Settings::hunterHp + normalDistribution(Settings::hunterHp);
    this->fullHp =      Settings::hunterHp + normalDistribution(Settings::hunterHp);
    this->size =        Settings::hunterSize + normalDistribution(Settings::hunterSize);
    this->speed =       Settings::hunterSpeed + normalDistribution(Settings::hunterSpeed);
    this->maxHunger =   Settings::hunterMaxHunger + normalDistribution(Settings::hunterMaxHunger);
    this->maxAge =      Settings::hunterMaxAge + normalDistribution(Settings::hunterMaxAge);
    this->strength =    Settings::hunterStrength + normalDistribution(Settings::hunterStrength);
    this->view =        Settings::hunterView + normalDistribution(Settings::hunterView);
    this->growthSpeed = Settings::hunterGrowthSpeed + normalDistribution(Settings::hunterGrowthSpeed);
    this->hunger =      1;
    this->age =         0;
    this->color =       Settings::hunterColor;
    this->type =        "hunter";
}

Hunter::~Hunter() {
}

void Hunter::action() {
    this->chooseDirection();
    this->move();
    this->replicate();
    this->age++;
    this->hunger++;
}

void Hunter::replicate() {
    if((this->fullHp == this->hp) && (this->hunger <= 0)) {
        auto newHunter = new Hunter();
        newHunter->coordinateX = this->coordinateX + 10;
        newHunter->coordinateY = this->coordinateY + 10;
        newHunter->unitShape.setPosition(newHunter->coordinateX,newHunter->coordinateY);
        newHunter->unitShape.setSize(sf::Vector2f(newHunter->size,newHunter->size));
        newHunter->unitShape.setOutlineColor(sf::Color::Black);
        newHunter->unitShape.setOutlineThickness(1.f);
        newHunter->unitShape.setFillColor(sf::Color::Red);
        hunters.push_back(newHunter);
    }
}

void Hunter::chooseDirection() {
    if(this->hunger > 0) {
        for(auto peaceful : peacefuls) {
            if(getDistance(this->coordinateX, this->coordinateY, peaceful->coordinateX, peaceful->coordinateY) <= this->view) {
                this->directionX = peaceful->coordinateX;
                this->directionY = peaceful->coordinateY;
                bite(peaceful);
                return;
            }
        }
    }
    this->directionX = 0;
    this->directionY = 0;
}