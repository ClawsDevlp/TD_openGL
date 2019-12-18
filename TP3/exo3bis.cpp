#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/common.hpp>
#include <glm/gtc/random.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Cube.hpp>
#include <glimac/Scene.hpp>

using namespace glimac;

int main(int argc, char** argv) {
     // Initialize SDL and open a window
     SDLWindowManager windowManager(800, 600, "GLImac");

     // Initialize glew for OpenGL3+ support
     GLenum glewInitError = glewInit();
     if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
     }

     std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
     std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;
    
     FilePath applicationPath(argv[0]);

     //charger les shaders
     Program program = loadProgram(applicationPath.dirPath() + argv[1], applicationPath.dirPath() + argv[2]);
     program.use();

     /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

     TrackballCamera camera;
     Scene scene;

     Cube cube;
     Cube cube2;
     
     cube.initialVboVao();
     cube2.initialVboVao();

     scene.initMatrice(&program);

     // Application loop:
     bool done = false;
     while(!done) {
     
         // Event loop:
         SDL_Event e;
         while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
            switch(e.type){
                case SDL_MOUSEMOTION:
                    if (SDL_BUTTON(SDL_BUTTON_LEFT) & e.motion.state)
                    {
                        camera.rotateLeft(e.motion.xrel);
                        camera.rotateUp(e.motion.yrel);
                    }
                    break;
                case SDL_MOUSEWHEEL:
                    camera.moveFront(e.wheel.y);
                    break;
            }
         }

         // HERE SHOULD COME THE RENDERING CODE

         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         scene.renvoiMatrice(camera);
         
         cube.drawCube();
        
         // Update the display
         windowManager.swapBuffers();
    }
     
     
     // Libération des ressources
     cube.deleteCube();
     cube2.deleteCube();

     return EXIT_SUCCESS;
}
