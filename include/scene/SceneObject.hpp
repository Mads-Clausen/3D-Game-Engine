#ifndef SCENEOBJECT_INCLUDED
#define SCENEOBJECT_INCLUDED

#include "math/mat3.hpp"

class Scene;

class SceneObject
{
    private:
        mat3f _space;
        Scene *_parent;

    public:
        SceneObject(Scene *p) : _parent(p) {}

        virtual void update();
        virtual void render();
};

#endif // SCENEOBJECT_INCLUDED
