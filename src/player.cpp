#include "player.hpp"

void player::movement() {

    if(moving) {
        
        source_image = ent_sprite_sheet.get_sprite_images()[9][animation_index];   
        
    } else {
        source_image = ent_sprite_sheet.get_sprite_images()[18][0]; // For some reason, out of bound now
    }
    moving = false;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        movement_offset.x += 5;
        moving = true;
        if(side == 1) side = 0;
            
    } if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q ) ) {
        movement_offset.x -= 5;
        moving = true;
        if(side == 0) side = 1;

    } if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) ) {
        movement_offset.y -= 5;
        moving = true;    
    
    } if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ) {
        movement_offset.y += 5;
        moving = true;

    } if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ) { // Sprinting, basically making the speed 2 times faster.
        movement_offset.x = movement_offset.x * 2;  
        movement_offset.y = movement_offset.y * 2;  
    } 

    // If enough frames have passed, increment the animation_index to the next keyframe in the animation sequence.
    if(animation_frame >= animation_speed) {
        animation_frame = 0;
        animation_index +=1;
    }

    // If the last keyframe in the sequence is reached, reset the animation sequence index.
    if(animation_index >= 5) {
        animation_index = 0;
    }
    
    // If the player's side should be left, flip the image horizontaly (By default the player image is always on the right.)
    if (side == 1) {
        source_image.flipHorizontally();
    }
    
    // Displaying the character and updating the animation frame.
    ent_texture.loadFromImage(source_image);
    ent_sprite.setTexture(ent_texture, true);
    ent_sprite.setScale({2.5, 2.5});
    animation_frame++;
    
}

