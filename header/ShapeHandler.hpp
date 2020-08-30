/*
** EPITECH PROJECT, 2020
** 2d-shadow-raytracing [WSL: Debian]
** File description:
** ShapeHandler
*/

#pragma once

#include "core.hpp"
#include "Shape.hpp"

class ShapeHandler {
    public:
        ShapeHandler(sf::RenderWindow &window);
        ~ShapeHandler();
        void addShape(core::graphics::Shape &shape);
        bool removeShape(core::graphics::Shape &shape);
        bool removeShape(uint64_t index);
        void render(sf::RenderWindow &window);
        void testAndTriggerEvent(sf::Event &event);

    public OPE:
        core::graphics::Shape &operator[](uint64_t index);

    public SET:
        void setWindow(sf::RenderWindow &window);

    public GET:
        sf::RenderWindow &getWindow() const;

    private:
        std::vector<core::graphics::Shape*> _shapes;
        sf::RenderWindow *_window;
};
