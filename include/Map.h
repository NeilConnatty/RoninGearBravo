#include <SFML/Graphics.hpp>

class Map
{
public:
    Map() = default;

    void initialize();
    void draw(sf::RenderTarget& target);

private:
    sf::Texture m_backgroundTileset{"../../assets/sprites/background-tileset.png"};
    sf::Texture m_wallsTileset{"../../assets/sprites/walls-tileset.png"};
    sf::VertexArray m_backgroundVertices;
    sf::VertexArray m_wallsVertices;
};