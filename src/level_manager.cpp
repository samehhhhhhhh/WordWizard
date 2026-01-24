#include "level_manager.hpp"


void level_manager::draw_bottom(sf::RenderWindow & window) {
    
    window.draw(*layerOne);
    window.draw(*layerTwo);
    window.draw(*layerThree);
}
void level_manager::draw_top(sf::RenderWindow & window) {
    
    MapLayer layer(map, 2);
    
    window.draw(layer);
    
}

void level_manager::check_collision(int &x, int & y) {
    
    const tmx::Vector2u tile_position {x/map.getTileCount().x, y/map.getTileCount().y};

    auto tile {(*layerTwo).getTile(tile_position.x, tile_position.y)};

    // Inutile ? Si get tile n'est pas nul alors ça veut dire qu'il y'a une tile de collision aux coordonées donc stop le joueur.


    // Tout ça en bas ptete inutile.
    auto tilesets {map.getTilesets()};
    const tmx::Tileset::Tile* The_Tile;
    for(auto &i: tilesets) {
        if(i.getFirstGID() <= tile.ID && i.getLastGID() >= tile.ID) {
            auto l_tileID {tile.ID - i.getFirstGID()};
            The_Tile = i.getTile(l_tileID);
        }
    }
    std::vector<tmx::Property> tile_propreties{The_Tile->properties};

    for(auto & a: tile_propreties) {
        if(a.getName() == )
    }


    



    
}