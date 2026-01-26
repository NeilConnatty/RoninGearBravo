#include <SFML/Graphics.hpp>

class Map
{
public:
    Map() = default;

    void initialize();
    void draw(sf::RenderTarget& target);

private:
    sf::Texture m_tileset{"../../assets/sprites/tileset.png"};
    sf::VertexArray m_vertices;
};