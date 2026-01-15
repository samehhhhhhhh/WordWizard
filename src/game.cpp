

#include "game.hpp"
#include "player.hpp"
#include "level_manager.hpp"

void game::run() {

    player m_player;
    level_manager m_level;
    while (window.isOpen())
    {
        
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::Black);
        m_player.movement();
        m_level.draw_bottom(window);
        m_player.update(window);
        
        
        window.display();
        
    }
}