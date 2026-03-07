

#include "entity_base.hpp"

void entity_base::update(sf::RenderWindow &window) {
    movement();

    collision_check();

    // Applying the movement offset to the player coordinates. TODO: ADD SPRINTING.
    
    x += movement_offset.x;
    y += movement_offset.y;
    movement_offset = {0, 0};
    ent_sprite.setPosition({x, y});
    
    window.draw(ent_sprite);
    
    e_weapon.update(window);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        e_weapon.shoot(window);
    }
}
    

void entity_base::collision_check() {
    Hitbox.position = {x + movement_offset.x, y + movement_offset.y+30};
    Hitbox.size = {static_cast<float>(ent_texture.getSize().x + 20), static_cast<float>(ent_texture.getSize().y)};

    for(const auto i: collision_tiles) {
        if(Hitbox.findIntersection(i)) {
            movement_offset = {0 , 0};
        }  
    }     
    Hitbox.position = {x+20, y+50};
}

// This took me so much time... I dont' need it anymore, i'll leave it here as a memory lol.
bool entity_base::check_collision(float x, float y) {
    
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

float entity_base::get_x() {
    return x;
}

float entity_base::get_y() {
    return y;
}

sf::Texture entity_base::get_spriteImage() {
    return ent_texture;
}
