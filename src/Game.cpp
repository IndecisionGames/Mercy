#include "Game.h"
#include "RQ_Engine.h"

using namespace RQEngine;

Game::Game()
    : window("Mercy", 1280, 720, 120) {}

void Game::Start() {
   
    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);

    // Load resources
    if (RM.loadTexture("assets/textures/wall128x128.png", "wall")) {
        printf("Loaded texture\n");
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            sf::Sprite sprite = ResourceManager::createSprite("wall", 0, 0, 128, 128); //createSprite will be moved to a different class
            sprite.setPosition(128.0f * i, 128.0f * j);
            walls.push_back(sprite);
        }
    }

};

void Game::Update(uint64_t deltaTime) {
    window.Update();

    if (IM.isKeyUp(KeyCode::MouseLeft)) {
        std::cout << "MB1 Released" << std::endl;
        held = false;

    }
    else if (IM.isKeyPressed(KeyCode::MouseLeft)) {

        if (IM.isKeyHeld(KeyCode::MouseLeft)) {
            if (!held) {
                std::cout << "MB1 Held" << std::endl;
                held = true;
            }
        }
        else {
            std::cout << "MB1 Pressed" << std::endl;

        }
    }
};


void Game::Draw() {
    window.PrepareFrame();
    for (auto s : walls) {
        window.Draw(s);
    }
    window.DrawFrame();
};

bool Game::IsRunning() {
    return window.IsOpen();
};

void Game::Quit() {
    ResourceManager::cleanUp();
};