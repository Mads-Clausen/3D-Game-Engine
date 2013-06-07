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

#include "math/vec2.hpp"
#include "math/vec3.hpp"
#include "math/mat3.hpp"
#include "math/mat4.hpp"

#include "hardware/Shader.hpp"
#include "hardware/Texture.hpp"
#include "hardware/RenderQueue.hpp"

int main()
{
    math::vec2f a(-0.4f, 0.01f), b(0.4f, 0.01f);
    std::cout << "Angle = " << a.angle(b) << std::endl;

    if(!setup::initOpenGL())
        return -1;

    if(!setup::openWindow("Testing", 600, 600))
        return -1;

    float ps = 1.0f;
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
    math::mat4f perspectiveMatrix = math::perspectiveMat4( -1.0f,   1.0f,    // left, right
                                                            0.01f, 1.0f,  // near, far
                                                           -1.0f,   1.0f     // bottom, top
                                                         );
    math::mat4f viewMatrix = math::lookAt(math::vec3f(-0.0f, 0.0f, -0.39f), // position
                                          math::vec3f( 0.0f, 0.0f, -0.2f)  // look direction
                                          );
    perspectiveMatrix = perspectiveMatrix * viewMatrix;

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

    float yRot = 0, x = -0.0f, oldX = -0.0f, y = 0.0f, oldY = 0.0f, z = -0.39f, oldZ = -0.39f;
    do
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        queue.render();

        rotationMatrix = math::rotationMat4(yRot += 0.1f, math::vec3f(0.0f, 0.0f, 1.0f));

        if(x != oldX || y != oldY || z != oldZ)
        {
            perspectiveMatrix = math::perspectiveMat4( -10.0f,   10.0f,    // left, right
                                                        0.01f, 10.0f,  // near, far
                                                       -10.0f,   10.0f     // bottom, top
                                                         );
            viewMatrix = math::lookAt(  math::vec3f(x, y, z),           // position
                                        math::vec3f(0.0f, 0.0f, -1.0f)  // look direction
                                        );
            perspectiveMatrix = perspectiveMatrix * viewMatrix;
            oldX = x;
            oldY = y;
            oldZ = z;
        }

        ro.constructVAO();

        if(glfwGetKey(GLFW_KEY_LEFT) == GLFW_PRESS)
            x -= 0.0005f;
        else if(glfwGetKey(GLFW_KEY_RIGHT) == GLFW_PRESS)
            x += 0.0005f;

        if(glfwGetKey(GLFW_KEY_UP) == GLFW_PRESS)
            y += 0.0001f;
        else if(glfwGetKey(GLFW_KEY_DOWN) == GLFW_PRESS)
            y -= 0.0001f;

        if(glfwGetKey(GLFW_KEY_SPACE) == GLFW_PRESS)
            z -= 0.0005f;
        else if(glfwGetKey(GLFW_KEY_ENTER) == GLFW_PRESS)
            z += 0.0005f;

        glfwSwapBuffers();
    } while(glfwGetKey(GLFW_KEY_ESC) != GLFW_PRESS && glfwGetWindowParam(GLFW_OPENED));

    setup::done();

    return 0;
}
