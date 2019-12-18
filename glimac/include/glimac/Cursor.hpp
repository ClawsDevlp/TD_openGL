#pragma once

#include "common.hpp"
#include "Cube.hpp"

namespace glimac {

class Cursor : public Cube {

public:
     glm::vec3 coord;

     void setCoord(int axe, int increment);
     void dessinCube();
};
    
}
