#include "level_manager.hpp"
#include <iostream>

level_manager::level_manager() {
    if (!map.load("assets/level/Procedural_Rooms/test_level.tmx")) {
        std::cerr << "ERROR: Failed opening assets/level/Procedural_Rooms/test_level.tmx" << std::endl;
        return;
    }

    layerOne = std::make_unique<MapLayer>(map, 0);
    layerTwo = std::make_unique<MapLayer>(map, 1);
    layerThree = std::make_unique<MapLayer>(map, 3);
    layerTop = std::make_unique<MapLayer>(map, 2);
}


void level_manager::draw_bottom(sf::RenderWindow & window) {
    if (layerOne) {
        window.draw(*layerOne);
    }
    if (layerTwo) {
        window.draw(*layerTwo);
    }
    if (layerThree) {
        window.draw(*layerThree);
    }
}
void level_manager::draw_top(sf::RenderWindow & window) {
    if (layerTop) {
        window.draw(*layerTop);
    }
    
}

