#pragma once

#include "common.hpp"
#include <vector>
#include <iostream>

namespace glimac {

    class Lumiere {

    public:

    Lumiere();
    ~Lumiere() = default;

    bool directional; // mode jour / nuit

    void modeJourNuit();
    // Initialisation vbos et vao des lum
    void initLum();  
    void ajoutPointLum(glm::vec3 position);
    void supprPointLum(glm::vec3 position);
    
    };
}