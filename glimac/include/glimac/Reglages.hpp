#pragma once

#include "common.hpp"
#include <glimac/Program.hpp>
#include <glimac/TrackballCamera.hpp>
#include "glm.hpp"

namespace glimac {

class Reglage {

public:
     // Location matrices
     GLint uMVPMatrix;
     GLint uMVMatrix;
     GLint uNormalMatrix;

     // Matrices
     glm::mat4 MVMatrix;
     glm::mat4 NormalMatrix;
     glm::mat4 ProjMatrix;
     
     // Location valeurs lumière
     GLint uKd;
     GLint uKs;
     GLint uShininess;
     GLint uLightPos_vs;
     GLint uLightIntensity;
     GLint uLightDir_vs;

     // Méthode
     void initMatrice(Program *program);
     void renvoiMatrice(TrackballCamera camera, glm::mat4 CubeModelMatrix);
     

};
    
}
