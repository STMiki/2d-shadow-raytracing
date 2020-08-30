/*
** EPITECH PROJECT, 2020
** 2d-shadow-raytracing [WSL: Debian]
** File description:
** ShapeHandler
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "ShapeHandler.hpp"

ShapeHandler::ShapeHandler(sf::RenderWindow &window): _window(&window)
{
}

ShapeHandler::~ShapeHandler()
{
}

core::graphics::Shape &ShapeHandler::operator[](uint64_t index)
{
    return (*this->_shapes[index]);
}

void ShapeHandler::addShape(core::graphics::Shape &shape)
{
    this->_shapes.push_back(&shape);
}

bool ShapeHandler::removeShape(core::graphics::Shape &shape)
{
    for (uint64_t i = 0; i < this->_shapes.size(); i += 1) {
        if (*this->_shapes[i] != shape)
            continue;
        this->_shapes.erase(this->_shapes.begin() + i);
        return (true);
    }
    return (false);
}

bool ShapeHandler::removeShape(uint64_t index)
{
    auto iterator = this->_shapes.begin() + index;

    if (this->_shapes.size() <= index)
        return (false);
    this->_shapes.erase(iterator);
    return (true);
}

void ShapeHandler::render(sf::RenderWindow &window)
{
    for (auto shape : this->_shapes)
        window.draw(*shape);
}

void ShapeHandler::setWindow(sf::RenderWindow &window)
{
    this->_window = &window;
}

sf::RenderWindow &ShapeHandler::getWindow() const
{
    return (*this->_window);
}


void ShapeHandler::testAndTriggerEvent(sf::Event &event)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*this->_window);

    for (auto shape : this->_shapes)
        shape->testAndTriggerEvent(event, mousePos);
}
