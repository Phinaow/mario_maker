#include "../header/camera.h"

Camera::Camera(float zoom_level, sf::Vector2f position) :
    _zoom_level(zoom_level), _position(position)
{
}

sf::View Camera::getView(sf::Vector2u window_size)
{
    float aspect = (float)window_size.x / (float)window_size.y;
    sf::Vector2f size;

    if(aspect < 1.f)
        size = sf::Vector2f{this->_zoom_level, this->_zoom_level / aspect};
    else
        size = sf::Vector2f{this->_zoom_level * aspect, this->_zoom_level};

    return sf::View{this->_position, size};
}

void Camera::setZoomLevel(float zoom_level)
{
    this->_zoom_level = zoom_level;
}

void Camera::setPosition(sf::Vector2f position)
{
    this->_position = position;
}

sf::Vector2f Camera::getPostion()
{
    return this->_position;
}

float Camera::getZoomLevel()
{
    return this->_zoom_level;
}
