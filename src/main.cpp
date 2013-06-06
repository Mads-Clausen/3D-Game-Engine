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
#include <iomanip>

#include "setup.hpp"

#include "math/vec3.hpp"
#include "math/mat3.hpp"
#include "math/mat4.hpp"

#include "hardware/Shader.hpp"
#include "hardware/Texture.hpp"
#include "hardware/RenderQueue.hpp"

int main()
{
    if(!setup::initOpenGL())
        return -1;

    if(!setup::openWindow("Testing", 600, 600))
        return -1;

    float ps = 0.05f;
    GLfloat vertices[] =
    {
        -ps, -ps, -0.0f,
         ps, -ps, -0.0f,
        -ps,  ps, -0.0f,

         ps, -ps, -0.0f,
         ps,  ps, -0.0f,
        -ps,  ps, -0.0f
    };

    Shader shader("shaders/test.vs", "shaders/test.fs");
    shader.compile();
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

    math::mat4f rotationMatrix = math::rotationMat4(0.0f, math::vec3f(0.0f, 0.0f, 0.0f));
    math::mat4f perspectiveMatrix = math::perspectiveMat4(  -0.1f, 0.1f,    // left, right
                                                             0.1f, 0.2f,     // near, far
                                                            -0.1f, 0.1f     // bottom, top
                                                        );
    perspectiveMatrix = perspectiveMatrix * 4;

    RenderObject ro;
        ro.bufferStart = 0;
        ro.length = 6;
        ro.mesh = &mesh;
        ro.shader = &shader;
        ro.rotationMatrix = &rotationMatrix;
        ro.projectionMatrix = &perspectiveMatrix;
        ro.addTexture(&tex);

    ro.constructVAO();

    RenderQueue queue;
    queue.push(&ro);

    float yRot = 0;
    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        queue.render();

        rotationMatrix = math::rotationMat4(yRot += 0.1f, math::vec3f(0.5f, 0.0f, 1.0f));
        ro.constructVAO();

        glfwSwapBuffers();
    } while(glfwGetKey(GLFW_KEY_ESC) != GLFW_PRESS && glfwGetWindowParam(GLFW_OPENED));

    setup::done();

    return 0;
}
