#include <iostream>
#include <chrono>

#include "settings/settings.h"
#include "renderer/renderer.h"

void createUnits() {
    for (int i = 0; i < 10; i++) {
        auto a = new Hunter();
        hunters.push_back(a);
    }

    for (int i = 0; i < 20; i++) {
        auto a = new Peaceful();
        peacefuls.push_back(a);
    }

    for (int i = 0; i < 50; i++) {
        auto a = new Plant();
        plants.push_back(a);
    }
}

int main() {
    Settings::fillUnitSettings();
    createUnits();

    Renderer renderer;

    while(renderer.running()) {
        auto start = std::chrono::high_resolution_clock::now();
        renderer.update();
        renderer.render();
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << std::endl;
    }

    return 0;
}

//TODO: Убрать из объекта unit переменные координат, брать их из SFML объектов?