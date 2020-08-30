
#include <SFML/Graphics.hpp>

#include "ShapeHandler.hpp"
#include "shapeList.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "2d RayTracing");
    ShapeHandler handler(window);
    core::graphics::Rectangle shape(sf::Vector2f(60, 60));
    shape.setFillColor(sf::Color::Green);
    handler.addShape(shape);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        handler.render(window);
        window.display();
    }

    return 0;
}
