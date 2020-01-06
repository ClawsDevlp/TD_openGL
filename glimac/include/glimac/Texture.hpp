#pragma once

#include "common.hpp"
#include <vector>
#include <iostream>
#include <glimac/Image.hpp>

namespace glimac {

    class Texture {

        private:
        std::unique_ptr<Image> imgTexture;
        GLuint tex;

        public:

        Texture(const std::string chemin);
        ~Texture();

        // Bind la texture
        void bind();
        // Debind la texture
        void debind();    
    };
}