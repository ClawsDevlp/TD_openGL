#pragma once

#include "common.hpp"
#include "Vertex3Dcolor.hpp"

namespace glimac {

class Cube {

public:
     int nbCoordonnees = 36;
     GLuint cubeVbo;
     GLuint cubeVao;

     Cube();

     void initialVboVao();
     void afficheCube();
     void deleteCube();
     void drawCube();

    
    
private:
};
    
}
