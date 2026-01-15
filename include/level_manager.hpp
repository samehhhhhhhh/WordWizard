
#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include <SFML/Graphics.hpp>
class level_manager {
    tmx::Map map;
    
    public:


    level_manager() {
        
        map.load("test_level.tmx");
        
        
        
    }
    
    void draw_top(sf::RenderWindow & window);
    void draw_bottom(sf::RenderWindow & window);


/*
 
        


*/
};