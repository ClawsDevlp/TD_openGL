#include "glimac/Reglages.hpp"

namespace glimac {

    void Reglage::initMatrice(Program *program) {
        uMVPMatrix = glGetUniformLocation(program->getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(program->getGLId(), "uMVMatrix");

        //uKd = glGetUniformLocation(program->getGLId(), "uKd");
        //uKs = glGetUniformLocation(program->getGLId(), "uKs");
        //uShininess = glGetUniformLocation(program->getGLId(), "uShininess");
        //uLightDir_vs = glGetUniformLocation(program->getGLId(), "uLightDir_vs");
        //uLightPos_vs = glGetUniformLocation(program->getGLId(), "uLightPos_vs");
        //uLightIntensity = glGetUniformLocation(program->getGLId(), "uLightIntensity");

        uJourNuit = glGetUniformLocation(program->getGLId(), "uJourNuit");

        // Active le test de profondeur GPU
        glEnable(GL_DEPTH_TEST);

        // Calculer la matrice ProjMatrix
        ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);
    }

    void Reglage::renvoiMatrice(TrackballCamera camera, glm::mat4 CubeModelMatrix, Lumiere lum){
         const glm::mat4 ViewMatrix = camera.getViewMatrix();
         MVMatrix = ViewMatrix*CubeModelMatrix;

        float xLightD = -1.0f;
        float yLightD = -1.0f;
        float zLightD = -1.0f;
        glm::vec4 LightDir = ViewMatrix * glm::vec4(xLightD, yLightD, zLightD, 1);

         // Renvoi des valeurs des variables uniformes de lumieres
         //glUniform3fv(uKd, 1, glm::value_ptr(glm::vec3(3.f, 1.f, 2.f)));
         //glUniform3fv(uKs, 1, glm::value_ptr(glm::vec3(3.f, 1.f, 2.f)));
         //glUniform1f(uShininess,  2.f);
         glUniform1f(uJourNuit,  lum.directional);
         //glUniform3f(uLightDir_vs, LightDir.x, LightDir.y, LightDir.z);
         //glUniform3f(uLightPos_vs, LightDir.x, LightDir.y, LightDir.z);
         //glUniform3fv(uLightIntensity, 1, glm::value_ptr(glm::vec3(3.f, 1.f, 2.f)));

         glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
         glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    }

}