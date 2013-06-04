#include "hardware/Mesh.hpp"

Mesh::Mesh() { _vertbuf = 0; }

Mesh::Mesh(GLfloat *vert, unsigned int n)
{
    for(unsigned int i = 0; i < n * 3; ++i)
        _vert.push_back(vert[i]);

    _vertbuf = 0;
}

Mesh::Mesh(std::vector<GLfloat> &vert)
{
    for(unsigned int i = 0; i < vert.size(); ++i)
        _vert.push_back(vert[i]);

    _vertbuf = 0;
}

void Mesh::constructVAO(GLuint &id, bool createNew)
{
    // std::cout << "Constructing VAO with ID #" << id << std::endl;

    if(createNew)
    {
        glDeleteVertexArrays(1, &id);
        glGenVertexArrays(1, &id);
    }

    glBindVertexArray(id);
        if(_vertbuf == 0)
            glGenBuffers(1, &_vertbuf);

        glBindBuffer(GL_ARRAY_BUFFER, _vertbuf);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _vert.size(), &_vert[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
}
