#pragma once

#include "common.hpp"
#include <vector>
#include <iostream>
#include "glimac/SDLWindowManager.hpp"
#include <glimac/scene.hpp>
#include <glimac/GestionCube.hpp>
#include <glimac/Cursor.hpp>

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl.h>

namespace glimac {

    class Interface {

    public:

    Interface() = default;
    ~Interface() = default;

    void initImgui(SDLWindowManager* windowManager);
    void fenetreImgui(SDLWindowManager* windowManager, int* axe, GestionCube* cube, Cursor* cursor, Scene* scene);
            
    };
}