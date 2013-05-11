/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

/*******************************************************
 * @file Contains the definition of the Scene class.
 *
 * @author Mads Clausen
 *******************************************************/

#ifndef SCENE_INCLUDED
#define SCENE_INCLUDED

#include <vector>

#include "scene/SceneObject.hpp"

class Scene
{
    private:
        std::vector<SceneObject*> _objects;

    public:
        /**************************
         * Default constructor.
         **************************/
        Scene() {}

        /****************************
         * Updates all children.
         ****************************/
        virtual void update();


        /*********************************************
         * Calls all children's render functions.
         *********************************************/
        virtual void render();

        /***********************************************************
         * Adds a SceneObject to the scene.
         *
         * @param obj The object to be added. Cannot be deleted.
         ***********************************************************/
        void addObject(SceneObject *obj)
        {
            _objects.push_back(obj);
        }
};

#endif // SCENE_INCLUDED
