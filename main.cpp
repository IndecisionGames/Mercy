#include "RQ_Engine.h"
int main(){

    RQEngine::Window window("Mercy", 1280, 720, 120);
    RQEngine::InputManager IM;

    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);
    int count = 0;

    // Start the game loop
    while (window.isOpen()){

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
        window.drawFrame();
    }

    return EXIT_SUCCESS;

}
