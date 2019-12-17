#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/common.hpp>
#include <glm/gtc/random.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Vertex3Dcolor.hpp>

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

     Vertex3DColor vertices[] = {
        // face devant
        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
        Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0, 0, 1)),
        Vertex3DColor(glm::vec3(0.5, -0.5, 0.0), glm::vec3(0, 1, 0)),
        Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0, 0, 1)),

        //face coté gauche
        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(1, 0, 0)),
        Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),
        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
        Vertex3DColor(glm::vec3(-0.5, 0.5, -1.0), glm::vec3(1, 0, 0)),
        Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),

        //face coté droite
        Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
        Vertex3DColor(glm::vec3(0.5, -0.5, 0.0), glm::vec3(1, 0, 0)),
        Vertex3DColor(glm::vec3(0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),
        Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
        Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(1, 0, 0)),
        Vertex3DColor(glm::vec3(0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),

        //face dessous
        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0, 1, 0)),
        Vertex3DColor(glm::vec3(0.5, -0.5, 0.0), glm::vec3(1, 0, 0)),
        Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),
        Vertex3DColor(glm::vec3(0.5, -0.5, 0.0), glm::vec3(0, 1, 0)),
        Vertex3DColor(glm::vec3(0.5, -0.5, -1.0), glm::vec3(1, 0, 0)),
        Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),

        //face dessus
        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
        Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
        Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 0, 1)),
        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
        Vertex3DColor(glm::vec3(-0.5, 0.5, -1.0), glm::vec3(1, 0, 0)),
        Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 0, 1)),

        //face derrière
        Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 1, 0)),
        Vertex3DColor(glm::vec3(-0.5, 0.5, -1.0), glm::vec3(1, 0, 0)),
        Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 0, 1)),
        Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 1, 0)),
        Vertex3DColor(glm::vec3(0.5, -0.5, -1.0), glm::vec3(1, 0, 0)),
        Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 0, 1))
     };

     int verticesSize = 36;

     GLuint vbo;
     glGenBuffers(1, &vbo);

     glBindBuffer(GL_ARRAY_BUFFER, vbo);

     glBufferData(GL_ARRAY_BUFFER, verticesSize*sizeof(Vertex3DColor), vertices, GL_STATIC_DRAW);

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
     
     glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)(offsetof(Vertex3DColor, position)));
     glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)(offsetof(Vertex3DColor, color)));
    // glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)(offsetof(ShapeVertex, texCoords)));

     glBindBuffer(GL_ARRAY_BUFFER, 0);

     glBindVertexArray(0);

     // Récuperer les variables uniforms
     GLint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
     GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
     GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

     GLint uKd = glGetUniformLocation(program.getGLId(), "uKd");
     GLint uKs = glGetUniformLocation(program.getGLId(), "uKs");
     GLint uShininess = glGetUniformLocation(program.getGLId(), "uShininess");
    // GLint uLightDir_vs = glGetUniformLocation(program.getGLId(), "uLightDir_vs");
     GLint uLightPos_vs = glGetUniformLocation(program.getGLId(), "uLightPos_vs");
     GLint uLightIntensity = glGetUniformLocation(program.getGLId(), "uLightIntensity");

     //Active le test de profondeur GPU
     glEnable(GL_DEPTH_TEST);

     // Calculer la matrice ProjMatrix
     // 1er param : angle vertical de vure
     // 2eme : ratio largeur fenetre par hauteur
     // 3e : near       4e : far       définissent une range de vision sur l'axe de profondeur
     const glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);
     glm::mat4 MVMatrix;
     glm::mat4 NormalMatrix;


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
                    camera.moveFront(e.motion.xrel);
                    break;
            }
         }

         const glm::mat4 ViewMatrix = camera.getViewMatrix();

         /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         // Cube
         glm::mat4 CubeModelMatrix;
         glm::mat4 rotationMatrix;
         glm::vec3 AxeRotation;

         // Rotater la lumière
         rotationMatrix = glm::rotate(rotationMatrix, windowManager.getTime(), glm::vec3(0, 2, 0)); // Rotatio
         AxeRotation = glm::vec3(rotationMatrix * glm::vec4(1.f, 1.f, 1.f, 1.f));

         // Renvoi des valeurs des variables uniformes de lumieres
         glUniform3fv(uKd, 1, glm::value_ptr(glm::vec3(3.f, 1.f, 2.f)));
         glUniform3fv(uKs, 1, glm::value_ptr(glm::vec3(3.f, 1.f, 2.f)));
         glUniform1f(uShininess,  2.f);
         //glUniform3fv(uLightDir_vs, 1, glm::value_ptr(glm::mat3(ViewMatrix)*AxeRotation));
         glUniform3fv(uLightPos_vs, 1, glm::value_ptr(glm::mat3(ViewMatrix)*AxeRotation));
         glUniform3fv(uLightIntensity, 1, glm::value_ptr(glm::vec3(3.f, 1.f, 2.f)));

         MVMatrix = ViewMatrix * CubeModelMatrix;
         NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
         glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
         glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
         glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

         glBindVertexArray(vao);
         glDrawArrays(GL_TRIANGLES, 0, verticesSize);
         glBindVertexArray(0);

         // Update the display
         windowManager.swapBuffers();
    }

     // Libération des ressources
     glDeleteBuffers(1, &vbo);
     glDeleteVertexArrays(1, &vao);

     return EXIT_SUCCESS;
}
