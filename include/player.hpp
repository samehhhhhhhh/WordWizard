#include "entity_base.hpp"

class player : public entity_base{

    private:

        float x = 300;
        float y = 300;

    public:

    player() : entity_base("mage.png", 11, 16, 144) {}
    void movement() override;
        
    };