#pragma once

#include "common.hpp"
#include "GestionCube.hpp"

namespace glimac {

class Cursor {

public:
     GestionCube cursorCube;
     glm::vec3 coord;
     
     Cursor();
     ~Cursor() = default;
     void changeCoord(int axe, int increment);
     void dessinCursor();
};
    
}
