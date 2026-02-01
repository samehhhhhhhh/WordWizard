// Instead of using sprites images, let's use sprite sheet.
#include <SFML/Graphics.hpp>
#include <iostream>
class sprite_sheet {

    sf::Image sheet_image;
    int width, height;
    int block_offset;
    
    std::vector<std::vector<sf::Image>> sprite_images {};

    public: 
    
    sprite_sheet(std::string sheet_image_path, int width, int height, int block_offsetx) 
        : width(width), height(height), block_offset(block_offsetx) {

        sheet_image.loadFromFile(sheet_image_path);
        auto sheet_size {sheet_image.getSize()};
        std::cout << "Sprite sheet loading" << std::endl;

        for(int keyframe_y = 0; keyframe_y <= sheet_size.y-height; keyframe_y += height) {
            
            for(int keyframe_x = 2; keyframe_x <= block_offset-width; keyframe_x+= width+4) {
                
                std::vector<sf::Image> keyframes;

                for(int key_frame_sequence = 0; key_frame_sequence < sheet_size.x/block_offset; key_frame_sequence++) {
                    
                    // Create temporary with the correct size before copying
                    sf::Image temporary({width, height}, sf::Color::Transparent);
                    temporary.copy(sheet_image, {0, 0}, sf::IntRect(sf::Vector2{keyframe_x + (key_frame_sequence * block_offset), keyframe_y}, sf::Vector2{width, height}));
                    keyframes.push_back(temporary);
                }
                
                sprite_images.push_back(keyframes);

            }
        }  
        std::cout << "Sprite sheet loaded" << std::endl;
    }

    

    std::vector<std::vector<sf::Image>> get_sprite_images() {
        return sprite_images;
    }

    

};