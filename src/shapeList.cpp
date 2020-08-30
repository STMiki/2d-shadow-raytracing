/*
** EPITECH PROJECT, 2020
** 2d-shadow-raytracing [WSL: Debian]
** File description:
** shapeList
*/

#include <SFML/Graphics.hpp>
#include "shapeList.hpp"


core::graphics::Rectangle::Rectangle(const sf::Vector2f &size)
{
    sf::Vector2f rectangleOrigin = sf::Vector2f(0, 0);
    this->addPoint(rectangleOrigin);
    this->addPoint(sf::Vector2f(rectangleOrigin.x + size.x, rectangleOrigin.y));
    this->addPoint(rectangleOrigin + size);
    this->addPoint(sf::Vector2f(rectangleOrigin.x, rectangleOrigin.y + size.y));
}

core::graphics::Circle::Circle(UNUSED const sf::Vector2f &size)
{

}

core::graphics::Star::Star(UNUSED const sf::Vector2f &size)
{

}

core::graphics::Triangle::Triangle(UNUSED const sf::Vector2f &size)
{

}
