cmake_minimum_required(VERSION 3.22)
project(evolution)

set(CMAKE_CXX_STANDARD 17)
set(LINKER_FLAGS "-lsfml-graphics -lsfml-window -lsfml-system")

include_directories(include)
add_executable(evolution main.cpp units/unit.cpp units/unit.h units/animal.cpp units/animal.h
        units/hunter.cpp units/hunter.h units/plant.cpp units/plant.h
        settings/settings.cpp settings/settings.h units/peaceful.cpp units/peaceful.h renderer/renderer.cpp renderer/renderer.h logic/logic.cpp logic/logic.h)

target_link_libraries(evolution ${LINKER_FLAGS})
set(EXECUTABLE_OUTPUT_PATH ${evolution_SOURCE_DIR}/bin)
