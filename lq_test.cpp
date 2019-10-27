#include "RQ_Engine.h"

int main()
{
    //Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    RQEngine::EventManager EM(&window);

    RQEngine::InputManager IM;

    // Start the game loop
    while (window.isOpen()){
        EM.processEvents();


        if(IM.isKeyUp(KeyCode::MouseLeft)){
            std::cout << "MB1 Released" << std::endl;

        }else if(IM.isKeyPressed(KeyCode::MouseLeft)){

            if(IM.isKeyHeld(KeyCode::MouseLeft)){
                std::cout << "MB1 Held" << std::endl;
            }else{
                std::cout << "MB1 Pressed" << std::endl;
            }
        }
        sf::sleep(sf::seconds(0.1f));
    }
    return EXIT_SUCCESS;

}
