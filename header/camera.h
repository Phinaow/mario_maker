#pragma once

#include <SFML/Graphics.hpp>

class Camera
{
    public :

        Camera(float zoom_level = 100.f, sf::Vector2f position = sf::Vector2f{0.f, 0.f});

        sf::View getView(sf::Vector2u window_size);

        void setZoomLevel(float zoom_level);
        void setPosition(sf::Vector2f position);

        sf::Vector2f getPostion();
        float getZoomLevel();

    private :

        float _zoom_level;
        sf::Vector2f _position;
};