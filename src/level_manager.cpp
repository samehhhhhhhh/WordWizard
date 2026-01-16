#include "level_manager.hpp"
#include "SFMLOrthogonalLayer.hpp"
#include <tmxlite/Map.hpp>


void level_manager::draw_bottom(sf::RenderWindow & window) {
    
    MapLayer layerOne(map, 0);
    MapLayer layerTwo(map, 1);
    MapLayer layerThree(map, 3);

    
    window.draw(layerOne);
    window.draw(layerTwo);
    window.draw(layerThree);
}
void level_manager::draw_top(sf::RenderWindow & window) {
    
    MapLayer layer(map, 2);
    
    window.draw(layer);
    
}