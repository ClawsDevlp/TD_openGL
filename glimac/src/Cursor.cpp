#include "glimac/Cursor.hpp"

namespace glimac {

    Cursor::Cursor()
        : coord(0.)
        {
            cursorCube.ajoutCube(coord, glm::vec3(0,0,0));
        }

    
    glm::vec3 Cursor::getCoord(){
        return coord;
    }

    void Cursor::setCoord(glm::vec3 nCoord){
        coord = nCoord;
    } 

    void Cursor::changeCoord(const int axe, const int increment){
        cursorCube.supprCube(coord);

        if (axe == 0) {
            coord += glm::vec3(increment, 0, 0);
        } else if (axe == 1) {
            coord += glm::vec3(0, increment, 0);
        } else if (axe == 2) {
            coord += glm::vec3(0, 0, increment);
        }

        cursorCube.ajoutCube(coord, glm::vec3(0,0,0));
    }

    void Cursor::dessinCursor(){
        cursorCube.dessinCubeWireframe();
    }
}