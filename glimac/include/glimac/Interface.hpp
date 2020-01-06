#pragma once

#include "common.hpp"
#include <vector>
#include <iostream>
#include "glimac/SDLWindowManager.hpp"
#include <glimac/scene.hpp>
#include <glimac/GestionCube.hpp>
#include <glimac/Cursor.hpp>
#include <glimac/Lumiere.hpp>

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl.h>

namespace glimac {

    class Interface {

        public:

        Interface() = default;
        ~Interface() = default;

        // Initialise Imgui
        void initImgui(const SDLWindowManager* windowManager);
        // Initialise la fenêtre Imgui
        void creationFenetre(const SDLWindowManager* windowManager);
        // Contient les fonctionnalités de la fenêtre
        void fenetreImgui(int* axe, GestionCube* cube, const Cursor* cursor, Scene* scene, Lumiere* lum);
        // Arrêt de la fenêtre Imgui
        void arretFenetre();
        // Libération des ressources Imgui (non fonctionnel)
        void stopImgui();
    };
}