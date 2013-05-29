/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

/****************************************************
 * @file Contains definition of the Mesh class.
 * @author Mads Clausen
 ****************************************************/

#ifndef MESH_INCLUDED
#define MESH_INCLUDED

#include <vector>
#include <iostream>

#include <GL/glew.h>

class Mesh
{
    private:
        GLuint _vertbuf;

        std::vector<GLfloat> _vert;

    public:
        /***************************
         * Default constructor.
         ***************************/
        Mesh();


        /*************************************
         * Constructor.
         *
         * @param vert The mesh' vertices.
         * @param n The amount of vertices.
         *************************************/
        Mesh(GLfloat *vert, unsigned int n);


        /*************************************
         * Constructor.
         *
         * @param vert The mesh' vertices.
         *************************************/
        Mesh(std::vector<GLfloat> &vert);


        /****************
         * Destructor.
         ****************/
        virtual ~Mesh() {};


        /***************************************
         * Constructs a vertex array object.
         *
         * @param id The ID.
         * @param createNew Create a new ID?
         ***************************************/
        void constructVAO(GLuint &id, bool createNew = false);
};

#endif // MESH_INCLUDED
