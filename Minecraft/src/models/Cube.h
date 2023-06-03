#ifndef CUBE_H
#define CUBE_H

#include "../Mesh.h"

class Cube
{
public:
    std::vector<GLuint> indices = {
        0, 1, 2,
        0, 2, 3,

        7, 6, 1,
        7, 1, 0,

        4, 5, 6,
        4, 6, 7,

        3, 2, 5,
        3, 5, 4
    };

    std::vector<Vertex> vertices = {
        // Position                         // Color                            // TexCoords                // Normals
        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},

        {glm::vec3(-0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},

        {glm::vec3(-0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},

        {glm::vec3(0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},

        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},

        {glm::vec3(-0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f,  0.5f,  0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f,  0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(0.0f, 0.0f, 1.0f)},
    };

    std::vector<Vertex> vertices1 = {
        
        //Position								//Color							//Texcoords					//Normals
        {glm::vec3(-0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f)},
        {glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f)},
        {glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f)},
        {glm::vec3(0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f)},
        
        {glm::vec3(0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)},
        {glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f)},
        {glm::vec3(-0.5f, -0.5f, -0.5f),		glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f)},
        {glm::vec3(-0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)}
    };

    Cube() {
    }

private:

    //glm::vec3 pos;
    //glm::vec3 size;
};
#endif // !CUBE_H