/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/


/************************************************************************************
 * @file Contains functions for setting up and configuring the engine at runtime.
 *
 * @author Mads Clausen
 ************************************************************************************/

#ifndef SETUP_OPENGL_INCLUDED
#define SETUP_OPENGL_INCLUDED

#include <iostream>

#include <GL/glew.h>
#include <GL/glfw.h>

namespace setup
{
    /*******************************************
     * Set up OpenGL and open the window.
     *
     * @return Success?
     *******************************************/
    bool initOpenGL()
    {
        if(!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW." << std::endl;
            return false;
        }

        glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
        glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
        glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
        glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        return true;
    }

    /***************************
     * Open the GLFW window.
     *
     * @return Success?
     ***************************/
    bool openWindow(const char *title, const int w, const int h)
    {
        if(!glfwOpenWindow(w, h, 0,0,0,0, 32,0, GLFW_WINDOW))
        {
            std::cerr << "Failed to open GLFW window." << std::endl;
            glfwTerminate();
            return false;
        }

        glfwSetWindowTitle(title);

        glewExperimental = true;
        if(glewInit() != GLEW_OK)
        {
            std::cerr << "Failed to initialize GLEW." << std::endl;
            return false;
        }

        return true;
    }

    /*********************************************************
     * Makes sure that everything gets shut down correctly.
     *********************************************************/
    void done()
    {
        glfwTerminate();
    }
}

#endif // SETUP_OPENGL_INCLUDED
