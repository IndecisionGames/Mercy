#include "RQ_Engine.h"

using namespace RQEngine;

class Game: public GameObject {
private:
    Window window;
    InputManager IM;
    ResourceManager RM;
    int count = 0;
    bool held = false;
    std::vector <sf::Sprite> walls;

public:
    Game();
    void Start();
    void Update(uint64_t deltaTime);
    void Draw();
    void Quit();
    bool IsRunning();
};