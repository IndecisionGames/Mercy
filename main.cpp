#include "RQ_Engine.h"

using namespace RQEngine;

int main()
{
    InputManager IM;
    ResourceManager RM;

    // Create the main window
	Window window("Mercy", 1280, 720, 120);

    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);
	int count = 0;
	bool held = false;

	// Load resources
	if (RM.loadTexture("assets/textures/wall128x128.png", "wall", false)) {
		printf("Loaded texture\n");
	}

	std::vector <sf::Sprite> walls;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++) {
			sf::Sprite sprite = ResourceManager::createSprite("wall", 0, 0, 128, 128); //createSprite will be moved to a different class
			sprite.setPosition(128 * i, 128 * j);
			walls.push_back(sprite);
		}
	}
	
	// Game loop
    while (window.isOpen())
    {
		window.update();

        if(IM.isKeyUp(KeyCode::MouseLeft)){
            std::cout << "MB1 Released" << std::endl;
			held = false;

        } else if (IM.isKeyPressed(KeyCode::MouseLeft)){

            if(IM.isKeyHeld(KeyCode::MouseLeft)){
				if (!held) {
					std::cout << "MB1 Held" << std::endl;
					held = true;
				}
            } else {
                std::cout << "MB1 Pressed" << std::endl;

            }
        }
		window.prepareFrame();
		for (sf::Sprite s : walls) {
			window.draw(s);
		}
        window.drawFrame();
    }

	ResourceManager::cleanUp();
    return EXIT_SUCCESS;
}
