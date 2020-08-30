/*
** EPITECH PROJECT, 2020
** 2d-shadow-raytracing [WSL: Debian]
** File description:
** Events
*/

#include "Events.hpp"
#include "ShapeHandler.hpp"

core::graphics::EventState::EventState(const core::graphics::EventState &eventState)
{
    this->_events = eventState.getEvents();
}

/// Public GET
bool core::graphics::EventState::registerEvents(core::graphics::ShapeEventType event, std::function<void()> callback)
{
    return (this->_events.insert(std::pair<core::graphics::ShapeEventType, std::function<void()>>(event, callback)).second);
}

std::map<core::graphics::ShapeEventType, std::function<void()>> core::graphics::EventState::getEvents() const
{
    return (this->_events);
}

void core::graphics::EventState::testAndTriggerEvent(sf::Event &event, sf::Vector2i mousePos, ShapeHandler *shapeHandler)
{
    sf::Vector2<sf::Vector2f> minMax;

    // Test MouseWheelScrolled Event
    if (event.type == sf::Event::EventType::MouseWheelScrolled) {

    }

    if (event.type == sf::Event::EventType::MouseButtonReleased) {
        if (this->_mouseButtonPressed.find(event.mouseButton.button) != this->_mouseButtonPressed.end()) {
            this->triggerEvent(core::graphics::ShapeEventType::MouseButtonReleased, mousePos);
            this->_mouseButtonPressed[event.mouseButton.button] = false;
        }
    }

    minMax = this->getMinMax();

    // Test MouseButtonPressed Event
    if (this->_mouseButtonPressed)
    if (sf::Vector2i(this->_mouseMove.x, this->_mouseMove.y) != mousePos)
        this->triggerEvent(core::graphics::ShapeEventType::MouseMoved, mousePos);

    // Test MouseLeft Event
    if (mousePos.x < minMax.x.x || mousePos.x > minMax.y.x || mousePos.y < minMax.x.y || mousePos.y > minMax.y.y) {
        if (this->_mouseIn) {
            this->triggerEvent(core::graphics::MouseLeft, mousePos);
            return;
        }
    }

    // Test MouseButtonReleased Event
    // Test MouseMoved Event
    // Test MouseEntered Event
    (void)event;
    (void)mousePos;
    // TODO: Implement this
}

void core::graphics::EventState::triggerEvent(core::graphics::ShapeEventType event, sf::Vector2i mousePos)
{
    (void)event;
    (void)mousePos;
    // TODO: Implement this
}
