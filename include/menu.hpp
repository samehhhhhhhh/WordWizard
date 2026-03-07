

#include <SFML/Graphics.hpp>
#include "level_manager.hpp"

class menu_manager {

    bool in_menu {true};
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text text;
    sf::Text text_ready;
    level_manager background;

    void draw_menu();

public :

    // Constructor
    menu_manager(sf::RenderWindow& game_window)
     : font("Cinzel-Black.ttf"), text_ready(font) ,text(font), window(game_window) {

        // Main menu game name title
        text.setString("Word Wizard !");
        text.setPosition({300, 150});
        text.setCharacterSize(30);
        text.setStyle(sf::Text::Bold);
        text.setOutlineColor(sf::Color::Black);
        text.setOutlineThickness(5);
        text.setFillColor(sf::Color::White);

        text_ready.setString("Press <Space> to start");
        text_ready.setPosition({300, 300});
        text_ready.setCharacterSize(10);
        text_ready.setStyle(sf::Text::Bold);
        text_ready.setOutlineColor(sf::Color::Black);
        text_ready.setOutlineThickness(5);
        text_ready.setFillColor(sf::Color::White);

    } 
    void update();
    bool get_in_menu() {
        return in_menu;
    }
};