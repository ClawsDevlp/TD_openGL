#include "glimac/Texture.hpp"

namespace glimac {

    Texture::Texture(std::string chemin){
        imgTexture = loadImage(chemin);
 
        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D, tex);
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgTexture->getWidth(), imgTexture->getHeight(), 0, GL_RGBA, GL_FLOAT, imgTexture->getPixels());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    Texture::~Texture(){
        glDeleteTextures(1, &tex);
    }

    void Texture::bind(){
        glBindTexture(GL_TEXTURE_2D, tex);
    }

    void Texture::debind(){
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}