#include "glimac/Cube.hpp"

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

     glm::vec3 coordonnees[] = {
        // face devant
        posSommets[0],
        posSommets[1],
        posSommets[2],
        posSommets[1],
        posSommets[2],
        posSommets[3],

        //face coté gauche
        posSommets[0],
        posSommets[2],
        posSommets[4],
        posSommets[0],
        posSommets[5],
        posSommets[4],

        //face dessous
        posSommets[2],
        posSommets[3],
        posSommets[4],
        posSommets[3],
        posSommets[6],
        posSommets[4],

        //face derrière
        posSommets[4],
        posSommets[5],
        posSommets[7],
        posSommets[4],
        posSommets[6],
        posSommets[7],

        //face dessus
        posSommets[0],
        posSommets[1],
        posSommets[7],
        posSommets[0],
        posSommets[5],
        posSommets[7],

        //face coté droite
        posSommets[1],
        posSommets[3],
        posSommets[6],
        posSommets[1],
        posSommets[7],
        posSommets[6],
     };

    void Cube::initialVboVao(){
      GLuint cubeVbo;
      glGenBuffers(1, &cubeVbo);
      glBindBuffer(GL_ARRAY_BUFFER, cubeVbo);
      glBufferData(GL_ARRAY_BUFFER, nbCoordonnees*sizeof(glm::vec3), &coordonnees, GL_STATIC_DRAW);
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
      
      glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
      //glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (const GLvoid*)(offsetof(glm::vec3, color)));
      // glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)(offsetof(ShapeVertex, texCoords)));

      glBindBuffer(GL_ARRAY_BUFFER, 0);

      glBindVertexArray(0);

      c_Vbo = cubeVbo;
      c_Vao = cubeVao;
    }

    glm::mat4 Cube::modifieCube(glm::vec3 coord){
      glm::mat4 CubeModelMatrix;
      return CubeModelMatrix = glm::translate(CubeModelMatrix, coord); // Translation
    }

    void Cube::dessinCube(){
      glBindVertexArray(c_Vao);
      glDrawArrays(GL_TRIANGLES, 0, nbCoordonnees);
      glBindVertexArray(0);
    }

    void Cube::supprCube(){
      glDeleteBuffers(1, &c_Vbo);
      glDeleteVertexArrays(1, &c_Vao);
    }


}