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

        Texture(std::string chemin);
        ~Texture();

        void bind();
        void debind();


    
    };
}