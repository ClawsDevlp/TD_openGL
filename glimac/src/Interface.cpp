#include "glimac/Interface.hpp"

namespace glimac {

    void Interface::initImgui(SDLWindowManager* windowManager){
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplSDL2_InitForOpenGL(windowManager->window, SDL_GL_CreateContext(windowManager->window));
        ImGui_ImplOpenGL3_Init("#version 330 core");
    }

    void Interface::fenetreImgui(SDLWindowManager* windowManager, int* axe, GestionCube* gestionator, Cursor* cursor, Scene* scene){
        // Debut def fenetre
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(windowManager->window);
        ImGui::NewFrame();
        static float colBase = 0.;
        
        ImGui::Begin("Outils de création");
        

        /* PARTIE CURSEUR */
        ImGui::Text("Curseur");
        
        ImGui::Text("Changer axe : ");
        ImGui::SameLine();
        if (ImGui::Button("X"))
            *axe = 0;
        ImGui::SameLine();
        if (ImGui::Button("Y"))
            *axe = 1;
        ImGui::SameLine();
        if (ImGui::Button("Z"))
            *axe = 2;


        /* PARTIE CUBE */
        ImGui::Text("Cube");

        if (ImGui::Button("Ajout"))
            gestionator->ajoutCube(cursor->coord, glm::vec3(0,0,0));
        ImGui::SameLine();
        if (ImGui::Button("Supression"))
            gestionator->supprCube(cursor->coord);
        ImGui::ColorEdit4("Couleur", &colBase); //montre la couleur de base du cube et la modifie

            /*float colBase = 0, 0, 1 };
            colBase = glm::value_ptr(gestionator.trouvCouleur(cursor.coord));

            glm::vec3 vec(1, 2, 3);
            float* data = glm::value_ptr(vec)
            
            float data[] = { 1, 2, 3 };
            glm::vec3 vec = glm::make_vec3(data);*/

        /* PARTIE COLONNE */
        ImGui::Text("Colonne");

        ImGui::Text("Extrud");
        ImGui::SameLine();
        if (ImGui::Button("Xe"))
            gestionator->extruDigCube(0, true, cursor->coord);
        ImGui::SameLine();
        if (ImGui::Button("Ye"))
            gestionator->extruDigCube(1, true, cursor->coord);
        ImGui::SameLine();
        if (ImGui::Button("Ze"))
            gestionator->extruDigCube(2, true, cursor->coord);

        ImGui::Text("Creuser");
        ImGui::SameLine();
        if (ImGui::Button("Xd"))
            gestionator->extruDigCube(0, false, cursor->coord);
        ImGui::SameLine();
        if (ImGui::Button("Yd"))
            gestionator->extruDigCube(1, false, cursor->coord);
        ImGui::SameLine();
        if (ImGui::Button("Zd"))
            gestionator->extruDigCube(2, false, cursor->coord);


        /* PARTIE TERRAIN */
        ImGui::Text("Terrain");

        if (ImGui::Button("Plat"))
            scene->sceneInit(gestionator);


        // Fin def fenetre
        ImGui::End();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

}