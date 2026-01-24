
#include "SFMLOrthogonalLayer.hpp"

class level_manager {
    private:

    tmx::Map map;
    MapLayer *layerOne;
    MapLayer *layerTwo;
    MapLayer *layerThree;

    public:

    level_manager() {

        map.load("test_level.tmx");
        layerOne = new MapLayer(map, 0);
        layerTwo = new MapLayer(map, 1);
        layerThree = new MapLayer(map, 3);
    }
    ~level_manager() {

        delete layerOne;
        delete layerTwo;
        delete layerThree;
    }
    
    void draw_top(sf::RenderWindow & window);
    void draw_bottom(sf::RenderWindow & window);
    void check_collision(int & x, int & y);
};