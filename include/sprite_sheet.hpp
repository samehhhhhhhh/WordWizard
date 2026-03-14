// Instead of using sprites images, let's use sprite sheet.
#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

class sprite_sheet {
    sf::Image sheet_image{};
    unsigned int width{};
    unsigned int height{};
    unsigned int block_offset{};
    unsigned int width_offsetx{};

    std::vector<std::vector<sf::Image>> sprite_images{};

public:
    sprite_sheet(const std::filesystem::path& sheet_image_path,
                 unsigned int frame_width,
                 unsigned int frame_height,
                 unsigned int block_offsetx,
                 unsigned int width_offsetx = 0);
        
        

    const std::vector<std::vector<sf::Image>>& get_sprite_images() const {
        return sprite_images;
    }
};