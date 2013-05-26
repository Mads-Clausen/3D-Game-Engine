#ifndef RENDERQUEUE_INCLUDED
#define RENDERQUEUE_INCLUDED

#include <vector>

#include <GL/glew.h>

struct RenderObject
{
    unsigned int bufferStart, length;
    GLuint vao;
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
