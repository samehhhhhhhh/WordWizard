#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "WordWizard - The game"
    );
    sf::Texture mage_image("tile018.png");
    sf::Sprite mage(mage_image);
    window.setFramerateLimit(60);

    int x = 10;
    int y = 10;

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            x += 5;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
            x -= 5;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
            y -= 5;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            y += 5;
        
        mage.setPosition({x, y});
        window.clear(sf::Color::Black);
        window.draw(mage);
        window.display();
    }

    return 0;
}
