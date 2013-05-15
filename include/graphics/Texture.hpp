/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

/***********************************************************
 * @file Contains the definition of the Texture class.
 *
 * @author Mads Clausen
 ***********************************************************/

#ifndef TEXTURE_INCLUDED
#define TEXTURE_INCLUDED

#include <vector>
#include <iostream>

#include <GL/glew.h>
#include "GL/SOIL.h"

#include "math/vec2.hpp"

class Texture
{
    private:
        std::vector<GLfloat> _uvCoords;
        GLuint _buf, _tex;

    public:
        /****************************
         * Default constructor.
         ****************************/
        Texture() {}


        /************************************************************
         * Constructor. Initialises texture with UV coordinates.
         *
         * @param c A vector containing the UV coords.
         ************************************************************/
        Texture(std::vector<GLfloat> c);


        /**************************************************************
         * Constructor. Initialises texture with UV coordinates.
         *
         * @param c An array with the UV coords.
         * @param n The amount of UV coords.
         **************************************************************/
        Texture(GLfloat *c, unsigned int n);


        /***************************************
         * Adds a UV coord to the register.
         *
         * @param x The x coordinate.
         * @param y The y coordinate.
         ***************************************/
        void addUVCoordinate(GLfloat x, GLfloat y);

        /***************************************
         * Adds a UV coord to the register.
         *
         * @param v The coordinate-set.
         ***************************************/
        void addUVCoordinate(vec2<GLfloat> v);


        /*********************************
         * Updates the UV coord buffer.
         *********************************/
        void updateBuffer();


        /**********************************************************
         * Load the texture into memory. Image width and height
         * must be a power of 2.
         *
         * @param path The path to the image file.
         *
         * @return Success?
         **********************************************************/
        bool load(const char *path);


        /**
         * Pushes the UV coordinates.
         *
         * @param pID the uniform location.
         */
        void push(GLuint loc);
};


#endif // TEXTURE_INCLUDED
