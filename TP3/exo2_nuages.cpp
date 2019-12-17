#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>
#include <glm/gtc/random.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>

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

    //charger les textures
    std::unique_ptr<Image> imgTerre = loadImage("/home/6im2/cdaigmor/Documents/openGl/GLImac-Template/TP3/assets/textures/EarthMap.jpg");
    std::unique_ptr<Image> imgLune = loadImage("/home/6im2/cdaigmor/Documents/openGl/GLImac-Template/TP3/assets/textures/MoonMap.jpg");
    std::unique_ptr<Image> imgNuages = loadImage("/home/6im2/cdaigmor/Documents/openGl/GLImac-Template/TP3/assets/textures/CloudMap.jpg");
    
    // Terre    
    GLuint texTerre;
    glGenTextures(1, &texTerre);
    glBindTexture(GL_TEXTURE_2D, texTerre);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgTerre->getWidth(), imgTerre->getHeight(), 0, GL_RGBA, GL_FLOAT, imgTerre->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Lune    
    GLuint texLune;
    glGenTextures(1, &texLune);
    glBindTexture(GL_TEXTURE_2D, texLune);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgLune->getWidth(), imgLune->getHeight(), 0, GL_RGBA, GL_FLOAT, imgLune->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Nuages 
    GLuint texNuages;
    glGenTextures(1, &texNuages);
    glBindTexture(GL_TEXTURE_2D, texNuages);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgNuages->getWidth(), imgNuages->getHeight(), 0, GL_RGBA, GL_FLOAT, imgNuages->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);


    //charger les shaders
    Program program = loadProgram(applicationPath.dirPath() + argv[1], applicationPath.dirPath() + argv[2]);
    program.use();

    
    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

     Sphere sphere(1, 32, 16);

     GLuint vbo;
     glGenBuffers(1, &vbo);

     glBindBuffer(GL_ARRAY_BUFFER, vbo);

     glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount()*sizeof(ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);

     glBindBuffer(GL_ARRAY_BUFFER, 0);

     GLuint vao;
     glGenVertexArrays(1, &vao);

     glBindVertexArray(vao);

     const GLuint VERTEX_ATTR_POSITION = 0;
     const GLuint VERTEX_ATTR_NORMAL = 1;
     const GLuint VERTEX_ATTR_TEXCOORDS = 2;

     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
     glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
     glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);

     glBindBuffer(GL_ARRAY_BUFFER, vbo);
     
     glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)(offsetof(ShapeVertex, position)));
     glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)(offsetof(ShapeVertex, normal)));
     glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)(offsetof(ShapeVertex, texCoords)));

     glBindBuffer(GL_ARRAY_BUFFER, 0);

     glBindVertexArray(0);

     // Récuperer les variables uniforms
     GLint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
     GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
     GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

     GLint uTexture = glGetUniformLocation(program.getGLId(), "uTexture");
     GLint uTexture2 = glGetUniformLocation(program.getGLId(), "uTexture2");

    if (uTexture2 < 0)
    {
        std::cout << texNuages << "Error while getting location for uTexture2" << std::endl;
        return 1;
    }

     //Active le test de profondeur GPU
     glEnable(GL_DEPTH_TEST);

     // Calculer la matrice ProjMatrix
     // 1er param : angle vertical de vure
     // 2eme : ratio largeur fenetre par hauteur
     // 3e : near       4e : far       définissent une range de vision sur l'axe de profondeur
     glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);
     glm::mat4 MVMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -5.f));
     glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));


     // Random de 32 axes de rotation
     std::vector<glm::vec3> axisLune;

     for(int i=0; i<32; i++){
         axisLune.push_back(glm::vec3(glm::sphericalRand(3.))); //float
     }


    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         // Matrice clean
         glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);
         glm::mat4 MVMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -5.f));
         glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

         // Planete
         MVMatrix = glm::rotate(MVMatrix, windowManager.getTime(), glm::vec3(0, 1, 0)); // Rotation
         glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
         glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
         glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

         glActiveTexture(GL_TEXTURE0);
         glBindTexture(GL_TEXTURE_2D, texTerre);
         glActiveTexture(GL_TEXTURE1);
         glBindTexture(GL_TEXTURE_2D, texNuages);
         glUniform1i(uTexture, 0);
         glUniform1i(uTexture2, 1);

         glBindVertexArray(vao);
         glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
         glBindVertexArray(0);

         glActiveTexture(GL_TEXTURE0);
         glBindTexture(GL_TEXTURE_2D, 0);
         glActiveTexture(GL_TEXTURE1);
         glBindTexture(GL_TEXTURE_2D, 0);

         // Lunes
         for(int i=0; i<32; i++){
            glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);
            glm::mat4 MVMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -5.f));
            glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

            // On place la rotation en premier afin de tourner autour du centre du monde
            MVMatrix = glm::rotate(MVMatrix, windowManager.getTime(), glm::vec3(0, 2, 0)); // Rotation
            MVMatrix = glm::translate(MVMatrix, axisLune[i]); // Rotation * Translation
            MVMatrix = glm::scale(MVMatrix, glm::vec3(0.2, 0.2, 0.2)); // Rotation * Translation * Scale

            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));
            
            glBindTexture(GL_TEXTURE_2D, texLune);
            glUniform1i(uTexture, 0);

            glBindVertexArray(vao);
            glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
            glBindVertexArray(0);

            glBindTexture(GL_TEXTURE_2D, 0);
         }

         // Update the display
         windowManager.swapBuffers();
    }

    // Libération des ressources
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
    glDeleteTextures(1, &texTerre);

    return EXIT_SUCCESS;
}
