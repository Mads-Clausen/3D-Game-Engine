/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

// hau3b

#include <iostream>

#include "math/vec3.hpp"
#include "math/mat3.hpp"
#include "setup.hpp"
#include "graphics/Shader.hpp"

int main()
{
    if(!setup::initOpenGL())
        return -1;

    if(!setup::openWindow("2D Game Engine", 800, 600))
        return -1;

    mat3f m(
            0.0f,  0.5f, -1.0f,
            0.5f, -0.5f, -1.0f,
           -0.5f, -0.5f, -1.0f);

    Shader shader("", "");
    shader.compile("#version 330\nlayout(location = 0) in vec3 vertexPosition_modelspace;\nvoid main() { gl_Position.xyz = vertexPosition_modelspace;gl_Position.w = 1.0; }",
                   "#version 330 core\nout vec3 color;\nvoid main(){ color = vec3(1, 0, 0); }");

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, &m[0], GL_STATIC_DRAW);

    do
    {
        shader.bind();
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
           0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
           3,                  // size
           GL_FLOAT,           // type
           GL_FALSE,           // normalized?
           0,                  // stride
           (void*)0            // array buffer offset
        );

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glDisableVertexAttribArray(0);
        shader.unbind();

        glfwSwapBuffers();
    } while(glfwGetKey(GLFW_KEY_ESC) != GLFW_PRESS && glfwGetWindowParam(GLFW_OPENED));

    setup::done();

    return 0;
}
