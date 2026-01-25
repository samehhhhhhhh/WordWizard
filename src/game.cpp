

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

        std::cout << "Collision state : " << m_player.check_collision() << std::endl;
        window.clear(sf::Color::Black);
        // m_player.check_collision(m_level.map, m_level.layerTwo);
        m_player.movement();
        m_level.draw_bottom(window);
        m_player.update(window);
        m_level.draw_top(window);
        
        
        window.display();
        
    }
}