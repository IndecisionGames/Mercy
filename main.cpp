#include "RQ_Engine.h"

using namespace RQEngine;

int main()
{
    InputManager IM;
    ResourceManager* res = new ResourceManager();

    // Create the main window
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Mercy");
	Window window("Mercy", 1280, 720, 120);

    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);
	int count = 0;

	// Load resources
	if (res->loadTexture("assets/textures/wall128x128.png", "wall", false)) {
		printf("Loaded texture\n");
	}
	if (res->createSprite("s", "wall", 0, 0, 128, 128)) {
		printf("Created sprite\n");
	}

	sf::Sprite* sprite = ResourceManager::getSprite("s");

	
	// Game loop
    while (window.isOpen())
    {
		window.update();

        if(IM.isKeyUp(KeyCode::MouseLeft)){
            std::cout << "MB1 Released" << std::endl;

        }else if(IM.isKeyPressed(KeyCode::MouseLeft)){

            if(IM.isKeyHeld(KeyCode::MouseLeft)){
                std::cout << "MB1 Held" << std::endl;
            }else{
                std::cout << "MB1 Pressed" << std::endl;
            }
        }

		window.prepareFrame();
		window.draw(*sprite);
        window.drawFrame();
    }

	res->~ResourceManager();
    return EXIT_SUCCESS;
}
