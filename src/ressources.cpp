#include "../header/ressources.h"

void Ressources::initTextures()
{
    for(auto& file : std::filesystem::directory_iterator("./ressources/textures/"))
    {
        if(file.is_regular_file() && (file.path().extension() == ".png" || file.path().extension() == ".jpg"))
        {
            if(!this->_textures[file.path().filename().string()].loadFromFile(file.path().string()))
                exit(EXIT_FAILURE);
            else
                this->_sprites[file.path().filename().string()].setTexture(this->_textures[file.path().filename().string()]);
        }
    }
}
