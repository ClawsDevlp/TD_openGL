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
     void supprCube();

     void initialVboVao();
     glm::mat4 modifieCube(glm::vec3 coord);
     void afficheCube();
     void dessinCube();

};
    
}
