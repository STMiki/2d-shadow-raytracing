/*
** EPITECH PROJECT, 2020
** 2d-shadow-raytracing [WSL: Debian]
** File description:
** Shape
*/

#include <SFML/Graphics.hpp>
#include <functional>
#include "Shape.hpp"
#include "Events.hpp"

core::graphics::Shape::Shape()
{
}

core::graphics::Shape::Shape(const core::graphics::Shape &shape): EventState(shape)
{
    this->_points = shape.getPoints();
}

core::graphics::Shape::~Shape()
{
}

/// Public

/// Public OPE
bool core::graphics::Shape::operator==(core::graphics::Shape &other)
{
    auto otherPointsVector = other.getPoints();
    auto otherPoint = otherPointsVector.begin();

    if (otherPointsVector.size() != this->_points.size())
        return (false);
    for (uint64_t i = 0; i < this->_points.size(); i += 1) {
        if (this->_points.begin() + i != otherPoint)
            return (false);
        otherPoint++;
    }
    return (true);
}

bool core::graphics::Shape::operator!=(core::graphics::Shape &other)
{
    return (!(*this == other));
}

core::graphics::Shape &core::graphics::Shape::operator=(const Shape &self)
{
    if (this == &self)
        return *this;
    this->_points = self.getPoints();
    this->_events = self.getEvents();
    return (*this);
}

/// Public GET
std::vector<sf::Vector2f> core::graphics::Shape::getPoints() const
{
    return (this->_points);
}

sf::Vector2f core::graphics::Shape::getPoint(std::size_t index) const
{
    return (this->_points[index]);
}

std::size_t core::graphics::Shape::getPointCount() const
{
    return (this->_points.size());
}

/// Public SET
void core::graphics::Shape::addPoint(sf::Vector2f point)
{
    this->_points.push_back(point);
    this->update();
}

sf::Vector2f core::graphics::Shape::getMin() const
{
    sf::Vector2f result;

    if (this->_points.size() == 0)
        return sf::Vector2f(-1, -1);
    for (auto point : this->_points) {
        if (result.x > point.x)
            result.x = point.x;
        if (result.y > point.y)
            result.y = point.y;
    }
    return (result);
}

sf::Vector2f core::graphics::Shape::getMax() const
{
    sf::Vector2f result;

    if (this->_points.size() == 0)
        return sf::Vector2f(-1, -1);
    for (auto point : this->_points) {
        if (result.x < point.x)
            result.x = point.x;
        if (result.y < point.y)
            result.y = point.y;
    }
    return (result);
}


sf::Vector2<sf::Vector2f> core::graphics::Shape::getMinMax() const
{
    sf::Vector2<sf::Vector2f> result;

    if (this->_points.size() == 0)
        return (sf::Vector2<sf::Vector2f>(sf::Vector2f(-1, -1), sf::Vector2f(-1, -1)));
    for (auto point : this->_points) {
        // Min
        if (result.x.x > point.x)
            result.x.x = point.x;
        if (result.x.y > point.y)
            result.x.y = point.y;
        // Max
        if (result.y.x < point.x)
            result.y.x = point.x;
        if (result.y.y < point.y)
            result.y.y = point.y;
    }
    return (result);
}
