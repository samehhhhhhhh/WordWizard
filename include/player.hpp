
#include <SFML/Graphics.hpp>

class player{

    private:

        sf::Texture mage_image;
        sf::Sprite mage;
        int animation_frame{ 0};
        int animation_speed{ 5}; // Lower is faster    
        int animation_index = { 0};
        
        std::stringstream ss;
        

    public:
        float x = 10;
        float y = 10;
        player() : mage(mage_image){
            mage.setTexture(mage_image);
        }
        void update(sf::RenderWindow &window);
        void movement();

    };