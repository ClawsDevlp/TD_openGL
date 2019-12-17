#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <glimac/Program.hpp>


using namespace glimac;

struct Vertex2DUV
{
    glm::vec2 positionXY;
    glm::vec2 textureUV;
    // Constructeur
    Vertex2DUV() = default;
    Vertex2DUV(glm::vec2 positionXY, glm::vec2 textureUV);
};

Vertex2DUV::Vertex2DUV(glm::vec2 positionXY, glm::vec2 textureUV){
    this->positionXY = positionXY;
    this->textureUV = textureUV;
};

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
    Program program = loadProgram(applicationPath.dirPath() + argv[1], applicationPath.dirPath() + argv[2]);
    program.use();
    GLuint UNIFORM_TIME_LOCATION =glGetUniformLocation( program.getGLId(), "uTime"); 

    glUniform1f(UNIFORM_TIME_LOCATION, 45.);
    float Time=0;

    GLuint vbo;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    std::vector<Vertex2DUV> vertices;

    vertices.push_back(Vertex2DUV(glm::vec2(-1, -1), glm::vec2(0,0)));
    vertices.push_back(Vertex2DUV(glm::vec2(1, -1), glm::vec2(0,0)));
    vertices.push_back(Vertex2DUV(glm::vec2(0, 1), glm::vec2(0,0)));
    
    
    int verticesSize = vertices.size();

    glBufferData(GL_ARRAY_BUFFER, verticesSize*sizeof(Vertex2DUV), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);


    GLuint vao;
    glGenVertexArrays(1, &vao);

     // Binding du VAO (tout se bind)
     // Pas de cible (contrairement au buffer) car une seule cible dispo pour VAO
     glBindVertexArray(vao);

     const GLuint VERTEX_ATTR_POSITION = 0;
     const GLuint VERTEX_ATTR_TEXTURE = 1;
     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
     glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);

     glBindBuffer(GL_ARRAY_BUFFER, vbo);
     glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), (const GLvoid*)offsetof(Vertex2DUV, positionXY));
     glVertexAttribPointer(VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), (const GLvoid*)offsetof(Vertex2DUV, textureUV));
     // Et on débind le VBO
     glBindBuffer(GL_ARRAY_BUFFER, 0);


    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    // Application loop:
    bool done = false;
    while(!done) {

        Time+=1;


        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }
        glClear(GL_COLOR_BUFFER_BIT);

         // Dessin en utilisant le VAO
         // Binding du VAO pour pouvoir le réutiliser
         glBindVertexArray(vao);
         glDrawArrays(GL_TRIANGLES, 0, 3);
         glBindVertexArray(0);




        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);


    return EXIT_SUCCESS;
}
