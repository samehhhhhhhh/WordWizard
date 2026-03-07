#include <SFML/Graphics.hpp>
#include "SFMLOrthogonalLayer.hpp"
#include "sprite_sheet.hpp"
#include "weapon.hpp"

class entity_base{

    protected:

        sf::Image source_image;
        sf::Texture ent_texture;
        sf::Sprite ent_sprite;

        int sprite_width {ent_sprite.getScale().x};
        int sprite_height {ent_sprite.getScale().x};
        int animation_frame{ 0};
        int animation_speed{ 5}; // Lower is faster    
        int animation_index = { 0};

        bool moving = false;
        int side {0}; // Right 0, left 1

        tmx::Map map;
        MapLayer * collision_layer;

        std::stringstream ss;

        float x = 300;
        float y = 300;
        
        sf::Vector2f movement_offset{0, 0};

        weapon e_weapon;

    public:

        sprite_sheet ent_sprite_sheet;

        sf::IntRect Hitbox {{x, y}, {ent_sprite.getScale().x, ent_sprite.getScale().y}};

        std::vector<sf::IntRect> collision_tiles;

        entity_base(std::string path, int a, int b, int c) : ent_sprite(ent_texture), ent_sprite_sheet(path, a, b, b) {

            ent_sprite.setTexture(ent_texture);
            map.load("test_level.tmx");
            collision_layer = new MapLayer(map, 3);

            const auto mapTileCount = map.getTileCount();
            const auto TileSize = map.getTileSize();

            for(int i = 0; i <= map.getTileCount().y;i++) { // y

                for(int a = 0; a <= map.getTileCount().x;a++) { // x

                    tmx::TileLayer::Tile tile = (*collision_layer).getTile(a, i);

                    if(tile.ID != 0) {
                        // If tile is a collision tile : 
                        collision_tiles.push_back(sf::IntRect({a*TileSize.x, i*TileSize.y},{TileSize.x , TileSize.y})); // x = a, y = i
                    }
                }
            }
            e_weapon = weapon(ent_sprite_sheet.get_sprite_images()[8], x, y, 5);
        }


        // Class methods :
        void update(sf::RenderWindow &window);
        
        bool check_collision(float x, float y); // For specific coordinates with a tile ... Kind of deprecated.

        // Getters
        float get_x();
        float get_y();

        sf::Texture get_spriteImage();
        void collision_check();

        virtual void movement() {
            movement_offset = {0 , 0};
        }
        
    };