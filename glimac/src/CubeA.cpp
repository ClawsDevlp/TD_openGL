#include "../include/glimac/CubeA.hpp"

namespace glimac {

    glm::vec3 posSommets[] = {
        // p0
        glm::vec3(-0.5, 0.5, 0.0),
        // p1
        glm::vec3(0.5, 0.5, 0.0),
        // p2
        glm::vec3(-0.5, -0.5, 0.0),
        // p3
        glm::vec3(0.5, -0.5, 0.0),
        // p4
        glm::vec3(-0.5, -0.5, -1.0),
        // p5
        glm::vec3(-0.5, 0.5, -1.0),
        // p6
        glm::vec3(0.5, -0.5, -1.0),
        // p7
        glm::vec3(0.5, 0.5, -1.0),
     };

     Vertex3DColor coordonnees[] = {
        // face devant
        Vertex3DColor(posSommets[0], glm::vec3(0, 1, 0)),
        Vertex3DColor(posSommets[1], glm::vec3(0, 1, 0)),
        Vertex3DColor(posSommets[2], glm::vec3(0, 1, 0)),
        Vertex3DColor(posSommets[1], glm::vec3(0, 1, 0)),
        Vertex3DColor(posSommets[2], glm::vec3(0, 1, 0)),
        Vertex3DColor(posSommets[3], glm::vec3(0, 1, 0)),

        //face coté gauche
        Vertex3DColor(posSommets[0], glm::vec3(1, 0, 0)),
        Vertex3DColor(posSommets[2], glm::vec3(1, 0, 0)),
        Vertex3DColor(posSommets[4], glm::vec3(1, 0, 0)),
        Vertex3DColor(posSommets[0], glm::vec3(1, 0, 0)),
        Vertex3DColor(posSommets[5], glm::vec3(1, 0, 0)),
        Vertex3DColor(posSommets[4], glm::vec3(1, 0, 0)),

        //face dessous
        Vertex3DColor(posSommets[2], glm::vec3(0, 0, 1)),
        Vertex3DColor(posSommets[3], glm::vec3(0, 0, 1)),
        Vertex3DColor(posSommets[4], glm::vec3(0, 0, 1)),
        Vertex3DColor(posSommets[3], glm::vec3(0, 0, 1)),
        Vertex3DColor(posSommets[6], glm::vec3(0, 0, 1)),
        Vertex3DColor(posSommets[4], glm::vec3(0, 0, 1)),

        //face derrière
        Vertex3DColor(posSommets[4], glm::vec3(1, 0, 0)),
        Vertex3DColor(posSommets[5], glm::vec3(1, 0, 0)),
        Vertex3DColor(posSommets[7], glm::vec3(1, 0, 0)),
        Vertex3DColor(posSommets[4], glm::vec3(1, 0, 0)),
        Vertex3DColor(posSommets[6], glm::vec3(1, 0, 0)),
        Vertex3DColor(posSommets[7], glm::vec3(1, 0, 0)),

        //face dessus
        Vertex3DColor(posSommets[0], glm::vec3(0, 1, 0)),
        Vertex3DColor(posSommets[1], glm::vec3(0, 1, 0)),
        Vertex3DColor(posSommets[7], glm::vec3(0, 1, 0)),
        Vertex3DColor(posSommets[0], glm::vec3(0, 1, 0)),
        Vertex3DColor(posSommets[5], glm::vec3(0, 1, 0)),
        Vertex3DColor(posSommets[7], glm::vec3(0, 1, 0)),

        //face coté droite
        Vertex3DColor(posSommets[1], glm::vec3(0, 0, 1)),
        Vertex3DColor(posSommets[3], glm::vec3(0, 0, 1)),
        Vertex3DColor(posSommets[6], glm::vec3(0, 0, 1)),
        Vertex3DColor(posSommets[1], glm::vec3(0, 0, 1)),
        Vertex3DColor(posSommets[7], glm::vec3(0, 0, 1)),
        Vertex3DColor(posSommets[6], glm::vec3(0, 0, 1)),
     };

   Cube::Cube() {
        initialVboVao();
      }

    void Cube::initialVboVao(){
      glGenBuffers(1, &cubeVbo);
      glBindBuffer(GL_ARRAY_BUFFER, cubeVbo);
      glBufferData(GL_ARRAY_BUFFER, nbCoordonnees*sizeof(Vertex3DColor), coordonnees, GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER, 0);

      GLuint cubeVao;
      glGenVertexArrays(1, &cubeVao);
      glBindVertexArray(cubeVao);

      const GLuint VERTEX_ATTR_POSITION = 0;
      const GLuint VERTEX_ATTR_NORMAL = 1;
      const GLuint VERTEX_ATTR_TEXCOORDS = 2;

      glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
      glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
      glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);

      glBindBuffer(GL_ARRAY_BUFFER, cubeVbo);
      
      glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)(offsetof(Vertex3DColor, position)));
      glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)(offsetof(Vertex3DColor, color)));
      // glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)(offsetof(ShapeVertex, texCoords)));

      glBindBuffer(GL_ARRAY_BUFFER, 0);

      glBindVertexArray(0);
    }


    void Cube::drawCube(){
         glBindVertexArray(cubeVao);
         glDrawArrays(GL_TRIANGLES, 0, nbCoordonnees);
         glBindVertexArray(0);
    }


     void Cube::deleteCube(){
      // Libération des ressources
      glDeleteBuffers(1, &cubeVbo);
      glDeleteVertexArrays(1, &cubeVao);
     }


}