#include "graphics/RenderQueue.hpp"

unsigned int RenderQueue::render()
{
    unsigned int s = _q.size();

    for(unsigned int i = 0; i < _q.size();)
    {
        glBindVertexArray(_q[i]->vao);
        glDrawArrays(GL_TRIANGLES, _q[i]->bufferStart, _q[i]->length);
        _q.erase(_q.begin() + i);
    }

    return s;
}
