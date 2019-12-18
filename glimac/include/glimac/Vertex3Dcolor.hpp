#pragma once

#include <vector>

#include "common.hpp"

namespace glimac {   
    // Structure pour les coordonnées couleurs / positions
    struct Vertex3DColor
    {
            glm::vec3 position;
            glm::vec3 color;
            // Constructeur
            Vertex3DColor() = default;
            Vertex3DColor(glm::vec3 position, glm::vec3 color);
    };

    Vertex3DColor::Vertex3DColor(glm::vec3 position, glm::vec3 color){
        this->position = position;
        this->color = color;
    };
}