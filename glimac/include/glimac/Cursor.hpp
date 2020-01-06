#pragma once

#include "common.hpp"
#include "GestionCube.hpp"

namespace glimac {

     class Cursor {
          
          private:
          GestionCube cursorCube;
          glm::vec3 coord;
          
          public:
          Cursor();
          ~Cursor() = default;

          // Setters et Getters
          glm::vec3 getCoord();
          void setCoord(glm::vec3 nCoord);

          // Change les coordonnées du curseur (déplacement)
          void changeCoord(const int axe, const int increment);
          // Dessine cursorCube en wireframe
          void dessinCursor();

          friend class Interface;
     };
    
}
