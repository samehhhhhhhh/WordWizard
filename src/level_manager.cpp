#include "level_manager.hpp"


void level_manager::draw_bottom(sf::RenderWindow & window) {
    
    window.draw(*layerOne);
    window.draw(*layerTwo);
    window.draw(*layerThree);
}
void level_manager::draw_top(sf::RenderWindow & window) {
    
    MapLayer layer(map, 2);
    
    window.draw(layer);
    
}

