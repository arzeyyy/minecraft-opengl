#ifndef CUBE_H
#define CUBE_H

#include "../Mesh.h"

class Cube
{
public:
    std::vector<GLuint> indices = {
        0,1,2,3,
        4,7,6,5,
        0,4,5,1,
        1,5,6,2,
        2,6,7,3,
        4,0,3,7,
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
        // Position                         // Color                            // TexCoords                // Normals
        {glm::vec3(-0.5f, -0.5f, -0.5f),     glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(-1.0f, 0.0f, 0.0f)},
        {glm::vec3(0.5f, -0.5f, -0.5f),      glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(1.0f, 0.0f, 0.0f)},
        {glm::vec3(0.5f, 0.5f, -0.5f),       glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(1.0f, 0.0f, 0.0f)},
        {glm::vec3(-0.5f, 0.5f, -0.5f),      glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(-1.0f, 0.0f, 0.0f)},
        {glm::vec3(-0.5f, -0.5f, 0.5f),      glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 0.0f),      glm::vec3(-1.0f, 0.0f, 0.0f)},
        {glm::vec3(0.5f, -0.5f, 0.5f),       glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 0.0f),      glm::vec3(1.0f, 0.0f, 0.0f)},
        {glm::vec3(0.5f, 0.5f, 0.5f),        glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(1.0f, 1.0f),      glm::vec3(1.0f, 0.0f, 0.0f)},
        {glm::vec3(-0.5f, 0.5f, 0.5f),       glm::vec3(0.0f, 0.0f, 0.0f),        glm::vec2(0.0f, 1.0f),      glm::vec3(-1.0f, 0.0f, 0.0f)}
    };

    Cube() {
    }

private:

    //glm::vec3 pos;
    //glm::vec3 size;
};
#endif // !CUBE_H