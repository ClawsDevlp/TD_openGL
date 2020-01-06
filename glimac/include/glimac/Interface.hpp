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

        void initImgui(SDLWindowManager* windowManager);
        void creationFenetre(SDLWindowManager* windowManager);
        void fenetreImgui(int* axe, GestionCube* cube, Cursor* cursor, Scene* scene, Lumiere* lum);
        void arretFenetre();
        void stopImgui();
    };
}