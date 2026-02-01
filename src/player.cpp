#include "player.hpp"

void player::update(sf::RenderWindow &window) {
    movement();

    collision_check();

    // Applying the movement offset to the player coordinates. TODO: ADD SPRINTING.
    x += movement_offset.x;
    y += movement_offset.y;
    movement_offset = {0, 0};
    mage.setPosition({x, y});
    window.draw(mage);
}
    
void player::movement() {

    if(moving) {
        
        da_image = (*mage_sheet).get_sprite_images()[9][animation_index];   
        
    } else {
        da_image = (*mage_sheet).get_sprite_images()[18][0];
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
        da_image.flipHorizontally();
    }

    // Displaying the character and updating the animation frame.
    mage_texture.loadFromImage(da_image);
    mage.setTexture(mage_texture, true);
    mage.setScale({2.5, 2.5});
    animation_frame++;
    
}

void player::collision_check() {
    Hitbox.position = {x + movement_offset.x, y + movement_offset.y+30};
    Hitbox.size = {static_cast<float>(mage_texture.getSize().x + 20), static_cast<float>(mage_texture.getSize().y)};

    for(const auto i: collision_tiles) {
        if(Hitbox.findIntersection(i)) {
            movement_offset = {0, 0};
        }  
    }    
    Hitbox.position = {x+20, y+50};
}

// This took me so much time... I dont' need it anymore, i'll leave it here as a memory lol.
bool player::check_collision(float x, float y) {
    
    const auto mapTileCount = map.getTileCount();
    
    // Getting the exact tile coordinate on the tmx map
    const tmx::Vector2u tile_position {
        static_cast<unsigned int>((x) / mapTileCount.x), 
        static_cast<unsigned int>((y) / mapTileCount.y)
    };

    // incase the player is outside of the map.
    if(tile_position.x > 3600 || tile_position.y > 3600 ) {
        return true;

    }

    // Gets the tile at the given coordinates, if there is no collision tile, the returned tile ID would be 0
    // If there is a collision tile, we would get an ID.
    tmx::TileLayer::Tile tile = (*collision_layer).getTile(tile_position.x, tile_position.y);

    return tile.ID != 0;
}

float player::get_x() {
    return x;
}

float player::get_y() {
    return y;
}

sf::Texture player::get_spriteImage() {
    return mage_texture;
}




/*

/////////////////////

contain tools and algorithms to be used everywhere and make one that would return a struct i guess of sprite animation.

the struct would have one image for standing up right
4 vectors for movement of each direction
4 vector for attack ? I guess in each direction
And more...

*/