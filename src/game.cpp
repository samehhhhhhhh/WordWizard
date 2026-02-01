

#include "game.hpp"
#include "player.hpp"
#include "level_manager.hpp"

void game::run() {

    sf::View view;
    view.setSize({800.f, 600.f});
    level_manager m_level;
    player m_player;

    while (window.isOpen())
    {
        
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        view.setCenter({m_player.get_x(), m_player.get_y()});
        window.setView(view);
        window.clear(sf::Color::Black);
        m_level.draw_bottom(window);
        m_player.update(window);
        m_level.draw_top(window);
        
 /*       
        // Player Hitbox drawing.
        sf::RectangleShape hitbox(sf::Vector2f(30,30));
        hitbox.setPosition(sf::Vector2f(m_player.get_x(), m_player.get_y()+30));
        hitbox.setSize(sf::Vector2f(m_player.get_spriteImage().getSize().x+20, m_player.get_spriteImage().getSize().y));
        hitbox.setFillColor(sf::Color(255, 0, 0, 100)); // Green with transparency
        window.draw(hitbox);

        // Collision tiles hitbox drawing.
        for (const auto& tile : m_player.collision_tiles) {
            sf::RectangleShape collision_rect(sf::Vector2f(30, 30));
            collision_rect.setPosition(sf::Vector2f(tile.position));
            collision_rect.setFillColor(sf::Color(255, 0, 0, 100)); // Red with transparency
            window.draw(collision_rect);
        }
*/

        // De despley
        window.display(); 
        
    }
}