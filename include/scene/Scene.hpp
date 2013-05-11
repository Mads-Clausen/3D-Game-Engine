#ifndef SCENE_INCLUDED
#define SCENE_INCLUDED

#include <vector>

#include "scene/SceneObject.hpp"

class Scene
{
    private:
        std::vector<SceneObject*> _objects;

    public:
        Scene() {}

        virtual void update();
        virtual void render();
};

#endif // SCENE_INCLUDED
