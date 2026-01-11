#include <SFML/Graphics.hpp> 

class Player
{
public:
    Player() = default;

    void initialize();
    void handleKeyPressed(const sf::Event::KeyPressed& keyPressed);
    void handleKeyReleased(const sf::Event::KeyReleased& keyReleased);
    void update();
    void draw(sf::RenderTarget& target);

private:
    sf::Transform m_transform{sf::Transform::Identity};
    std::array<bool, 4> m_inputs;
    sf::Texture m_texture{"../../assets/sprites/character.png"};
    sf::Sprite m_sprite{m_texture};
};