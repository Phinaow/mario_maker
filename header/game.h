#pragma once

#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <string>
#include <iostream>

#include "camera.h"
#include "ressources.h"
#include "map.h"

#define WIDTH_GRID_SIZE 500
#define HEIGHT_GRID_SIZE 17

class Game
{
    public :
    //Constructor / Destructor

        Game();
        ~Game();

    //Functions

        void processEvents();
        void update();
        void render();

    //Accessor

        bool isWindowOpen();

    private :
    /*------Window------*/
    //Variables

        sf::RenderWindow *_window;
        Camera _camera;

        sf::RectangleShape _rectangle;

    //Functions

        void initWindow();

    /*------Window------*/

    /*------Sprites------*/
    //Variables

        Ressources _ressources;

    //Functions

        void init_Ressources();
        void setSprite(std::string name, sf::Vector2f position, sf::Vector2f size);

    /*------Sprites------*/ 

    /*------Map------*/
    //Variables

        Map _map{};
        int choice;

    //Functions

        void initMap();
        void drawMap();

    /*------Map------*/  
};