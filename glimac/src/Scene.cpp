#include "glimac/Scene.hpp"

namespace glimac {

    void Scene::initMatrice(Program *program) {
        uMVPMatrix = glGetUniformLocation(program->getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(program->getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(program->getGLId(), "uNormalMatrix");

        uKd = glGetUniformLocation(program->getGLId(), "uKd");
        uKs = glGetUniformLocation(program->getGLId(), "uKs");
        uShininess = glGetUniformLocation(program->getGLId(), "uShininess");
        // GLint uLightDir_vs = glGetUniformLocation(program.getGLId(), "uLightDir_vs");
        uLightPos_vs = glGetUniformLocation(program->getGLId(), "uLightPos_vs");
        uLightIntensity = glGetUniformLocation(program->getGLId(), "uLightIntensity");

        //Active le test de profondeur GPU
        glEnable(GL_DEPTH_TEST);

        // Calculer la matrice ProjMatrix
        ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);
    }

    void Scene::renvoiMatrice(TrackballCamera camera){
         const glm::mat4 ViewMatrix = camera.getViewMatrix();

         // Cube
         glm::mat4 CubeModelMatrix;
         glm::mat4 rotationMatrix;
         glm::vec3 AxeRotation;

         // Rotater la lumière
         //AxeRotation = glm::vec3(rotationMatrix * glm::vec4(1.f, 1.f, 1.f, 1.f));

         // Renvoi des valeurs des variables uniformes de lumieres
         glUniform3fv(uKd, 1, glm::value_ptr(glm::vec3(3.f, 1.f, 2.f)));
         glUniform3fv(uKs, 1, glm::value_ptr(glm::vec3(3.f, 1.f, 2.f)));
         glUniform1f(uShininess,  2.f);
         //glUniform3fv(uLightDir_vs, 1, glm::value_ptr(glm::mat3(ViewMatrix)*AxeRotation));
         glUniform3fv(uLightPos_vs, 1, glm::value_ptr(glm::mat3(ViewMatrix)*AxeRotation));
         glUniform3fv(uLightIntensity, 1, glm::value_ptr(glm::vec3(3.f, 1.f, 2.f)));

         MVMatrix = ViewMatrix*CubeModelMatrix;
         NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
         glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
         glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
         glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));
    }

}