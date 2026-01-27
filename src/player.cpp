

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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        movement_offset.x += 5;
        if(animation_frame >= animation_speed) {
            ss << "tile0" << 27+animation_index << ".png";
            mage_image.loadFromFile(ss.str());
            animation_frame = 0;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q ) ) {
        movement_offset.x -= 5;
        if(animation_frame >= animation_speed) {
        ss << "tile0" << 10+animation_index << ".png";
        mage_image.loadFromFile(ss.str());
        animation_frame = 0;
    }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) ) { // MAKE THE COLLISION WORKKKK Check down here
        movement_offset.y -= 5;
        if(animation_frame >= animation_speed) {
        ss << "tile00" << animation_index << ".png";
        mage_image.loadFromFile(ss.str());
        animation_frame = 0;
    }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ) {
        movement_offset.y += 5;
        if(animation_frame >= animation_speed) {
        ss << "tile0" << 18+animation_index << ".png";
        mage_image.loadFromFile(ss.str());
        animation_frame = 0;
    }
    } else {
        mage_image.loadFromFile("tile018.png");
    } if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ) { // Sprinting, basically making the speed 2 times faster.
        movement_offset.x * 5;  
        movement_offset.y * 5;  
    }

    animation_index +=1;

    if(animation_index >= 7) {
        animation_index = 0;
    }

    // Displaying the character and updating the animation frame.
    ss.str("");
    mage.setTexture(mage_image, true);
    animation_frame++;
    
}

void player::collision_check() {
    Hitbox.position = {x + movement_offset.x, y + movement_offset.y};
    Hitbox.size = {static_cast<float>(mage_image.getSize().x), static_cast<float>(mage_image.getSize().y)};

    for(const auto i: collision_tiles) {
        if(Hitbox.findIntersection(i)) {
            movement_offset = {0, 0};
        }  
    }    
    Hitbox.position = {x, y};
}

// This took me so much time, i liked it.
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
    return mage_image;
}


/*

sprinting (We would simply double the x and y offset)

/////////////////////

Next easy fix : temporarly set the sprite hitbox to a fixed position and size depending on this sprite.
And the collision hitbox (with collide tiles) Should be surrounding the legs only and nothing more ! 
And something else, sprite sheets. Why have a thousand images of the player sprite ? Be smart and just have a sprite image sheet, after solving this collision problem, make a class that would
contain tools and algorithms to be used everywhere and make one that would return a struct i guess of sprite animation.

the struct would have one image for standing up right
4 vectors for movement of each direction
4 vector for attack ? I guess in each direction
And more...

*/