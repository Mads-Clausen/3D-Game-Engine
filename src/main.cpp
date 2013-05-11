#include <iostream>

#include "math/vec3.hpp"
#include "math/mat3.hpp"

#include "setup.hpp"

int main()
{
    if(!setup::initOpenGL())
        return -1;

    if(!setup::openWindow("Some title", 800, 600))
        return -1;

    mat3f m(
            0.0f,  1.0f, -1.0f,
            1.0f, -1.0f, -1.0f,
           -1.0f, -1.0f, -1.0f);

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, &m[0], GL_STATIC_DRAW);

    do
    {
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

        glfwSwapBuffers();
    } while(glfwGetKey(GLFW_KEY_ESC) != GLFW_PRESS && glfwGetWindowParam(GLFW_OPENED));

    setup::done();

    return 0;
}
