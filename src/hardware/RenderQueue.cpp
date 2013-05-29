/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

#include "hardware/RenderQueue.hpp"

/*
void RenderObject::constructVAO()
{
    if(__vao != 0)
        glDeleteVertexArrays(1, &__vao);

    glGenVertexArrays(1, &__vao);
    glBindVertexArray(__vao);
        for(unsigned int i = 0; i < renderInfos.size(); ++i)
        {
            RenderInfo *ri = renderInfos[i];

            switch(ri->type)
            {
                case TYPE_VERTEXBUF:
                {
                    GLuint vertexbuffer;
                    glGenBuffers(1, &vertexbuffer);
                    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(ri->data), ri->data, GL_STATIC_DRAW);
                    ri->id = new GLuint(vertexbuffer);

                    std::cout << "Vertexbuffer with ID #" << ri->id << " and size " << sizeof(ri->data) << std::endl;

                    break;
                }

                case TYPE_ATTRIBPOINTER:
                {
                    std::cout << "Attribpointer with location " << ri->location << ", size " << ri->size << " and buffer ID #" << ri->id << std::endl;

                    glEnableVertexAttribArray(ri->location);
                    glBindBuffer(GL_ARRAY_BUFFER, *(ri->id));
                    glVertexAttribPointer(ri->location, ri->size, ri->datatype, ri->normalized, ri->stride, (void*) 0);

                    break;
                }

                case TYPE_TEXSAMPLER_UNIFORM:
                {
                    std::cout << "Texture sampler with texture ID #" << ri->id << " and uniform name \"" << ri->uniformName << "\"" << std::endl;

                    glActiveTexture(GL_TEXTURE0);
                    glBindTexture(GL_TEXTURE_2D, *(ri->id));
                    glUniform1i(glGetUniformLocation(ri->shader->getID(), ri->uniformName), 0);

                    break;
                }

                case TYPE_SHADERS:
                {
                    std::cout << "Using shaders with ID #" << ri->shader->getID() << std::endl;

                    glUseProgram(ri->shader->getID());

                    break;
                }

                default:
                    break;
            }
        }
    glBindVertexArray(0);
}
*/

RenderObject::RenderObject()
{
    glGenVertexArrays(1, &__vao);
}

void RenderObject::constructVAO()
{
    glBindVertexArray(__vao);
        mesh->constructVAO(__vao, false);
        shader->bind();
        tex->push(1, glGetUniformLocation(shader->getID(), "tex_sampler"));
    glBindVertexArray(0);
}

unsigned int RenderQueue::render()
{
    unsigned int s = _q.size();

    for(unsigned int i = 0; i < _q.size(); ++i)
    {
        glBindVertexArray(_q[i]->__vao);
        glDrawArrays(GL_TRIANGLES, _q[i]->bufferStart, _q[i]->length);
    }

    return s;
}
