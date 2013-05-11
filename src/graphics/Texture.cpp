/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

#include "graphics/Texture.hpp"

Texture::Texture(std::vector<GLfloat> c)
{
    _uvCoords = c;
}

Texture::Texture(GLfloat *c, unsigned int n)
{
    for(unsigned int i = 0; i < n; ++i)
    {
        _uvCoords.push_back(c[i]);
    }
}

void Texture::addUVCoordinate(GLfloat x, GLfloat y)
{
    _uvCoords.push_back(x);
    _uvCoords.push_back(y);
}

void Texture::addUVCoordinate(vec2<GLfloat> v)
{
    _uvCoords.push_back(v.x);
    _uvCoords.push_back(v.y);
}
