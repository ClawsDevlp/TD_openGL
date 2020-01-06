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
#include <glimac/scene.hpp>
#include <glimac/Interface.hpp>
#include <fstream> 

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl.h>

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

    // Imgui
    Interface interface;
    interface.initImgui(&windowManager);

    //charger les textures
    //Texture texture(applicationPath.dirPath() + "assets/textures/MoonMap.jpg");

    // Charger les shaders
    Program program = loadProgram(applicationPath.dirPath() + argv[1], applicationPath.dirPath() + argv[2]);
    program.use();

    /*********************************
    * HERE SHOULD COME THE INITIALIZATION CODE
    *********************************/

    GestionCube gestionator;
    TrackballCamera camera;
    Lumiere lumiere;
    Reglage reglage;
    Scene scene;
    Cursor cursor;

    gestionator.ajoutCube(glm::vec3(0,0,0), glm::vec3(0,0,1));

    reglage.initMatrice(&program);

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
                    // Selection de l'axe a utiliser
                    // AXE : x=0 y=1 z=2
                    if (e.key.keysym.scancode == SDL_SCANCODE_X) {
                        axe = 0;
                    } else if (e.key.keysym.scancode == SDL_SCANCODE_Y) {
                        axe = 1;
                    } else if (e.key.keysym.scancode == SDL_SCANCODE_W) { // Code W car qwerty
                        axe = 2; 
                    }

                    // Mouvement curseur
                    if (e.key.keysym.scancode == SDL_SCANCODE_UP) {
                        cursor.changeCoord(axe, 1);
                    } else if (e.key.keysym.scancode == SDL_SCANCODE_DOWN){
                        cursor.changeCoord(axe, -1);
                    }

                    // Ajout cube
                    if (e.key.keysym.scancode == SDL_SCANCODE_SPACE) {
                        gestionator.ajoutCube(cursor.getCoord(), glm::vec3(0,1,0));
                    }

                    // Initialisation scene
                    if (e.key.keysym.scancode == SDL_SCANCODE_I) {
                        scene.sceneInit(&gestionator);
                    }

                    //Creation d'une scene d'apres fonction radiale
                    if (e.key.keysym.scancode == SDL_SCANCODE_R) {
                        scene.loadRBFscene(&gestionator);
                    } 

                    //Save the actual scene dans un fichier
                    if (e.key.keysym.scancode == SDL_SCANCODE_S) {
                        scene.saveScene(&gestionator);
                    } 
                    //Ouvre une scène précédemment sauvegardée
                    if (e.key.keysym.scancode == SDL_SCANCODE_O) {
                        scene.chargeScene(&gestionator);
                    } 

                    // Rajout cube à une colonne (extrud)
                    if (e.key.keysym.scancode == SDL_SCANCODE_E) {
                        gestionator.extruDigCube(axe, true, cursor.getCoord());
                    }

                    // Creuse colonne
                    if (e.key.keysym.scancode == SDL_SCANCODE_D) {
                        gestionator.extruDigCube(axe, false, cursor.getCoord());
                    }

                    // Changement couleur
                    if (e.key.keysym.scancode == SDL_SCANCODE_C) {
                        gestionator.modifCouleur(cursor.getCoord(), glm::vec3(1.,1.,1.));
                    }
            }
        }

        // HERE SHOULD COME THE RENDERING CODE
        glClearColor(1., 0., 0.5, 1.);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        reglage.renvoiMatrice(camera, lumiere);
        
        gestionator.dessinCube();
        cursor.dessinCursor();

        // Fenetre Imgui
        interface.creationFenetre(&windowManager);
        interface.fenetreImgui(&axe, &gestionator, &cursor, &scene, &lumiere);
        interface.arretFenetre();
        
        windowManager.swapBuffers();
    }
        
    // Libération des ressources
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    //interface.stopImgui(); -> fonctionne pas etrangement ?
    //SDL_GL_DeleteContext(gl_context);
    
    gestionator.supprDonneesCube();

    return EXIT_SUCCESS;
}
