#include "VBO.h"

void Engine::VBO::create()
{
    glGenBuffers(1, &VBO);
}


void Engine::VBO::bind(GLint type, void *data, size_t size)
{
    glBindBuffer(type, VBO); //select buffer
    glBufferData(type, size, data, GL_STATIC_DRAW);  //sends data to vidmem


    //// position attribute
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    //glEnableVertexAttribArray(0);
    //// color attribute
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);
    //// texture coord attribute
    //glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    //glEnableVertexAttribArray(2);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    //glEnableVertexAttribArray(2);



}

void Engine::VBO::unbind(GLint type)
{
    glBindBuffer(type, 0);
}

void Engine::VBO::destroy()
{
    glDeleteBuffers(1, &VBO);
}

