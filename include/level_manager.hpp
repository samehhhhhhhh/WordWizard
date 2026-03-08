
#include "SFMLOrthogonalLayer.hpp"
#pragma once
#include <memory>

class level_manager {
    private:
    tmx::Map map;
    std::unique_ptr<MapLayer> layerOne;
    std::unique_ptr<MapLayer> layerTwo;
    std::unique_ptr<MapLayer> layerThree;
    std::unique_ptr<MapLayer> layerTop;

    public:

    level_manager();
    
    // Class Methods : 
    void draw_top(sf::RenderWindow & window);
    void draw_bottom(sf::RenderWindow & window);
};