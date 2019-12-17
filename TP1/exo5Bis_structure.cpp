#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <cstddef>
#include <vector>

using namespace glimac;

// Structure pour les coordonnées couleurs / positions
struct Vertex2DColor
{
        glm::vec2 position;
        glm::vec3 color;
        // Constructeur
        Vertex2DColor() = default;
        Vertex2DColor(glm::vec2 position, glm::vec3 color);
};

Vertex2DColor::Vertex2DColor(glm::vec2 position, glm::vec3 color){
    this->position = position;
    this->color = color;
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

    // Charge les shaders et les compile
    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/triangle.vs.glsl", applicationPath.dirPath() + "shaders/triangle.fs.glsl");
    program.use();


    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

     // Création d'un VBO = Vertex Buffer Object
     // VBO contient les données des sommets des triangles
     GLuint vbo;
     glGenBuffers(1, &vbo);

    // Binding (branchement) du VBO sur la cible GL_ARRAY_BUFFER
    // Cela permet de pouvoir modifier le vbo en passant par GL_ARRAY_BUFFER
     glBindBuffer(GL_ARRAY_BUFFER, vbo);

     // Création du triangle
     // On a un tableau GLfloat contenant ses coordonnées Vertex2DColor
    std::vector<Vertex2DColor> vertices;

    vertices.push_back(Vertex2DColor(glm::vec2(0, 0), glm::vec3(1, 1, 1)));

    for (float i = 0; i <= (2*glm::pi<float>()); i+=.05)
    {
        vertices.push_back(Vertex2DColor(glm::vec2(1*glm::cos(i), 1*glm::sin(i)), glm::vec3(0, 1, 1)));
    }

    
    int verticesSize = vertices.size();
    
     // On envoie les données du triangle dans le VBO
     // GL_STATIC_DRAW signifie que ses données ne changeront jamais
     // La taille correspond au sizeof(float) * le nombre de flottants
     glBufferData(GL_ARRAY_BUFFER, verticesSize*sizeof(Vertex2DColor), vertices.data(), GL_STATIC_DRAW);

     // Débinding du VBO pour ne pas le modifier par erreur
     glBindBuffer(GL_ARRAY_BUFFER, 0);

     // Création du IBO
     GLuint ibo;
     glGenBuffers(1, &ibo);

     // On bind sur GL_ELEMENT_ARRAY_BUFFER, cible reservée pour les IBOs
     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

     // Tableau d'indices: ce sont les indices des sommets à dessiner
     // On en a 6 pour former deux triangles
     // Les indices correspondent au sommet correspondant dans le VBO
     std::vector<uint32_t> indices;

     for(int j=0; j < verticesSize - 2; j++){
        indices.push_back(0);
        indices.push_back(j+1);
        indices.push_back(j+2);
     }

    indices.push_back(0);
    indices.push_back(verticesSize - 1);
    indices.push_back(1);

     glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);

     // On debind pour passer a autre chose
     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

     // Maintenant on spécifie à OpenGL comment interpréter nos données
     // Nos données = un triangle blanc en 2D (2 coordonnées flottants)
     // C'est la spécification de sommet, grace au VAO = Vertex Array Object
     GLuint vao;
     glGenVertexArrays(1, &vao);

     // Binding du VAO (tout se bind)
     // Pas de cible (contrairement au buffer) car une seule cible dispo pour VAO
     glBindVertexArray(vao);

     // On bind l'IBO sur GL_ELEMENT_ARRAY_BUFFER, puisqu'un VAO est actuellement bindé
     // cela a pour effet d'enregistrer l'IBO dans le VAO
     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

     // Activation des attributs de vertex (id position = 0)
     // Cette fonction modifie le VAO actuellement bindé (NE PAS SE TROMPER DE VAO)
     // = "attribut [index] activé"
     // On appelle deux fois la fonctions : pour la position et pour la couleur
     const GLuint VERTEX_ATTR_POSITION = 3;
     const GLuint VERTEX_ATTR_COLOR = 8;
     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
     glEnableVertexAttribArray(VERTEX_ATTR_COLOR);

     // Spécification des attributs de vertex
     // On indique à OpenGL où sont les sommets et comment les lire
     // VBO contient les données et VAO les décrit
     // Il faut re-binder le VBO
     glBindBuffer(GL_ARRAY_BUFFER, vbo);
     // La fonction va directement lire l'id du VBO bindé sur la cible, et de le stocker dans le VAO
     // 2 = 2 coordonnées pour chaque sommet, 3 = 3 coordonnées pour les couleurs
     // 5*sizeof(GLfloat) = 5 octets pour le prochain sommet
     // offsetof(Vertex2DColor, position) = décalage en octets de la premiere instance de l'attribut dans le tableau (casté en GLvoid*))
     glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor), (const GLvoid*)offsetof(Vertex2DColor, position));
     glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor), (const GLvoid*)offsetof(Vertex2DColor, color));
     // Et on débind le VBO
     glBindBuffer(GL_ARRAY_BUFFER, 0);

     // Débinding du VAO pour ne pas le modifier par erreur
     glBindVertexArray(0);



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

         // Nettoyage de la fenetre pour ne pas avoir de résidu du tour de boucle précédent
         glClear(GL_COLOR_BUFFER_BIT);

         // Dessin en utilisant le VAO
         // Binding du VAO pour pouvoir le réutiliser
         glBindVertexArray(vao);
         glDrawElements(GL_TRIANGLES, verticesSize*3, GL_UNSIGNED_INT, 0);
         glBindVertexArray(0);


        // Update the display
        windowManager.swapBuffers();
    }

    // Libération des ressources
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return EXIT_SUCCESS;
}
