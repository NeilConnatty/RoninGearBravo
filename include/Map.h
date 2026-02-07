#include <SFML/Graphics.hpp>

namespace ldtk
{
class Level;
class Layer;
}

class Map
{
public:
    Map() = default;

    void initialize(const ldtk::Level& level);

    void drawBackground(sf::RenderTarget& target) const;
    void drawWalls(sf::RenderTarget& target) const;
    void drawForeground(sf::RenderTarget& target) const;
    void drawLighting(sf::RenderTarget& target) const;

    // lookup if the position in world coordinates is a wall tile
    std::optional<sf::FloatRect> checkWallCollision(sf::FloatRect box) const;

private:
    struct TileLayer
    {
        sf::VertexArray vertices;
        void draw(sf::RenderTarget& target) const;
    };
    std::array<TileLayer, 4> m_tileLayers;
    void populateTileLayer(TileLayer& tileLayer, const ldtk::Layer& layerDef);
    void populateStaticColliders(const ldtk::Layer& colliderLayer);

    sf::Texture m_tileset{"../../assets/sprites/tileset.png"};

    std::vector<sf::FloatRect> m_staticColliders;

    sf::Texture m_lightingTexture{"../../assets/sprites/lighting.png"};
    sf::Sprite m_lightingSprite{m_lightingTexture};
};