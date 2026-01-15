
#include <SFML/Graphics.hpp>

class game {
    sf::RenderWindow window;
    
    
    public:

    game() {
        window = sf::RenderWindow(sf::VideoMode({800, 600}), "WordWizard - The game");
        
        window.setFramerateLimit(60);
        
    }

    void run();
};