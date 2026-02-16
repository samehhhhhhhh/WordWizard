#include "weapon.hpp"
#include <cmath>

void weapon::update(sf::RenderWindow & window) {
    calculate_draw(window);
    upd_projectile_pos();
    draw(window);
}

void weapon::calculate_draw(sf::RenderWindow & window) {
    if (!x || !y) return; // Safety check

    int circle_rayon {40};
    sf::Vector2i mouse_pos_screen = sf::Mouse::getPosition(window);
    sf::Vector2f mouse_pos = window.mapPixelToCoords(mouse_pos_screen);


    float tx = *x + 15; // t for true position of the player center 
    float ty = *y + 20;

    sf::Vector2f vector1 {mouse_pos.x - tx, mouse_pos.y - ty};

    int vector1_length {static_cast<int>(std::sqrt(std::pow(vector1.x, 2) + std::pow(vector1.y, 2)))};

    // Normalize the vector to unit length, then scale to circle_rayon
    sf::Vector2f normalized {vector1.x / vector1_length, vector1.y / vector1_length};
    sf::Vector2f vector2 {normalized.x * circle_rayon, normalized.y * circle_rayon};

    draw_coordinates = {vector2.x + tx, vector2.y + ty};

}

void weapon::upd_projectile_pos() {
    for(auto & projectile: projectiles) {
        projectile.position.x += projectile.vector.x * 3;
        projectile.position.y += projectile.vector.y * 3;
    }
}

void weapon::draw(sf::RenderWindow & window) {
    
    // Sprite setup
    sf::Texture weapon_texture(anim_sequence[0]);
    sf::Sprite weapon_sprite(weapon_texture);
    weapon_sprite.setPosition(draw_coordinates);
    window.draw(weapon_sprite);

    // Drawing projectiles 
    for(auto & projectile: projectiles) {
        sf::CircleShape shape;
        shape.setRadius(projectile_size);
        shape.setPosition(projectile.position);
        window.draw(shape);
    }
}

void weapon::shoot(sf::RenderWindow & window) {
    // Calculate direction from weapon to mouse
    sf::Vector2i mouse_pos_screen = sf::Mouse::getPosition(window); 
    sf::Vector2f mouse_pos = window.mapPixelToCoords(mouse_pos_screen);
    
    sf::Vector2f direction{mouse_pos.x - draw_coordinates.x, mouse_pos.y - draw_coordinates.y};
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    
    if (length > 0) {
        direction.x /= length;
        direction.y /= length;
    }
    
    projectiles.push_back({draw_coordinates, direction});
}