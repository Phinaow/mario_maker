#include "../header/map.h"

Map::Map(float cell_size) : _cell_size(cell_size)
{
}

void Map::setCellSize(float cell_size)
{
    this->_cell_size = cell_size;
}

void Map::createCheckerboard(size_t width, size_t height)
{
    sf::Image image;
    image.loadFromFile("./ressources/images/map.png");

    this->grid = std::vector(width, std::vector(height, 0));

    int last = 0;
    int i = 0, j = 0;
    for(auto& column : grid)
    {
        for(auto& cell : column)
        {
            if(image.getPixel(i, j) == sf::Color::Black)
                cell = 1;
            j++;
        }
        j = 0;
        i++;
    }
}
