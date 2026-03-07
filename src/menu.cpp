#include "menu.hpp"

void menu_manager::draw_menu() {
    background.draw_bottom(window);
    background.draw_top(window);
    window.draw(text);
    window.draw(text_ready);
}

void menu_manager::update() {
    draw_menu();

    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        in_menu = false;
    }
}