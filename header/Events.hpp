/*
** EPITECH PROJECT, 2020
** 2d-shadow-raytracing [WSL: Debian]
** File description:
** Events
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "ShapeHandler.hpp"
#include "core.hpp"

namespace core::graphics {

    enum ShapeEventType {
        MouseWheelScrolled = sf::Event::EventType::Count,     ///< The mouse wheel was scrolled (data in event.mouseWheelScroll)
        MouseButtonPressed,                                   ///< A mouse button was pressed (data in event.mouseButton)
        MouseButtonReleased,                                  ///< A mouse button was released (data in event.mouseButton)
        MouseMoved,                                           ///< The mouse cursor moved (data in event.mouseMove)
        MouseEntered,                                         ///< The mouse cursor entered the area of the window (no data)
        MouseLeft,                                            ///< The mouse cursor left the area of the window (no data)

        Count                                                 ///< Keep last -- the total number of event types
    };

    class EventState {

        public:
            EventState() = default;
            EventState(const EventState &eventState);
            bool registerEvents(ShapeEventType event, std::function<void()> callback);
            void testAndTriggerEvent(sf::Event &event, sf::Vector2i mousePos, ::ShapeHandler *shapeHandler = nullptr);

        public OPE:
            virtual sf::Vector2<sf::Vector2f> getMinMax() const = 0;
            virtual sf::Vector2f getMin() const = 0;
            virtual sf::Vector2f getMax() const = 0;

        public GET:
            std::map<ShapeEventType, std::function<void()>> getEvents() const;

        protected:

        private:
            void triggerEvent(ShapeEventType event, sf::Vector2i mousePos);

        protected:
            ShapeEventType _type = ShapeEventType::Count;
            bool _mouseIn = false;

            sf::Vector2f                       _mouseMove;           ///< Mouse move event parameters (Event::MouseMoved)
            std::map<sf::Mouse::Button, bool>  _mouseButtonPressed;  ///< Mouse button event parameters (Event::MouseButtonPressed, Event::MouseButtonReleased)
            sf::Event::MouseWheelScrollEvent   _mouseWheelScroll;    ///< Mouse wheel event parameters (Event::MouseWheelScrolled)

            std::map<ShapeEventType, std::function<void()>> _events;
    };

}
