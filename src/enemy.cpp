


#include "enemy.hpp"

void enemy::movement() {
    
    detection();
    if(moving) {
        
        source_image = ent_sprite_sheet.get_sprite_images()[0][animation_index];   

        sf::Vector2f movement_offset_a = {p_x-x, p_y-y};
        movement_offset_a.normalized();
        movement_offset = movement_offset_a;
        
    } else {
        source_image = ent_sprite_sheet.get_sprite_images()[0][0]; // For some reason, out of bound now
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

void enemy::detection() {
    
    int distance {static_cast<int>(std::hypot(p_x - x, p_y - y))};

    if(distance <= view_distance) {
        moving = true;
    } else {
        moving = false;
    }
   

    // maybe first calculate the distance between the player and enemy, 
    // if it reaches a certain treshold then run the rest of the code, by making a vector that goes from
    // the player to the enemy,
    // Make a method to check if the vector collides with any collision tile
    // if it does then break but if it doesn't hit any collision then 
    // check if the vector is in the correct direction (On the right of the enemy or the left)

    // This is doable but i must find a way to check if the vector collides with any tiles, 
    // We can loop through the collision tiles but the problem stays the same, this is not a 
    // Rect

}