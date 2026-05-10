

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
    
    for(auto& i : ent_weapons) {
        i.update(window);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        i.shoot(window);
    }
    }
   

    
}
    

void entity_base::collision_check() {
    

    Hitbox.position = {x + movement_offset.x, y};
    

    for(const auto i: collision_tiles) {
        if(Hitbox.findIntersection(i)) {
            movement_offset.x = 0;
        }  
    }     
    
    // For the vertical collision check : 
    Hitbox.position = {x, y + movement_offset.y};

    for(const auto i: collision_tiles) {
        if(Hitbox.findIntersection(i)) {
            movement_offset.y = 0;
        }  
        
    }     
}

std::vector<std::vector<sf::Image>> entity_base::correct_sprite(sf::Vector2u size, sf::Vector2u position_offset) {

    auto sprite_sheet_vec = ent_sprite_sheet.get_sprite_images();
    for(auto& row : sprite_sheet_vec) {
        for(auto& image : row) {
            const auto image_size = image.getSize();
            if (image_size.x == 0 || image_size.y == 0) {
                std::cerr << "correct_sprite: skipping empty image\n";
                continue;
            }
            if (position_offset.x + size.x > image_size.x || position_offset.y + size.y > image_size.y) {
                std::cerr << "correct_sprite: src_rect out of bounds (img=" << image_size.x
                          << "x" << image_size.y << ", offset=" << position_offset.x
                          << "," << position_offset.y << ", size=" << size.x
                          << "x" << size.y << ")\n";
                continue;
            }
            sf::Image new_image(size);
            const sf::IntRect src_rect{
                {static_cast<int>(position_offset.x), static_cast<int>(position_offset.y)},
                {static_cast<int>(size.x), static_cast<int>(size.y)}
            };
            if (!new_image.copy(image, {0, 0}, src_rect)) {
                std::cerr << "correct_sprite: copy failed for src_rect\n";
                continue;
            }
            image = new_image;
        }
    }


    return sprite_sheet_vec;


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
float entity_base::get_hitsx() {
    return Hitbox.size.x;
}
float entity_base::get_hitsy() {
    return Hitbox.size.y;
}
float& entity_base::get_x() {
    return x;
}

float& entity_base::get_y() {
    return y;
}

sf::Texture entity_base::get_spriteImage() {
    return ent_texture;
}
