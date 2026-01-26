#include <SFML/Graphics.hpp>
#include <Player.h>
#include <Map.h>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({320u, 240u}), "Samurai Action Game");
    window.setFramerateLimit(60);

    Player player;
    player.initialize();
    Map map;
    map.initialize();

    auto onWindowClose = [&window](const sf::Event::Closed&)
    {
        window.close();
    };

    auto onKeyPressed = [&player](const sf::Event::KeyPressed& keyPressed)
    {
        player.handleKeyPressed(keyPressed);
    };

    auto onKeyReleased = [&player](const sf::Event::KeyReleased& keyReleased)
    {
        player.handleKeyReleased(keyReleased);
    };

    while (window.isOpen())
    {
        window.handleEvents(onWindowClose, onKeyPressed, onKeyReleased);

        player.update();

        window.clear(sf::Color::Black);
        map.draw(window);
        player.draw(window);
        window.display();
    }
}
