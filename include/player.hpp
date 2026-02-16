#include <SFML/Graphics.hpp>
#include "SFMLOrthogonalLayer.hpp"
#include "sprite_sheet.hpp"
#include "weapon.hpp"

class player{

    private:

        sf::Image da_image;
        sf::Texture mage_texture;
        sf::Sprite mage;

        int sprite_width {mage.getScale().x};
        int sprite_height {mage.getScale().x};
        int animation_frame{ 0};
        int animation_speed{ 5}; // Lower is faster    
        int animation_index = { 0};

        bool moving = false;
        int side {0}; // Right 0, left 1

        tmx::Map map;
        MapLayer * collision_layer;

        std::stringstream ss;

        float x = 10;
        float y = 10;
        
        sf::Vector2f movement_offset{0, 0};

        weapon p_weapon;

    public:

        sprite_sheet* mage_sheet;

        sf::IntRect Hitbox {{x, y}, {mage.getScale().x, mage.getScale().y}};

        std::vector<sf::IntRect> collision_tiles;

        player() : mage(mage_texture) {
            std::cout << "Initializing player..." << std::endl;
            
            mage_sheet = new sprite_sheet("mage.png", 11, 16, 144);

            mage.setTexture(mage_texture);
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
            p_weapon = weapon((*mage_sheet).get_sprite_images()[8], x, y);
        }

        ~player() {
            delete mage_sheet;
        }

        // Class methods :
        void update(sf::RenderWindow &window);
        void movement();
        bool check_collision(float x, float y); // For specific coordinates with a tile ... Kind of deprecated.

        // Getters
        float get_x();
        float get_y();

        
        void set_weapon(weapon player_weapon);

        sf::Texture get_spriteImage();
        void collision_check();
        
    };