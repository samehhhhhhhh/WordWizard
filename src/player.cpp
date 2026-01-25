

#include "player.hpp"

void player::update(sf::RenderWindow &window) {
    mage.setPosition({x, y});
    window.draw(mage);
    
}

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

// This took me so much time, i liked it.
bool player::check_collision() {
    
    const auto mapTileCount = map.getTileCount();
    
    // Getting the exact tile coordinate on the tmx map
    const tmx::Vector2u tile_position {
        static_cast<unsigned int>((this->x+10) / mapTileCount.x), 
        static_cast<unsigned int>((this->y+10) / mapTileCount.y)
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