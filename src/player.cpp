

#include "player.hpp"
#include <iostream>
void player::update(sf::RenderWindow &window) {
    mage.setPosition({x, y});
    window.draw(mage);
    
}



// At each iteration of the loop, we check what key is pressed then :
/* 
change the texture accordingly to the direction of movement.

7 images per direction

*/

void player::movement() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        x += 5;
        if(animation_frame >= animation_speed) {
            ss << "tile0" << 27+animation_index << ".png";
            mage_image.loadFromFile(ss.str());
            animation_frame = 0;
        }
        
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        x -= 5;
        if(animation_frame >= animation_speed) {
        ss << "tile0" << 10+animation_index << ".png";
        mage_image.loadFromFile(ss.str());
        animation_frame = 0;
    }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        y -= 5;
        if(animation_frame >= animation_speed) {
        ss << "tile00" << animation_index << ".png";
        mage_image.loadFromFile(ss.str());
        animation_frame = 0;
    }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        y += 5;
        if(animation_frame >= animation_speed) {
        ss << "tile0" << 18+animation_index << ".png";
        mage_image.loadFromFile(ss.str());
        animation_frame = 0;
    }
    } else {
        mage_image.loadFromFile("tile018.png");
    }
    animation_index +=1;
    
    if(animation_index >= 7) {
        animation_index = 0;
    }
    ss.str("");
    mage.setTexture(mage_image, true);
    animation_frame++;
        
}