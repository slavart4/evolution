#include "renderer.h"
using namespace sf;

// Constructor / Destructor

Renderer::Renderer() {
    sf::Clock clock;
    this->initVariables();
    this->initWindow();
    this->handleEvents();
    this->initGameObjects();
}

Renderer::~Renderer() {
    for (auto hunter : hunters) {
        delete hunter;
    }

    for (auto peaceful : peacefuls) {
        delete peaceful;
    }

    for(auto plant : plants) {
        delete plant;
    }

    delete this->window;
}

//Private functions

void Renderer::initVariables() {
    //Initialize variables

    this->window = nullptr;

    this->videoMode.height = 1024;
    this->videoMode.width = 1600;
}

void Renderer::initWindow() {
    // Initialize window
    this->window = new RenderWindow(this->videoMode, "Evolution!");
    this->window->setFramerateLimit(50);
}

void Renderer::initObject(Unit *unit) {
    RectangleShape gameObject;
    CircleShape gameObjectView;

    unit->coordinateX = rand() % this->videoMode.width;
    unit->coordinateY = rand() % this->videoMode.height;

    // Set units visual characteristics
    unit->unitShape.setPosition(unit->coordinateX,unit->coordinateY);
    unit->unitShape.setSize(sf::Vector2f(unit->size,unit->size));
    unit->unitShape.setOutlineColor(sf::Color::Black);
    unit->unitShape.setOutlineThickness(1.f);
    if (unit->color == "red") {
        unit->unitShape.setFillColor(sf::Color::Red);
    }
    if (unit->color == "blue") {
        unit->unitShape.setFillColor(sf::Color::Blue);
    }
    if (unit->color == "green") {
        unit->unitShape.setFillColor(sf::Color::Green);
    }

    // Set units view range characteristics
    if((unit->type == "hunter") || (unit->type == "peaceful")) {
        unit->unitView.setPosition(unit->coordinateX - unit->size, unit->coordinateY + unit->size);
        unit->unitView.setRadius(unit->view);
        unit->unitView.setFillColor(sf::Color(128, 128, 128, 90));
    }
}

void Renderer::initGameObjects() {
    for (auto hunter : hunters) {
        this->initObject(hunter);
    }

    for (auto peaceful : peacefuls) {
        this->initObject(peaceful);
    }

    for(auto plant : plants) {
        this->initObject(plant);
    }
}

//Accessors

const bool Renderer::running() const {
    return this->window->isOpen();
}

//Functions

void Renderer::handleEvents() {
    // Event polling
    while (this->window->pollEvent(ev)) {
        switch (this->ev.type) {
            case Event::Closed:
                this->window->close();
                break;
            case Event::KeyPressed:
                if(this->ev.key.code == Keyboard::Escape) {
                    this->window->close();
                }
                break;
        }
    }
}

void Renderer::update() {
    // Check is window not closed
    this->handleEvents();

    // Update all game objects
    this->updateObjects();
}

void Renderer::updateObjects() {
    updateHunters();
    updatePeacefuls();
    updatePlants();
}

void Renderer::updateHunters() {
    for(auto i = 0; i != hunters.size(); i++) {
        auto hunter = hunters[i];
        if(hunter->isAlive()) {
            hunter->action();
            hunter->unitShape.setPosition(hunter->coordinateX, hunter->coordinateY);
            hunter->unitView.setPosition(hunter->coordinateX - hunter->view + hunter->size, hunter->coordinateY - hunter->view + hunter->size);
        } else {
            hunters.erase (hunters.begin() + i);
            delete hunter;
            i--;
        }
    }
}

void Renderer::updatePeacefuls() {
    for(auto i = 0; i != peacefuls.size(); i++) {
        auto peaceful = peacefuls[i];
        if(peaceful->isAlive()) {
            peaceful->action();
            peaceful->unitShape.setPosition(peaceful->coordinateX, peaceful->coordinateY);
            peaceful->unitView.setPosition(peaceful->coordinateX - peaceful->view + peaceful->size, peaceful->coordinateY - peaceful->view + peaceful->size);
        } else {
            peacefuls.erase(peacefuls.begin() + i);
            delete peaceful;
            i--;
        }
    }
}

void Renderer::updatePlants() {
    for(auto i = 0; i != plants.size(); i++) {
        auto plant = plants[i];
        if(plant->isAlive()) {
            plant->action();
        } else {
            plants.erase(plants.begin() + i);
            delete plant;
            i--;
        }
    }
}

void Renderer::render() {
    /*
     * Renders the game objects
     * - clear old frame
     * - render objects
     * - display frame in the window
     */

    //Clear old frame
    this->window->clear(sf::Color::White);

    //Render all objects
    for(auto &hunter : hunters) {
        this->window->draw(hunter->unitShape);
        this->window->draw(hunter->unitView);
    }
    for(auto &peaceful : peacefuls) {
        this->window->draw(peaceful->unitShape);
        this->window->draw(peaceful->unitView);
    }
    for(auto &plant : plants) {
        this->window->draw(plant->unitShape);
        this->window->draw(plant->unitView);
    }

    //Window is done drowing
    this->window->display();
}