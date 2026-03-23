#include "entity_base.hpp"

class player : public entity_base{

    public:
    weapon e_weapon;

    player() : entity_base("assets/sprites/mage.png", 11, 16, 144, 5, 2) {
        e_weapon = weapon(ent_sprite_sheet.get_sprite_images()[8], x, y, 5);

        ent_weapons.push_back(e_weapon);
        
    }
    void movement() override;
        
    };