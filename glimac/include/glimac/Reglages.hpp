#pragma once

#include "common.hpp"
#include <glimac/Program.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Lumiere.hpp>
#include "glm.hpp"

namespace glimac {

     class Reglage {

          public:
          // Location matrices
          GLint uMVPMatrix;
          GLint uMVMatrix;

          // Matrices
          glm::mat4 MVMatrix;
          glm::mat4 ProjMatrix;
          
          // Location valeurs lumière
          GLint uNbPoint;
          GLint uJourNuit;
          GLint uPointPos;

          // Méthode
          void initMatrice(Program *program);
          void renvoiMatrice(TrackballCamera camera, Lumiere lum);
     };
    
}
