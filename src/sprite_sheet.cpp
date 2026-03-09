#include "sprite_sheet.hpp"

sprite_sheet::sprite_sheet(const std::filesystem::path& sheet_image_path,
                 unsigned int frame_width,
                 unsigned int frame_height,
                 unsigned int block_offsetx)
        : width(frame_width), height(frame_height), block_offset(block_offsetx) {
        if (width == 0 || height == 0 || block_offset == 0) {
            std::cerr << "Invalid sprite sheet parameters: width/height/block_offset must be > 0\n";
            return;
        }

        if (!sheet_image.loadFromFile(sheet_image_path)) {
            std::cerr << "Error loading sprite sheet at path: " << sheet_image_path << '\n';
            return;
        }

        const sf::Vector2u sheet_size = sheet_image.getSize();

        if (sheet_size.x < width || sheet_size.y < height) {
            std::cerr << "Sprite sheet too small for requested frame size\n";
            return;
        }

        unsigned int start_x = 2;
        if (start_x + width > sheet_size.x) {
            start_x = 0;
        }

        for (unsigned int keyframe_y = 0; keyframe_y + height <= sheet_size.y; keyframe_y += height) {
            // Fine up to here
            // iterate only across the first block to find each animation entry
            for (unsigned int keyframe_x = start_x;
                 keyframe_x + width <= 144;
                 keyframe_x += width+5) {
                std::vector<sf::Image> keyframes{};

                // collect one frame from each horizontal block at the same relative x
                for (unsigned int b = 0; b < 6; b++) {
                    unsigned int seq_x = keyframe_x + b * block_offset;

                    sf::Image frame{};
                    frame.resize({width, height}, sf::Color::Transparent);

                    const sf::IntRect src_rect{
                        {static_cast<int>(seq_x), static_cast<int>(keyframe_y)},
                        {static_cast<int>(11), static_cast<int>(16)}
                    };

                    if (frame.copy(sheet_image, {0, 0}, src_rect, true)) {
                        keyframes.push_back(frame);
                    }
                }
                sprite_images.push_back(keyframes);   
            } 
        }
    }