


#include "enemy.hpp"

void enemy::movement() {

    if(moving) {
        
        source_image = ent_sprite_sheet.get_sprite_images()[9][animation_index];   
        
    } else {
        source_image = ent_sprite_sheet.get_sprite_images()[18][0]; // For some reason, out of bound now
    }
    moving = false;


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