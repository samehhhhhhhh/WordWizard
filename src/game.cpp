

#include "game.hpp"
#include "player.hpp"
#include "level_manager.hpp"

void game::run() {

    sf::View view;
    view.setSize({800.f, 600.f});
    player m_player;
    level_manager m_level;

    
    while (window.isOpen())
    {
        
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        view.setCenter({m_player.x, m_player.y});
        window.setView(view);

        window.clear(sf::Color::Black);
        m_player.movement();
        m_level.draw_bottom(window);
        m_player.update(window);
        m_level.draw_top(window);
        
        
        window.display();
        
    }
}