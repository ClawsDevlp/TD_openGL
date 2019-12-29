#pragma once

#include "common.hpp"
#include <vector>
#include <iostream>
#include "glimac/common.hpp"

namespace glimac {

class GestionCube {

public:
     std::vector<glm::vec3> cubesPositions;

     GLuint positionVbo;
     GLuint c_Vao;
     GLuint sommetVbo;
     GLuint ibPositionsSommetsID;

     GestionCube();
     ~GestionCube() = default;
     
     void ajoutCube(glm::vec3 position);

     void initialisationCube();
     void miseAJourGPU();
     void afficheCube();
     void dessinCube();
     void dessinCubeWireframe();
     int trouveCube(glm::vec3 position);
     void supprDonneesCube();
     void supprCube(glm::vec3 position);
     int extrudCube(int axe, glm::vec3 position);
     int digCube(int axe, glm::vec3 position);
     glm::vec3 incrementAxe(int axe);
};
    
}
