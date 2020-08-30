/*
** EPITECH PROJECT, 2020
** 2d-shadow-raytracing [WSL: Debian]
** File description:
** Shape
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "Events.hpp"
#include "core.hpp"

namespace core::graphics {
    class Shape: public sf::Shape, public core::graphics::EventState {
        public:
            Shape();
            Shape(const Shape &self);
            ~Shape();

        public OPE:
            bool operator==(core::graphics::Shape &other);
            bool operator!=(core::graphics::Shape &other);
            sf::Vector2<sf::Vector2f> getMinMax() const override;
            sf::Vector2f getMin() const override;
            sf::Vector2f getMax() const override;
            Shape &operator=(const Shape &self);

        public GET:
            std::vector<sf::Vector2f> getPoints() const;
            sf::Vector2f getPoint(std::size_t index) const override;
            std::size_t getPointCount() const override;

        public SET:
            void addPoint(sf::Vector2f point = sf::Vector2f(0, 0));

        protected:
            std::vector<sf::Vector2f> _points;
            // void update();
    };
};
