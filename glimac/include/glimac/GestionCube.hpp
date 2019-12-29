#pragma once

#include "common.hpp"
#include <vector>
#include <iostream>
#include "glimac/common.hpp"

namespace glimac {

class GestionCube {

public:
     GestionCube();
     ~GestionCube() = default;
     
     std::vector<glm::vec3> cubesPositions;
     std::vector<glm::vec3> cubesCouleurs;

     GLuint positionVbo;
     GLuint vao;
     GLuint sommetVbo;
     GLuint positionSommetVbo;
     GLuint normaleVbo;
     GLuint couleurVbo;

     void initialisationCube();
     void ajoutCube(glm::vec3 position, glm::vec3 color);
     void miseAJourGPU();
     void afficheCube();
     void dessinCube();
     void dessinCubeWireframe();
     int trouveCube(glm::vec3 position);
     void supprDonneesCube();
     void supprCube(glm::vec3 position);
     int extruDigCube(int axe, bool ExtrOrDig, glm::vec3 position);
     int digCube(int axe, glm::vec3 position);
     glm::vec3 incrementAxe(int axe);

     void modifCouleur(glm::vec3 position, glm::vec3 couleur);
};
    
}
