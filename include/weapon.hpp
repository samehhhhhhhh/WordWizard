

#include <SFML/Graphics.hpp>

class weapon {

    sf::Vector2f player_coordinates;
    float* x = nullptr;
    float* y = nullptr;

    std::vector<sf::Image> anim_sequence;
    struct Projectile {
        sf::Vector2f position;
        sf::Vector2f vector;
    };

    std::vector<Projectile> projectiles;
    int projectile_size {15};

    sf::Vector2f draw_coordinates{0.0f, 0.0f};

    int shoot_delay {}; // Change this
    int shoot_counter {0};

    public:
        weapon() {} // Default: x and y are nullptr
        weapon(std::vector<sf::Image> anim_sequence, float & px, float & py, int delay)
            : anim_sequence(anim_sequence), x(&px), y(&py), shoot_delay(delay)
        {}

        void draw(sf::RenderWindow & window);
        void shoot(sf::RenderWindow & window);
        void calculate_draw(sf::RenderWindow & window);
        void upd_projectile_pos();
        void update(sf::RenderWindow & window);
        


};