/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

/**
 * @file Contains the definition of the SceneObject class.
 *
 * @author Mads Clausen
 */


#ifndef SCENEOBJECT_INCLUDED
#define SCENEOBJECT_INCLUDED

#include "math/mat3.hpp"

class Scene;

/*****************************************************************
 * A dynamic object which can be added to any Scene instance.
 *****************************************************************/
class SceneObject
{
    private:
        math::mat3f _space;
        Scene *_parent;

    public:
        /*****************
         * Constructor.
         *****************/
        SceneObject(Scene *p) : _parent(p) {}

        /************************
         * Updates everything.
         ************************/
        virtual void update();

        /**********************************************
         * Pushes needed stuff onto the renderqueue.
         **********************************************/
        virtual void render();
};

#endif // SCENEOBJECT_INCLUDED
