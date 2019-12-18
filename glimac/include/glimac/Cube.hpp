#pragma once

#include "common.hpp"

namespace glimac {

class Cube {

public:
     int nbCoordonnees = 36;
     GLuint c_Vbo;
     GLuint c_Vao;

     Cube() = default;
     Cube(glm::vec3 pos);
     void deleteCube();

     void initialVboVao();
     void modifyCube();
     void afficheCube();
     void drawCube();

};
    
}
