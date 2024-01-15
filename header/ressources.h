#pragma once

#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <filesystem>
#include <string>

class Ressources
{
    public :

        void initTextures();

        std::unordered_map<std::string, sf::Texture> _textures;
        std::unordered_map<std::string, sf::Sprite> _sprites;
};