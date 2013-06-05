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
 * @author Mads Clausen
 ***********************************************************/

#ifndef TEXTURE_INCLUDED
#define TEXTURE_INCLUDED

#include <vector>
#include <iostream>

#include <GL/glew.h>
#include "GL/SOIL.h"

#include "hardware/Shader.hpp"
#include "math/vec2.hpp"

class Texture
{
    private:
        GLuint _uniformLoc, _vaLoc;
        std::vector<GLfloat> _uvCoords;
        GLuint _buf, _tex, __last_loc;

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
        void addUVCoordinate(math::vec2<GLfloat> v);


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


        /***********************************************
         * Pushes the UV coordinates and the sampler.
         ***********************************************/
        void push();


        /*******************************************************************
         * Makes sure that the texture is not used in any other shaders.
         *******************************************************************/
        void pop();


        /*****************************
         * Gets the texture ID.
         *
         * @return The texture ID.
         *****************************/
        GLuint &getID()
        {
            return _tex;
        }


        /************************************************************
         * Sets the uniform location
         *
         * @param shader The shader which contains the location.
         * @param name The name of the location in the shader.
         ************************************************************/
        void setUniformLocation(Shader *shader, const char *name)
        {
            _uniformLoc = glGetUniformLocation(shader->getID(), name);
        }


        /**********************************************
         * Sets the vertex attrib pointer location.
         *
         * @param loc The location.
         **********************************************/
        void setVertexAttribLocation(GLuint loc)
        {
            _vaLoc = loc;
        }


        /**********************************************
         * Gets the vertex attrib pointer location.
         *
         * @return The location.
         **********************************************/
        GLuint getVertexAttribLocation()
        {
            return _vaLoc;
        }


        /************************************
         * Gets the uniform location.
         *
         * @return The uniform location.
         ************************************/
        GLuint getUniformLocation()
        {
            return _uniformLoc;
        }
};


#endif // TEXTURE_INCLUDED
