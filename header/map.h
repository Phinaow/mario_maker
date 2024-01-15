#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <unordered_map>
#include <string>

class Map
{
    public :

        Map(float cell_size = 10.f);
        void setCellSize(float cell_size);
        void createCheckerboard(size_t width, size_t height);

        std::vector<std::vector<int>> grid;
        float _cell_size;
};