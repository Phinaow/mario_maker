#include "../header/game.h"

Game::Game()
{
    this->initWindow();
    this->init_Ressources();
    this->initMap();
    this->_camera.setZoomLevel(200.f);

    float pos = ((((float)this->_window->getSize().x/10.f) - 200.f) / 2.f) + 200.f - this->_map._cell_size / 2.f;
    //float pos = WIDTH_GRID_SIZE * 10 - (float)this->_window->getSize().x / 20.f - 100.f + this->_map._cell_size / 2.f;

    this->_camera.setPosition(sf::Vector2f{pos, 100.f});
    this->choice = 1;
}

Game::~Game()
{
    sf::Image image;

    image.create(WIDTH_GRID_SIZE, HEIGHT_GRID_SIZE, sf::Color::Blue);

    for(int i = 0; i < this->_map.grid.size(); i++)
    {
        for(int j = 0; j < this->_map.grid[i].size(); j++)
        {
            if(this->_map.grid[i][j] == 1)
                image.setPixel(i, j, sf::Color::Black);
            else
                image.setPixel(i, j, sf::Color::White);
        }
    }

    image.saveToFile("Out1.png");

    delete this->_window;
}

void Game::processEvents()
{
    sf::Event event;
    while(this->_window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            this->_window->close();

        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
                this->_window->close();
        }
    }
}

void Game::update()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        sf::Vector2f pos = this->_window->mapPixelToCoords(sf::Mouse::getPosition(*this->_window));
        int x = (int)(pos.x / this->_map._cell_size);
        int y = (int)(pos.y / this->_map._cell_size);

        if(x == (int)(this->_camera.getPostion().x / this->_map._cell_size) + 2 && y == HEIGHT_GRID_SIZE + 1)
            this->choice = 0;

        if(x == (int)(this->_camera.getPostion().x / this->_map._cell_size) - 2 && y == HEIGHT_GRID_SIZE + 1)
            this->choice = 1;

        if(x >= 0 && x < WIDTH_GRID_SIZE && y >= 0 && y < HEIGHT_GRID_SIZE)
        {
            this->_map.grid[x][y] = this->choice;
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && this->_camera.getPostion().x > ((((float)this->_window->getSize().x/10.f) - 200.f) / 2.f) + 200.f - this->_map._cell_size / 2.f)
        this->_camera.setPosition(sf::Vector2f{this->_camera.getPostion().x - 10, this->_camera.getPostion().y});

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->_camera.getPostion().x < WIDTH_GRID_SIZE * 10 - (float)this->_window->getSize().x / 20.f - 100.f + this->_map._cell_size / 2.f)
        this->_camera.setPosition(sf::Vector2f{this->_camera.getPostion().x + 10, this->_camera.getPostion().y});

}

void Game::render()
{
    this->_window->setView(this->_camera.getView(this->_window->getSize()));

    this->_window->clear(sf::Color::Black);
    this->drawMap();

    this->_window->display();
}

bool Game::isWindowOpen()
{
    return this->_window->isOpen();
}

void Game::initWindow()
{
    this->_window = new sf::RenderWindow{sf::VideoMode::getFullscreenModes()[2], "Window", sf::Style::Fullscreen};
    this->_window->setFramerateLimit(60);
}

void Game::init_Ressources()
{
    this->_ressources.initTextures();
}

void Game::setSprite(std::string name, sf::Vector2f position, sf::Vector2f size)
{
    sf::Texture texture = this->_ressources._textures[name];

    this->_ressources._sprites[name].setPosition(position);
    this->_ressources._sprites[name].setOrigin((sf::Vector2f)texture.getSize() / 2.f);
    this->_ressources._sprites[name].setScale(size.x / (float)texture.getSize().x, size.y / (float)texture.getSize().y);
}

void Game::initMap()
{
    this->_map.createCheckerboard(WIDTH_GRID_SIZE, HEIGHT_GRID_SIZE);
}

void Game::drawMap()
{
    sf::Vector2f pos;

    pos.x = 500;
    pos.y = 100;
    this->setSprite("sky.png", pos, sf::Vector2f{2000, 400});
    this->_window->draw(this->_ressources._sprites["sky.png"]);

    int size_x = (int)(this->_camera.getPostion().x / 10.f);

    for (int i = size_x - 17; i < size_x + 18; i++)
    {
        for (int j = 0; j < this->_map.grid[i].size(); j++)
        {
            if (this->_map.grid[i][j] == 1)
            {
                pos.x = this->_map._cell_size / 2.f + i * this->_map._cell_size;
                pos.y = this->_map._cell_size / 2.f + j * this->_map._cell_size;
                this->setSprite("brick.png", pos, sf::Vector2f{this->_map._cell_size, this->_map._cell_size});
                this->_window->draw(this->_ressources._sprites["brick.png"]);
            }
            else
            {
                pos.x = this->_map._cell_size / 2.f + i * this->_map._cell_size;
                pos.y = this->_map._cell_size / 2.f + j * this->_map._cell_size;
                this->setSprite("cell.png", pos, sf::Vector2f{this->_map._cell_size, this->_map._cell_size});
                this->_window->draw(this->_ressources._sprites["cell.png"]);
            }
        }
    }

    pos.x = this->_map._cell_size / 2.f + this->_camera.getPostion().x - 2.f * this->_map._cell_size;
    pos.y = this->_map._cell_size / 2.f + (HEIGHT_GRID_SIZE + 1) * this->_map._cell_size;
    this->setSprite("brick.png", pos, sf::Vector2f{this->_map._cell_size, this->_map._cell_size});
    this->_window->draw(this->_ressources._sprites["brick.png"]);

    pos.x = this->_map._cell_size / 2.f + this->_camera.getPostion().x + 2.f * this->_map._cell_size;
    pos.y = this->_map._cell_size / 2.f + (HEIGHT_GRID_SIZE + 1) * this->_map._cell_size;
    this->setSprite("cell.png", pos, sf::Vector2f{this->_map._cell_size, this->_map._cell_size});
    this->_window->draw(this->_ressources._sprites["cell.png"]);
}
