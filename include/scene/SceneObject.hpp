/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://www.ckef-worx.com
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

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
