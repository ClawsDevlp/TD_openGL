#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>

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

    // Charge les shaders et les compile
    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/color2D.vs.glsl", applicationPath.dirPath() + "shaders/color2D.fs.glsl");
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
     // On a un tableau GLfloat contenant ses coordonnées
     GLfloat vertices[] = { -0.5f, -0.5f, 1.f, 0.f, 0.f, // Premier sommet : coordonnées + couleur
        0.5f, -0.5f, 0.f, 1.f, 0.f, // Deuxième sommet : coordonnées + couleur
        0.0f, 0.5f, 0.f, 0.f, 1.f }; // Troisième sommet : coordonnées + couleur

     // On envoie les données du triangle dans le VBO
     // GL_STATIC_DRAW signifie que ses données ne changeront jamais
     // La taille correspond au sizeof(float) * le nombre de flottants
     glBufferData(GL_ARRAY_BUFFER, 15*sizeof(GLfloat), vertices, GL_STATIC_DRAW);

     // Débinding du VBO pour ne pas le modifier par erreur
     glBindBuffer(GL_ARRAY_BUFFER, 0);

     // Maintenant on spécifie à OpenGL comment interpréter nos données
     // Nos données = un triangle blanc en 2D (2 coordonnées flottants)
     // C'est la spécification de sommet, grace au VAO = Vertex Array Object
     GLuint vao;
     glGenVertexArrays(1, &vao);

     // Binding du VAO (tout se bind)
     // Pas de cible (contrairement au buffer) car une seule cible dispo pour VAO
     glBindVertexArray(vao);

     // Activation des attributs de vertex (id position = 0)
     // Cette fonction modifie le VAO actuellement bindé (NE PAS SE TROMPER DE VAO)
     // = "attribut [index] activé"
     // On appelle deux fois la fonctions : pour la position et pour la couleur
     const GLuint VERTEX_ATTR_POSITION = 0;
     const GLuint VERTEX_ATTR_COLOR = 1;
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
     // (const GLvoid*)(0*sizeof(GLfloat)) = décalage en octets de la premiere instance de l'attribut dans le tableau (casté en GLvoid*)
     glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), 0);
     glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (const GLvoid*)(2*sizeof(GLfloat)));
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
         glDrawArrays(GL_TRIANGLES, 0, 3);
         glBindVertexArray(0);


        // Update the display
        windowManager.swapBuffers();
    }

    // Libération des ressources
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return EXIT_SUCCESS;
}
