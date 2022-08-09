#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

#include "../units/plant.h"
#include "../units/hunter.h"
#include "../units/peaceful.h"

using namespace sf;

/*
 * Class that acts as a game engine
*/

class Renderer {
public:
    // Constructor / Destructor
    Renderer();
    ~Renderer();

    //Accessors
    const bool running() const;

    //Functions
    void update();
    void render();
    void updateObjects();
    void updateHunters();
    void updatePeacefuls();
    void updatePlants();


    void handleEvents();
private:
    RenderWindow* window;
    Event ev;
    VideoMode videoMode;

    //Private functions
    void initVariables();
    void initWindow();
    void initGameObjects();
    void initObject(Unit *unit);
};