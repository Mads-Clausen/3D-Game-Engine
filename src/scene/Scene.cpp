/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

#include "scene/Scene.hpp"

void Scene::render()
{
    for(unsigned int i = 0; i < _objects.size(); ++i)
    {
        _objects[i]->render();
    }
}

void Scene::update()
{
    for(unsigned int i = 0; i < _objects.size(); ++i)
    {
        _objects[i]->update();
    }
}
