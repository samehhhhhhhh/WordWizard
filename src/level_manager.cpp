

#include "level_manager.hpp"


void level_manager::draw_top(sf::RenderWindow & window) {}

void level_manager::draw_bottom(sf::RenderWindow & window) {
    sf::RectangleShape tile;
    auto & layers = map.getLayers();
    auto map_tilesets {map.getTilesets()};


    for(auto layer : layers) {
        auto layer_tiles {layer.getTiles()};

        for(auto & tile : layer_tiles) {
            std::uint32_t tile_id = tile.ID;
            std::uint32_t first_gid {theone.getFirstGID()};
            std::uint32_t last_gid {theone.getLastGID()};

            if(tile_id > first_gid && tile_id < last_gid) {
                layer_tiles.getImagePath();
            }

                
            

        }
    }

    for(const auto& tileset : tilesets)
        {
            tile.setSize(sf::Vector2f(map.getTileSize()));
            sf::Texture texture(tileset.getImagePath());
            
            tile.setTexture(&texture);
            
            window.draw(tile);
           
            
        }
}

