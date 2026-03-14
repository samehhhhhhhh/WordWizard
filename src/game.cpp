

#include "game.hpp"
#include "player.hpp"
#include "level_manager.hpp"
#include "enemy.hpp"
#include "menu.hpp"
void game::run() {

    
    sf::View view;
    view.setSize({800.f, 600.f});
    level_manager m_level;
    player m_player;
    menu_manager m_menu(window);
    enemy m_enemy;

    while (window.isOpen())
    {
        
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if(m_menu.get_in_menu()) {
            m_menu.update();
        } else {
            view.setCenter({m_player.get_x(), m_player.get_y()});
            window.setView(view);
            window.clear(sf::Color::Black);
            m_level.draw_bottom(window);
            m_player.update(window);
            m_level.draw_top(window);
            m_enemy.update(window);
        }

       
        

        // Player Hitbox drawing.
        sf::RectangleShape hitbox(sf::Vector2f(30,30));
        hitbox.setPosition(sf::Vector2f(m_player.get_x(), m_player.get_y()));
        hitbox.setSize(sf::Vector2f(m_player.get_hitsx(), m_player.get_hitsy()));
        hitbox.setFillColor(sf::Color(255, 0, 0, 100)); // Green with transparency
        window.draw(hitbox);

        // Collision tiles hitbox drawing.
        for (const auto& tile : m_player.collision_tiles) {
            sf::RectangleShape collision_rect(sf::Vector2f(30, 30));
            collision_rect.setPosition(sf::Vector2f(tile.position));
            collision_rect.setFillColor(sf::Color(255, 0, 0, 100)); // Red with transparency
            window.draw(collision_rect);
        }


        // De despley
        window.display(); 
        
    }
}