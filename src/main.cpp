#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "WordWizard - The game"
    );
    sf::Texture mage_image;
    sf::Sprite mage(mage_image);
    int animation_frame{ 0};
    int animation_speed{ 10}; // Lower is faster
    window.setFramerateLimit(60);
    int animation_index = { 0};
    float x = 10;
    float y = 10;

    std::stringstream ss;

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
// At each iteration of the loop, we check what key is pressed then :
/* 
change the texture accordingly to the direction of movement.

7 images per direction

*/
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            x += 5;
            if(animation_frame >= animation_speed) {
                ss << "tile0" << 27+animation_index << ".png";
                mage_image.loadFromFile(ss.str());
                animation_frame = 0;
            }
            
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
            x -= 5;
            if(animation_frame >= animation_speed) {
            ss << "tile0" << 10+animation_index << ".png";
            mage_image.loadFromFile(ss.str());
            animation_frame = 0;
        }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
            y -= 5;
            if(animation_frame >= animation_speed) {
            ss << "tile00" << animation_index << ".png";
            mage_image.loadFromFile(ss.str());
            animation_frame = 0;
        }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            y += 5;
            if(animation_frame >= animation_speed) {
            ss << "tile0" << 18+animation_index << ".png";
            mage_image.loadFromFile(ss.str());
            animation_frame = 0;
        }
        } else {
            mage_image.loadFromFile("tile018.png");
            
        }
        animation_index +=1;
        
        if(animation_index >= 7) {
            animation_index = 0;
        }
        
        
        ss.str("");
        mage.setTexture(mage_image, true);
        
        mage.setPosition({x, y});
        window.clear(sf::Color::Black);
        window.draw(mage);
        window.display();
        animation_frame++;
    }

    return 0;
}
