/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/


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

        void addObject(SceneObject *obj)
        {
            _objects.push_back(obj);
        }
};

#endif // SCENE_INCLUDED
