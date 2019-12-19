#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/common.hpp>
#include <glm/gtc/random.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>
#include <glimac/GestionCube.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Cursor.hpp>
#include <glimac/Reglages.hpp>

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

     GestionCube gestionator;
     TrackballCamera camera;
     Scene scene;
     Cursor cursor;

     scene.initMatrice(&program);

     // Application loop:
     int axe = 0;
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
                case SDL_KEYDOWN:
                    // AXE : x=0 y=1 z=2
                    if (e.key.keysym.scancode == SDL_SCANCODE_X) {
                        axe = 0;
                    } else if (e.key.keysym.scancode == SDL_SCANCODE_Y) {
                        axe = 1;
                    } else if (e.key.keysym.scancode == SDL_SCANCODE_W) { // Code W car qwerty
                        axe = 2; 
                    }

                    if (e.key.keysym.scancode == SDL_SCANCODE_UP) {
                        cursor.changeCoord(axe, 1);
                    } else if (e.key.keysym.scancode == SDL_SCANCODE_DOWN){
                        cursor.changeCoord(axe, -1);
                    }

                    if (e.key.keysym.scancode == SDL_SCANCODE_SPACE) {
                        gestionator.ajoutCube(cursor.coord);
                    }
            }
         }

         // HERE SHOULD COME THE RENDERING CODE
         glClearColor(1., 0., 0., 1.);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         
         //scene.renvoiMatrice(camera, cursor.modifieCube(cursor.coord));
         scene.renvoiMatrice(camera, glm::mat4());
         
         cursor.dessinCursor();
         gestionator.dessinCube();
        
         // Update the display
         windowManager.swapBuffers();
    }
          
     // Libération des ressources
     gestionator.supprDonneesCube();

     return EXIT_SUCCESS;
}
