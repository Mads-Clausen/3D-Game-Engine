/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

/****************************************************************************
 * @file Contains definition of the RenderQueue and RenderObject classes.
 * @author Mads Clausen
 ****************************************************************************/

#ifndef RENDERQUEUE_INCLUDED
#define RENDERQUEUE_INCLUDED

#include <iostream>
#include <vector>

#include <GL/glew.h>

#include "hardware/Shader.hpp"
#include "hardware/Texture.hpp"
#include "hardware/Mesh.hpp"

enum RenderInfoType
{
    TYPE_VERTEXBUF,
    TYPE_ATTRIBPOINTER,
    TYPE_SHADERS,
    TYPE_TEXSAMPLER_UNIFORM
};

struct RenderInfo
{
    RenderInfoType  type;
    Shader         *shader;
    GLuint          location, size, stride, *id;
    GLboolean       normalized;
    int             datatype;
    GLfloat        *data;
    char           *uniformName;
};

struct RenderObject
{
    bool hasTexture;
    GLuint __vao, bufferStart, length;
    Mesh *mesh;
    Shader *shader;
    Texture *tex;

    RenderObject();

    void constructVAO();
};

class RenderQueue
{
    private:
        std::vector<RenderObject*> _q;

    public:
        RenderQueue() {};
        virtual ~RenderQueue() {};

        /******************************************************
         * Renders all objects in the queue, and clears it.
         *
         * @return The amount of objects rendered.
         ******************************************************/
        unsigned int render();


        /**********************************************************
         * Pushes a renderable object onto the end of the queue.
         *
         * @param ro A pointer to the object.
         **********************************************************/
        void push(RenderObject *ro)
        {
            _q.push_back(ro);
        }
};

#endif // RENDERQUEUE_INCLUDED
