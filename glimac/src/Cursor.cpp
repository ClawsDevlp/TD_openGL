#include "glimac/Cursor.hpp"

namespace glimac {

    void Cursor::setCoord(int axe, int increment){
        if (axe == 0) {
            coord += glm::vec3(increment, 0, 0);
        } else if (axe == 1) {
            coord += glm::vec3(0, increment, 0);
        } else if (axe == 2) {
            coord += glm::vec3(0, 0, increment);
        }
    }

    void Cursor::dessinCube(){
      glBindVertexArray(c_Vao);
      glDrawArrays(GL_LINES, 0, nbCoordonnees);
      glBindVertexArray(0);
    }

}