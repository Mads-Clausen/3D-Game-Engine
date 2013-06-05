/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

#include <iostream>

#include "math/vec3.hpp"
#include "math/mat3.hpp"
#include "setup.hpp"
#include "hardware/Shader.hpp"
#include "hardware/Texture.hpp"
#include "hardware/RenderQueue.hpp"

int main()
{
    if(!setup::initOpenGL())
        return -1;

    if(!setup::openWindow("Testing", 600, 600))
        return -1;

    GLfloat vertices[] =
    {
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f
    };

    Shader shader;
    shader.compile("\
#version 330 core                                           \n\
layout(location = 0) in vec3 vertexPosition_modelspace;     \
layout(location = 1) in vec2 vertexUV;                      \
                                                            \
out vec2 UV;                                                \
                                                            \
void main()                                                 \
{                                                           \
    gl_Position.xyz = vertexPosition_modelspace;            \
    gl_Position.w = 1.0;                                    \
    UV = vertexUV;                                          \
}",
//////////////////////////////////////////////////////////////////////////////////////////
"\
#version 330 core                                           \n\
out vec3 color;                                             \
                                                            \
in vec2 UV;                                                 \
uniform sampler2D tex_sampler;                              \
void main()                                                 \
{                                                           \
    color = texture(tex_sampler, UV).rgb;                   \
}");

    Mesh mesh(vertices, 6);

    std::vector<GLfloat> UV =
    {
        0.0f, 0.0f,
        1.0f, 0.0f,
        0.0f, 1.0f,

        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f
    };

    Texture tex(UV);
    tex.load("test.jpg");
    tex.setVertexAttribLocation(1);
    tex.setUniformLocation(&shader, "tex_sampler");

    RenderObject ro;
        ro.bufferStart = 0;
        ro.length = 6;
        ro.mesh = &mesh;
        ro.shader = &shader;
        ro.addTexture(&tex);

    ro.constructVAO();

    RenderQueue queue;
    queue.push(&ro);

    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        queue.render();

        glfwSwapBuffers();
    } while(glfwGetKey(GLFW_KEY_ESC) != GLFW_PRESS && glfwGetWindowParam(GLFW_OPENED));

    setup::done();

    return 0;
}
