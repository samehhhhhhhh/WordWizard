


// Make enemies that can walk with animations, make them go towards the player.

#include "entity_base.hpp"

class enemy : public entity_base {

public : 
    float& p_x;
    float& p_y;
    float speed;
    float health;


    std::vector<std::vector<sf::Image>> animations_vec;
    enemy(float& player_x, float& player_y, float speed = 1.f) : entity_base("assets/sprites/Orc.png", 100, 100, 100,0, 0), p_x(player_x),
    p_y(player_y), speed(speed) {
        x= 500;
        y = 500;
        Hitbox.size = {44, 42};

        animations_vec = correct_sprite({22, 15},{ 44, 42});
        
    }
    void movement() override;
    sf::Vector2f p_coordinates {0, 0};
    int view_distance {300};
    

    void detection();
    
};