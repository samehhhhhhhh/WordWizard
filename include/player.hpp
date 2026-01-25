
#include <SFML/Graphics.hpp>
#include "SFMLOrthogonalLayer.hpp"
class player{

    private:

        sf::Texture mage_image;
        sf::Sprite mage;
        int animation_frame{ 0};
        int animation_speed{ 5}; // Lower is faster    
        int animation_index = { 0};
        tmx::Map map;
        std::stringstream ss;
        float x = 10;
        float y = 10;
        MapLayer * collision_layer;
        

    public:
        
        player() : mage(mage_image){
            mage.setTexture(mage_image);
            map.load("test_level.tmx");
            collision_layer = new MapLayer(map, 3);
        }
        void update(sf::RenderWindow &window);
        void movement();
        bool check_collision();
        float get_x();
        float get_y();
    };