


// Make enemies that can walk with animations, make them go towards the player.

#include "entity_base.hpp"

class enemy : public entity_base {
public : 
    enemy() : entity_base("assets/sprites/Orc.png", 100, 100, 100) {
        
    }
    void movement() override;
    
};