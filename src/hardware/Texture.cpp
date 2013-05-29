/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

#include "hardware/Texture.hpp"

Texture::Texture(std::vector<GLfloat> c)
{
    _uvCoords = c;
    updateBuffer();

    _tex = 0;
}

Texture::Texture(GLfloat *c, unsigned int n)
{
    for(unsigned int i = 0; i < n; ++i)
    {
        _uvCoords.push_back(c[i]);
    }

    updateBuffer();
    _tex = 0;
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

void Texture::updateBuffer()
{
    glDeleteBuffers(1, &_buf);
    glGenBuffers(1, &_buf);
    glBindBuffer(GL_ARRAY_BUFFER, _buf);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _uvCoords.size(), &(_uvCoords[0]), GL_STATIC_DRAW);
}

bool Texture::load(const char *path)
{
    if(_tex == 0)
        _tex = SOIL_load_OGL_texture(path, 0, SOIL_CREATE_NEW_ID,   SOIL_FLAG_TEXTURE_REPEATS |
                                                                    SOIL_FLAG_INVERT_Y |
                                                                    SOIL_FLAG_COMPRESS_TO_DXT |
                                                                    SOIL_FLAG_NTSC_SAFE_RGB);
    else
        _tex = SOIL_load_OGL_texture(path, 0, _tex, SOIL_FLAG_TEXTURE_REPEATS |
                                                    SOIL_FLAG_INVERT_Y |
                                                    SOIL_FLAG_COMPRESS_TO_DXT |
                                                    SOIL_FLAG_NTSC_SAFE_RGB);

    if(_tex == 0)
    {
        std::cerr << "Unable to load image: " << SOIL_last_result() << std::endl;
        return false;
    }

    return true;
}

void Texture::push(GLuint loc, GLuint uniform_loc)
{
    __last_loc = loc;
    glBindBuffer(GL_ARRAY_BUFFER, _buf);
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 0, (void*) 0);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _tex);
    glUniform1i(uniform_loc, 0);

    std::cout << "\nglBindBuffer(GL_ARRAY_BUFFER, " << _buf << ");\nglEnableVertexAttribArray(" << loc << ");\nglVertexAttribPointer(" << loc << ", 2, GL_FLOAT, GL_FALSE, 0, (void*) 0);\nglActiveTexture(GL_TEXTURE0);\nglBindTexture(GL_TEXTURE_2D, " << _tex << ");\nglUniform1i(" << uniform_loc << ", 0);\n" << std::endl;
}

void Texture::pop()
{
    glDisableVertexAttribArray(__last_loc);
}
