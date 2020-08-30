/*
** EPITECH PROJECT, 2020
** 2d-shadow-raytracing [WSL: Debian]
** File description:
** shapeList
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Shape.hpp"

namespace core::graphics {

    class Rectangle: public Shape {
        public:
            Rectangle(const sf::Vector2f &size = sf::Vector2f(0, 0));
    };

    class Circle: public Shape {
        public:
            Circle(const sf::Vector2f &size = sf::Vector2f(0, 0));
    };

    class Star: public Shape {
        public:
            Star(const sf::Vector2f &size = sf::Vector2f(0, 0));
    };

    class Triangle: public Shape {
        public:
            Triangle(const sf::Vector2f &size = sf::Vector2f(0, 0));
    };

};
