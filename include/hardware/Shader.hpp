/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

/**
 * @file Contains definition of the Shader class.
 * @author Mads Clausen
 */

#ifndef SHADER_INCLUDED
#define SHADER_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include <GL/glew.h>

class Shader
{
    private:
        char *_vsPath, *_fsPath;
        GLuint _id;

    public:
        /************************
         * Default constructor.
         ************************/
        Shader()
        {
            _vsPath = (char*) "";
            _fsPath = (char*) "";
            _id = 0;
        }

        /****************************************************
         * Constructor.
         *
         * @param v The filepath to the vertex shader.
         * @param f The filepath to the fragment shader.
         ****************************************************/
        Shader(const char *v, const char *f)
        {
            _vsPath = (char*) v;
            _fsPath = (char*) f;
            _id = 0;
        }


        /***********************************************************
         * Compile the shader from source code located in files.
         ***********************************************************/
        void compile();


        /**********************************************************
         * Compile the shader from source code in strings.
         *
         * @param vertSourcePointer The vertex shader source.
         * @param fragSourcePointer The fragment shader source.
         **********************************************************/
        void compile(const char *vertSourcePointer, const char *fragSourcePointer);


        /************************************************
         * Returns the path to the vertex shader.
         *
         * @return The filepath to the vertex shader.
         ************************************************/
        const char *getVertexPath()
        {
            return (const char*) _vsPath;
        }


        /************************************************
         * Returns the path to the fragment shader.
         *
         * @return The filepath to the fragment shader.
         ************************************************/
        const char *getFragmentPath()
        {
            return (const char*) _fsPath;
        }


        /******************************************
         * Returns the ID of the OpenGL shader.
         *
         * @return The ID.
         ******************************************/
        const GLuint getID()
        {
            return (const GLuint) _id;
        }


        /*********************
         * Uses the shader.
         *********************/
        void bind()
        {
            if(_id != 0)
                glUseProgram(_id);
        }


        /**************************
         * "Unbinds" the shader.
         **************************/
        void unbind()
        {
            glUseProgram(0);
        }
};

#endif // SHADER_INCLUDED
